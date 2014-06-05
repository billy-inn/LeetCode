#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define inf 0x3fffffff
class Solution
{
public:
	vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int> > ans;
		vector<int> u,v;
		int len=num.size(),zero=0;
		for(int i=0;i<len;i++)
			if(num[i]==0) zero++;
			else if(num[i]>0) u.push_back(num[i]);
			else v.push_back(-num[i]);
		sort(u.begin(),u.end());
		sort(v.begin(),v.end());
		int lu=u.size(),lv=v.size();
		if(zero)
		{
			for(int i=0;i<lu;i++)
			{
				if(i>0 && u[i]==u[i-1]) continue;
				if(binarysearch(u[i],v)!=inf) ans.push_back(triple(-u[i],0,u[i]));
			}
			if(zero>=3) ans.push_back(triple(0,0,0));
		}
		int pv=0;
		for(int i=0;i<lu;i++)
		{
			if(i>0 && u[i]==u[i-1]) continue;
			while(pv<lv && 2*u[i]>v[pv]) pv++;
			for(int j=pv;j<lv;j++)
			{
				if(j>0 && v[j]==v[j-1]) continue;
				if(v[j]==2*u[i])
				{
					if(i<lu-1 && u[i]==u[i+1]) 
						ans.push_back(triple(-v[j],u[i],u[i]));
					continue;
				}
				if(binarysearch(v[j]-u[i],u)!=inf)
					ans.push_back(triple(-v[j],u[i],v[j]-u[i]));
			}
		}
		int pu=0;
		for(int i=0;i<lv;i++)
		{
			if(i>0 && v[i]==v[i-1]) continue;
			while(pu<lu && 2*v[i]>u[pu]) pu++;
			for(int j=pu;j<lu;j++)
			{
				if(j>0 && u[j]==u[j-1]) continue;
				if(u[j]==2*v[i])
				{
					if(i<lv-1 && v[i]==v[i+1])
						ans.push_back(triple(-v[i],-v[i],u[j]));
					continue;
				}
				if(binarysearch(u[j]-v[i],v)!=inf)
					ans.push_back(triple(v[i]-u[j],-v[i],u[j]));
			}
		}
		return ans;
	}
	int binarysearch(int val,vector<int> &v)
	{
		int L=0,R=v.size()-1;
		while(L<=R)
		{
			int M=(L+R)/2;
			if(v[M]==val) return M;
			if(v[M]<val) L=M+1;
			else R=M-1;
		}
		return inf;
	}
	vector<int> triple(int a,int b,int c)
	{
		vector<int> t;
		t.push_back(a);
		t.push_back(b);
		t.push_back(c);
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
