require 'thread'
require 'time'

class InMemoryScheduler
  def initialize(worker_threads: 5)
    @task_queue = Queue.new
    @worker_threads = worker_threads
    @workers = []
    @mutex = Mutex.new
    @condition_variable = ConditionVariable.new
    start_workers
  end

  def schedule(task, time)
    @mutex.synchronize do
      @task_queue << { task: task, time: time }
      @condition_variable.signal
    end
  end

  def schedule_at_fixed_interval(task, interval)
    @mutex.synchronize do
      @task_queue << { task: task, interval: interval, last_execution_time: Time.now }
      @condition_variable.signal
    end
  end

  private

  def start_workers
    @worker_threads.times do
      @workers << Thread.new do
        loop do
          task_info = @mutex.synchronize { @task_queue.pop }
          execute_task(task_info)
        end
      end
    end
  end

  def execute_task(task_info)
    if task_info[:time]
      sleep_time = task_info[:time] - Time.now
      sleep(sleep_time) if sleep_time.positive?
    elsif task_info[:interval]
      sleep_time = task_info[:last_execution_time] + task_info[:interval] - Time.now
      sleep(sleep_time) if sleep_time.positive?
      task_info[:last_execution_time] = Time.now
    end
    task_info[:task].call
  rescue StandardError => e
    puts "Error executing task: #{e.message}"
  end
end

# Example usage
scheduler = InMemoryScheduler.new(worker_threads: 2)

# Submit a task to be executed at a specific time
scheduler.schedule(-> { puts "Task 1 executed at #{Time.now}" }, Time.now + 10)

# Submit a task to be executed every 5 seconds
scheduler.schedule_at_fixed_interval(-> { puts "Task 2 executed at #{Time.now}" }, 5)

# Sleep for a while to allow tasks to execute
sleep(30)
