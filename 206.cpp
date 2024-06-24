#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;

		while (cur != nullptr) {
			ListNode* tmp = cur->next;
			cur->next = pre;

			pre = cur;
			cur = tmp;
		}
		return pre;
    }
};

int main() {
	ListNode* L = new ListNode();
	ListNode* l1 = new ListNode(2);
	ListNode* l2 = new ListNode(3);
	ListNode* l3 = new ListNode(4);
	ListNode* l4 = new ListNode(5);
	L->next = l1;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = nullptr;
	ListNode* p = L->next;
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
	Solution s;
	p = s.reverseList(L->next);
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
    return 0;
}