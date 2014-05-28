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
class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1,ListNode *l2)
	{
		int r=0,s;
		ListNode *p1=l1,*p2=l2,*q1,*q2;
		ListNode *t1=new ListNode(0);
		ListNode *t2=new ListNode(0);
		while(l1->next!=NULL) l1=l1->next;
		while(l2->next!=NULL) l2=l2->next;
		l1->next=t1;
		l2->next=t2;
		q1=l1,q2=l2;
		l1=p1,l2=p2;
		do
		{
			s=l1->val+l2->val+r;
			l1->val=l2->val=s%10;
			r=s/10;
			l1=l1->next;
			l2=l2->next;
		} while(l1->next!=NULL && l2->next!=NULL);
		if(l1->next==NULL)
		{
			while(l2->next!=NULL)
			{
				s=l2->val+r;
				l2->val=s%10;
				r=s/10;
				l2=l2->next;
			}
			if(r==0) q2->next=NULL;
			else l2->val=r;
			return p2;
		}
		else
		{
			while(l1->next!=NULL)
			{
				s=l1->val+r;
				l1->val=s%10;
				r=s/10;
				l1=l1->next;
			}
			if(r==0) q1->next=NULL;
			else l1->val=r;
			return p1;
		}
		return NULL;
	}
};
int main()
{
	ListNode a(5),b(5);
	Solution s;
	ListNode *c=s.addTwoNumbers(&a,&b);
	while(c!=NULL)
	{
		cout<<c->val<<endl;
		c=c->next;
	}
	return 0;
}
