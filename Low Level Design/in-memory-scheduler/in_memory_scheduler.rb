require 'thread'

# we could also pas queue_name and have separate queues as per requirement
# we could have different scheduler threads for one time and interval one
# we could separately store 
class JobScheduler
    def initialize(num_of_threads = 5)
        @job_queue = Queue.new # thread safe queue
        @mutex = Mutex.new # to ensure two threads do not pop at same time
        @num_of_threads = num_of_threads
        @condition = ConditionVariable.new
        @worker_threads = []
        @scheduler_thread = Thread.new { schedule_jobs }
        @all_jobs = []
    end

    def start_workers
        @worker_threads = []
        @num_of_threads.times do
            @worker_threads << Thread.new { worker_execute }
        end
    end

    def stop_workers
        @worker_threads.each(&:exit)
        @scheduler_thread.exit()
    end

    def schedule_at(task, time)
        @mutex.synchronize do
            @all_jobs << { task: task, time: time }
        end
    end

    def schedule_at_interval(task, interval)
        @mutex.synchronize do
            @all_jobs << { task: task, interval: interval, last_executed_at: nil }
        end
    end

    private

    def schedule_jobs
        loop do
            @all_jobs.each do |job|
                if job[:time]
                    if (job[:time] - Time.now <= 0)
                        @mutex.synchronize do
                            @job_queue << job
                            @condition.signal
                        end
                        @all_jobs.delete(job)
                    end
                elsif job[:interval]
                    if !job[:last_executed_at] || (job[:last_executed_at] + job[:interval] <= Time.now)
                        @mutex.synchronize do
                            @job_queue << job
                            @condition.signal
                        end
                        job[:last_executed_at] = Time.now
                    end
                end
            end
            sleep(0.1)
        end
    end

    def worker_execute
        loop do
            job = nil
            @mutex.synchronize do
                @condition.wait(@mutex)
                job = @job_queue.pop
            end
            execute_task(job)
        end
    end

    def execute_task(job)
        job[:task].call
    end
end