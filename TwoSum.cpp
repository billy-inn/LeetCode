#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers,int target)
	{
		vector<int> ans;
		vector<pair<int,int> > v;
		int n=numbers.size();
		for(int i=0;i<n;i++) v.push_back(make_pair(numbers[i],i+1));
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++)
		{
			int tmp=target-v[i].first;
			int L=i+1,R=n-1,M;
			while(L<=R)
			{
				M=(L+R)>>1;
				if(tmp==v[M].first)
				{
					int a=v[i].second,b=v[M].second;
					ans.push_back(a>b?b:a);
					ans.push_back(a>b?a:b);
					return ans;
				}
				else if(tmp<v[M].first) R=M-1;
				else L=M+1;
			}
		}
		return ans; 
	}
};
int main()
{
	vector<int> v;
	v.push_back(-3);
	v.push_back(4);
	v.push_back(3);
	v.push_back(90);
	Solution s;
	vector<int> ans=s.twoSum(v,0);
	for(int i=0;i<2;i++) cout<<ans[i]<<endl;
	return 0;
}
