//Web导航，前后移动两个网页
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	stack<string> forward;
	stack<string> backward;
	string current;
	current = "***###.acm.org/";
	string order;
	cout << "current: " << current << endl;
	while (cin >> order && order != "QUIT") {
		if (order == "visit") {
			forward.push(current);
			cin >> current;
			cout << "current: " << current << endl;
		}
		if (order == "back" && !forward.empty()) {
			backward.push(current);
			current = forward.top();
			forward.pop();
			cout << "current: " << current << endl;
		}
		if (order == "forward" && !backward.empty()) {
			forward.push(current);
			current = backward.top();
			backward.pop();
			cout << "current: " << current << endl;
		}
	}
	return 0;
}