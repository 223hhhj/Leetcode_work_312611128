class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            // Sort tasks and workers so we can use binary search effectively
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
          
            int taskCount = tasks.size(), workerCount = workers.size();
            // Initialize binary search boundaries
            int left = 0, right = min(workerCount, taskCount);
          
            // Lambda function to check if 'x' is feasible
            auto canAssignTasks = [&](int x) {
                int remainingPills = pills;
                deque<int> availableTasks;
                int taskIndex = 0;
                
                // Process the strongest x workers (from workerCount-x to workerCount-1)
                for (int workerIndex = workerCount - x; workerIndex < workerCount; ++workerIndex) {
                    // Add all tasks that this worker can potentially do (with or without pills)
                    while (taskIndex < x && tasks[taskIndex] <= workers[workerIndex] + strength) {
                        availableTasks.push_back(tasks[taskIndex++]);
                    }
                    
                    // If no tasks can be assigned to the current worker, return false
                    if (availableTasks.empty()) {
                        return false;
                    }
                    
                    // Task can be done without a pill (choose the easiest task)
                    if (availableTasks.front() <= workers[workerIndex]) {
                        availableTasks.pop_front();
                    } 
                    // Task requires a pill and we have pills left (choose the hardest task)
                    else if (remainingPills > 0) {
                        --remainingPills;
                        availableTasks.pop_back();
                    } 
                    // No pills left and the worker can't do any tasks
                    else {
                        return false;
                    }
                }
                return true;
            };
    
            // Binary search to find the maximum number of tasks that can be assigned
            while (left < right) {
                // Take the upper half of the remaining range
                int mid = (left + right + 1) / 2;
                // Check if 'mid' number of tasks can be successfully assigned
                if (canAssignTasks(mid)) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
    
            // 'left' will contain the maximum number of tasks that can be assigned
            return left;
        }
    };