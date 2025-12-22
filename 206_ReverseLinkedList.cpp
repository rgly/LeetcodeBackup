// Time : Beats 100%
// Memory : Beats 90.02%
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head) return nullptr;
		ListNode* last = head;
		ListNode* cur = head->next;
		head->next = nullptr;
		while (cur) {
			auto next = cur->next;
			cur->next = last;
			last = cur;
			cur = next;
		}
		return last;
	}
};
