class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            // 如果鏈表為空或只有一個節點，直接返回
            if (!head || !head->next) {
                return head;
            }
            
            // 創建一個虛擬頭節點，方便處理
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* prev = dummy;
            
            // 當還有至少兩個節點可以交換時
            while (prev->next && prev->next->next) {
                // 定義要交換的兩個節點
                ListNode* first = prev->next;
                ListNode* second = first->next;
                
                // 進行交換
                first->next = second->next;
                second->next = first;
                prev->next = second;
                
                // 移動到下一對節點
                prev = first;
            }
            
            // 保存結果並清理虛擬節點
            ListNode* result = dummy->next;
            delete dummy;
            return result;
        }
    };