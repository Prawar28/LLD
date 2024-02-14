require 'thread'

class JobScheduler
    def initialize(num_of_threads = 5)
        @job_queue = Queue.new # thread safe queue
        @mutex = Mutex.new # to ensure two threads do not pop at same time
        @num_of_threads = num_of_threads
        @interval_threads = []
        @condition = ConditionVariable.new
        @worker_threads = []
        @num_of_threads.times do
            @worker_threads << Thread.new { worker_execute }
        end
        @scheduler_thread = Thread.new { schedule_jobs }
        @all_jobs = []
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
                            @job_queue << { task: task, time: time }
                            @condition.signal
                        end
                        @all_jobs.delete(job)
                elsif job[:interval]
                    
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