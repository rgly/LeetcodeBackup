//Time : Beats 100%
//Memory : Beats 89%
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		int counter=0;
		auto* middle = head;
		while(head) {
			if (counter == 1) {
				middle = middle->next;
				counter = -1;
			}
			++counter;
			head = head->next;
		}
		return middle;
	}
};
