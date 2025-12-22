class DList {
public:
	ListNode* head=nullptr;
	ListNode* tail=nullptr;
	int size=0;
	DList(){};
	DList(ListNode* a, ListNode* b): head(a), tail(b){};
	void append(ListNode* n) {
		if (!head) head = n;
		else tail->next = n;
		tail = n;
		++size;
	}
	void concat(DList& rhs) {
		if (rhs.empty()) return;
		if (!head) head = rhs.head;
		else tail->next = rhs.head;
		tail = rhs.tail;
		size += rhs.size;
	}
	bool empty() { return head==nullptr; }
	void finalize() {tail->next = nullptr;}
};

class Solution {
public:
	int AVG(ListNode* head) {
		assert(head);
		ListNode* cur = head;
		int sum=0;
		int cnt=0;
		while (cur) {
			sum += cur->val;
			++cnt;
			cur = cur->next;
		}
		return sum/cnt;
	}
	
	array<DList, 3> divide(ListNode* head, int avg) {
		DList mid, left, right;

		ListNode* cur = head;
		while (cur) {
			if (cur->val == avg) mid.append(cur);
			else if (cur->val < avg) left.append(cur);
			else right.append(cur);
			cur = cur->next;
		}
		if (!mid.empty()) mid.finalize();
		if (!left.empty()) left.finalize();
		if (!right.empty()) right.finalize();
		return {left, mid, right};
	}

	DList quicksort(ListNode* head) {
		if (head == nullptr) return DList();
		if (head->next== nullptr) return DList(head, head);
		const int avg = AVG(head);
		auto a = divide(head, avg);
		DList left = a[0];
		DList mid = a[1];
		DList right = a[2];
		if (left.empty() && right.empty()) return mid;

		if (left.size > 1) left = quicksort(left.head);
		if (right.size > 1) right = quicksort(right.head);
		left.concat(mid);
		left.concat(right);
		return left;
	}

	ListNode* sortList(ListNode* head) {
		return quicksort(head).head;
	}
};
