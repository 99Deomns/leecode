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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* DummyHead=new ListNode(0);
		DummyHead->next = head;
		ListNode* fast, * slow;
		fast = DummyHead;
		slow = DummyHead;
		while (n-- && fast->next) {
			fast = fast->next;
		}
		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
//		slow->next = slow->next->next;
		ListNode* tmp = slow->next;
		slow->next = tmp->next;
		delete tmp;

		return DummyHead->next;
	}
};

int main() {
	ListNode* L = new ListNode();
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	L->next = l1;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = nullptr;
	ListNode* p = L->next;
	while (p != NULL) {
		cout << p->val << " " ;
		p = p->next;
	}
	cout << endl;

	Solution s;
	p = s.removeNthFromEnd(L->next,1);
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
    return 0;
}