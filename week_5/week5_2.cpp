class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            if (nums.size() <= 1) {
                return nums;
            }
            
            // 創建臨時陣列用於合併
            vector<int> temp(nums.size());
            mergeSort(nums, 0, nums.size() - 1, temp);
            return nums;
        }
        
    private:
        void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
            if (left >= right) {
                return;
            }
            
            // 分割陣列
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid, temp);
            mergeSort(nums, mid + 1, right, temp);
            
            // 合併兩個有序子陣列
            merge(nums, left, mid, right, temp);
        }
        
        void merge(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
            // 將元素複製到臨時陣列
            for (int i = left; i <= right; i++) {
                temp[i] = nums[i];
            }
            
            int i = left;      // 左半部分的起點
            int j = mid + 1;   // 右半部分的起點
            int k = left;      // 合併後的當前位置
            
            // 合併兩個子陣列
            while (i <= mid && j <= right) {
                if (temp[i] <= temp[j]) {
                    nums[k++] = temp[i++];
                } else {
                    nums[k++] = temp[j++];
                }
            }
            
            // 處理剩餘的元素（如果有）
            while (i <= mid) {
                nums[k++] = temp[i++];
            }
            while (j <= right) {
                nums[k++] = temp[j++];
            }
        }
    };