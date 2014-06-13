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
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		int k=lists.size();
		if(k==0) return NULL;
		return mergeSort(lists,0,k-1);
	}
	ListNode *mergeSort(vector<ListNode *> &lists,int L,int R)
	{
		if(L==R) return lists[L];
		int M=(L+R)/2;
		ListNode *lp=mergeSort(lists,L,M);
		ListNode *rp=mergeSort(lists,M+1,R);
		return merge2Lists(lp,rp);
	}
	ListNode *merge2Lists(ListNode *A,ListNode *B)
	{
		ListNode *cur=NULL,*head=NULL,*nxt;
		while(1)
		{
			if(A!=NULL && B!=NULL)
			{
				if(A->val>B->val) nxt=A;
				else nxt=B;
			}
			else if(A!=NULL) nxt=A;
			else if(B!=NULL) nxt=B;
			else nxt=NULL;
			if(nxt==NULL) break;
			else
			{
				if(cur==NULL)
				{
					cur=head=nxt;
					if(nxt==A) A=A->next;
					else B=B->next;
					continue;
				}
				cur->next=nxt;
				cur=cur->next;
				if(nxt==A) A=A->next;
				else B=B->next;
			}
		}
		return head;
	}
};
int main()
{
	return 0;
}
