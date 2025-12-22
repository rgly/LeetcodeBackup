// Time: Beat 100%
// Memory: Beat 28.20%
class MyQueue {
public:
	stack<int> in_stack, out_stack;
	MyQueue() {
	}
	void push(int x) {
		in_stack.push(x);
	}
	void flush() {
		assert(out_stack.empty());
		while(!in_stack.empty()) {
			int v = in_stack.top();
			in_stack.pop();
			out_stack.push(v);
		}
	}
	int pop() {
		if (out_stack.empty()) {
			flush();
		}
		int ret = out_stack.top();
		out_stack.pop();
		return ret;
	}
	int peek() {
		if (out_stack.empty()) {
			flush();
		}
		return out_stack.top();
	}
	bool empty() {
		return in_stack.empty() & out_stack.empty();
	}
