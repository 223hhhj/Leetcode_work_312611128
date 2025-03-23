class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            // 如果鏈表為空或 k = 1（不需要反轉），直接返回
            if (!head || k == 1) {
                return head;
            }
            
            // 創建一個虛擬頭節點
            ListNode dummy(0);
            dummy.next = head;
            
            // 記錄當前組的前一個節點
            ListNode* prev = &dummy;
            // 當前處理的節點
            ListNode* curr = head;
            
            // 計算鏈表長度
            int count = 0;
            while (curr) {
                count++;
                curr = curr->next;
            }
            
            // 重置 curr 指針
            curr = head;
            
            // 處理每一組 k 個節點
            while (count >= k) {
                // 記錄當前組的第一個節點
                ListNode* groupStart = curr;
                // 記錄下一組的第一個節點
                ListNode* nextGroupStart = curr;
                
                // 反轉 k 個節點
                ListNode* prev_ptr = nullptr;
                for (int i = 0; i < k; i++) {
                    ListNode* next_temp = curr->next;
                    curr->next = prev_ptr;
                    prev_ptr = curr;
                    curr = next_temp;
                }
                
                // 此時 prev_ptr 指向反轉後當前組的第一個節點（原來的最後一個）
                // curr 指向下一組的第一個節點
                
                // 連接前一組和當前組
                prev->next = prev_ptr;
                
                // 連接當前組和下一組
                groupStart->next = curr;
                
                // 更新 prev 為下一組的前一個節點
                prev = groupStart;
                
                // 減少計數
                count -= k;
            }
            
            return dummy.next;
        }
    };