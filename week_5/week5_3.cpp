class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.empty()) {
                return nullptr;
            }
            return mergeKListsHelper(lists, 0, lists.size() - 1);
        }
        
    private:
        ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
            // 基本情況：只有一個鏈表
            if (start == end) {
                return lists[start];
            }
            // 空範圍，返回 nullptr
            if (start > end) {
                return nullptr;
            }
            
            // 分割成兩半並遞迴處理
            int mid = start + (end - start) / 2;
            ListNode* left = mergeKListsHelper(lists, start, mid);
            ListNode* right = mergeKListsHelper(lists, mid + 1, end);
            
            // 合併左右兩部分
            return mergeTwoLists(left, right);
        }
        
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            // 如果任一鏈表為空，返回另一個
            if (!l1) return l2;
            if (!l2) return l1;
            
            // 比較節點值，遞迴合併
            if (l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            } else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    };