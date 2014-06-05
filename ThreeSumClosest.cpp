#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class Solution
{
public:
	int threeSumClosest(vector<int> &num,int target)
	{
		int mind=0x3fffffff;
		int ans;
		sort(num.begin(),num.end());
		int len=num.size();
		for(int i=0;i<len;i++)
		{
			int f=i+1,r=len-1;
			while(f<r)
			{
				int sum=num[i]+num[f]+num[r];
				if(mind>abs(sum-target))
				{
					mind=abs(sum-target);
					ans=sum;
				}
				if(sum>target) r--;
				else f++;
			}
		}
		return ans;
	}
};
int main()
{
	Solution s;
	int a[]={-1,2,1,4};
	vector<int> num;
	for(int i=0;i<4;i++) num.push_back(a[i]);
	cout<<s.threeSumClosest(num,1)<<endl;
	return 0;
}
