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
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead;
		ListNode* tmp1, * tmp2;
		while (cur->next && cur->next->next) {
			tmp1 = cur->next;
			tmp2 = tmp1->next;
			cur->next = tmp2;
			tmp1->next = tmp2->next;
			tmp2->next = tmp1;
			cur = tmp1;
		}
		ListNode* res = dummyHead->next;
		delete dummyHead;
		return res;
	}
};

int main() {
	ListNode* L = new ListNode();
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	L->next = l1;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = nullptr;
	ListNode* p = L->next;
	while (p != NULL) {
		cout << p->val << " " ;
		p = p->next;
	}
	cout << endl;

	Solution s;
	p = s.swapPairs(L->next);
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
    return 0;
}