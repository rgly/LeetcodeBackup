// Time : Beats 100%
// Memory : Beats 31.71%
class Solution {
public:
	// L0 Ln L1 Ln-1 L2
	void reorderList(ListNode* head) {
		assert(head);
		// get len
		int len = 0;
		auto* h = head;
		while (h) {
			++len;
			h = h->next;
		}
		// get target node at:
		//    x [x] x
		//    x [x] x x
		int lenhalf_before = (len%2) ? (len+1)/2 : len/2;
		h = head;
		for (int i=0; i<lenhalf_before-1; ++i) {
			h = h->next;
		}

		// break list
		//    x x | x
		//    x x | x x
		auto list2 = h->next;
		h->next = nullptr;
		if (!list2) return;

		// reverse list2
		h = list2;
		ListNode* lasth = nullptr;
		while (h) {
			auto nextn = h->next;
			h->next = lasth;
			lasth = h;
			h = nextn;
		}
		list2 = lasth;
		assert(list2);

		// merge 2 lists
		h = head;
		while (h) {
			auto NEXT = h->next;
			if (list2) {
				h->next = list2;
				auto NEXT2 = list2->next;
				list2->next = NEXT;
				list2 = NEXT2;
			}
			h = NEXT;
		}
	}
};
