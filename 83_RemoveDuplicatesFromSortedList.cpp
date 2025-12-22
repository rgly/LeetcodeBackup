class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return nullptr;
		ListNode* lastnode = head;
		auto* h = head->next;
		while (h) {
			if (h->val == lastnode->val) {
				lastnode->next = h->next;
			} else {
				lastnode = h;
			}
			h = h->next;
		}
		return head;
	}
};
