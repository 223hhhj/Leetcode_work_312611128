# Leetcode 239 - Sliding Window Maximum
# 312611128 謝佳鴻
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)  # 數組的長度
        if n == 0 or k == 0:  # 邊界檢查：如果數組空的或窗口大小為0
            return []
        
        result = []  # 存儲每個窗口的最大值
        
        # 外層迴圈：窗口從 0 滑到 n - k
        for i in range(n - k + 1):
            # 內層迴圈：找出當前窗口的最大值
            max_value = nums[i]  # 先假設窗口的第一個數是最大值
            for j in range(i, i + k):  # 檢查窗口內每個數
                if nums[j] > max_value:
                    max_value = nums[j]
            result.append(max_value)  # 把最大值加到結果
        
        return result

# 測試用例
nums = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3
solution = Solution()
print(solution.maxSlidingWindow(nums, k))  # 輸出: [3, 3, 5, 5, 6, 7]