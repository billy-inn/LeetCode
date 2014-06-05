#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int> > ans;
		sort(num.begin(),num.end());
		int len=num.size();
		for(int i=0;i<len;i++)
		{
			if(i>0 && num[i]==num[i-1]) continue;
			int f=i+1,r=len-1;
			while(f<r)
			{
				int sum=num[i]+num[f]+num[r];
				if(sum<0) f++;
				else if(sum>0) r--;
				else if(f>i+1 && num[f]==num[f-1]) f++;
				else if(r<len-1 && num[r]==num[r+1]) r--;
				else
				{
					ans.push_back(triple(num[i],num[f],num[r]));
					f++;r--;
				}
			}
		}
		return ans;
	}
	vector<int> triple(int a,int b,int c)
	{
		vector<int> t;
		t.push_back(a);
		t.push_back(b);
		t.push_back(c);
		sort(t.begin(),t.end());
		return t;
	}
};
int main()
{
	Solution s;
	vector<int> num;
	int a[]={0,0,0};
	for(int i=0;i<3;i++) num.push_back(a[i]);
	vector<vector<int> > ans=s.threeSum(num);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
	return 0;
}
