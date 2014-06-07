#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
struct Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head,int n)
	{
		ListNode *tmp=head;
		int len=1;
		while(tmp->next!=NULL)
		{
			len++;
			tmp=tmp->next;
		}
		if(n==len) return head->next;
		int x=len-n-1,y=len-n+1;
		ListNode *t1=head,*t2=head;
		while(x--) t1=t1->next;
		if(y==len)
		{
			t1->next=NULL;
		}
		else
		{
			while(y--) t2=t2->next;
			t1->next=t2;
		}
		return head;
	}
};
int main()
{
	return 0;
}
