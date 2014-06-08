#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    double findMedianSortedArrays(int A[],int m,int B[],int n) 
    {
        int total=m+n;
		if(total%2==0)
			return (double)(findKthSortedArrays(A,m,B,n,total/2)+
				findKthSortedArrays(A,m,B,n,total/2+1))/2;
		else 
			return (double)findKthSortedArrays(A,m,B,n,(total+1)/2);
    }
    int findKthSortedArrays(int A[],int m,int B[],int n,int k)
	{
		if(m>n) return findKthSortedArrays(B,n,A,m,k);
		if(m==0) return B[k-1];
		if(k==1) return min(A[0],B[0]);
		int pa=min(k/2,m),pb=k-pa;
		if(A[pa-1]>B[pb-1])
			return findKthSortedArrays(A,m,B+pb,n-pb,k-pb);
		else if(A[pa-1]<B[pb-1]) 
			return findKthSortedArrays(A+pa,m-pa,B,n,k-pa);
		else return A[pa-1];
	}
};
int main()
{
	int A[]={},B[]={1};
	Solution s;
	cout<<s.findMedianSortedArrays(A,0,B,1)<<endl;
	return 0;
}
