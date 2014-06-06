#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<vector<int> > fourSum(vector<int> &num,int target)
	{
		vector<vector<int> > ans;
		int len=num.size();
		sort(num.begin(),num.end());
		for(int i=0;i<len;i++)
		{
			if(i>0 && num[i]==num[i-1]) continue;
			for(int j=i+1;j<len;j++)
			{
				if(j>i+1 && num[j]==num[j-1]) continue;
				int f=j+1,r=len-1;
				while(f<r)
				{
					int sum=num[i]+num[j]+num[f]+num[r];
					if(sum>target) r--;
					else if(sum<target) f++;
					else if(r<len-1 && num[r]==num[r+1]) r--;
					else if(f>j+1 && num[f]==num[f-1]) f++;
					else
					{
						ans.push_back(quadruplet(num[i],num[j],num[f],num[r]));
						f++;r--;
					}
				}
			}
		}
		return ans;
	}
	vector<int> quadruplet(int a,int b,int c,int d)
	{
		vector<int> t;
		t.push_back(a);
		t.push_back(b);
		t.push_back(c);
		t.push_back(d);
		return t;
	}
};
int main()
{
	Solution s;
	int a[]={1,0,-1,0,2,-2};
	vector<int> v;
	for(int i=0;i<6;i++) v.push_back(a[i]);
	vector<vector<int> > ans=s.fourSum(v,0);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
	return 0;
}
