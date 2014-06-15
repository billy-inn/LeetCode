#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution
{
public:
	ListNode *swapPairs(ListNode *head)
	{
		if(head==NULL) return head;
		ListNode *cur=head,*nxt=cur->next,*pre=NULL;
		while(nxt!=NULL)
		{
			if(pre!=NULL) pre->next=nxt;
			cur->next=nxt->next;
			nxt->next=cur;
			pre=cur;
			if(cur==head) head=nxt;
			cur=cur->next;
			if(cur==NULL) break;
			nxt=cur->next;
		}
		return head;
	}
};
int main()
{
	return 0;
}
