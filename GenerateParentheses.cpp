#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> ans;
		dfs(ans,"",2*n,0);
		return ans;
	}
	void dfs(vector<string> &v,string s,int dep,int flag)
	{
		if(flag<0) return;
		if(dep==0)
		{
			if(!flag) v.push_back(s);
			return;
		}
		dfs(v,s+'(',dep-1,flag+1);
		dfs(v,s+')',dep-1,flag-1);
	}
};
int main()
{
	Solution s;
	int n;
	while(cin>>n)
	{
		vector<string> ans=s.generateParenthesis(n);
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<endl;
	}
	return 0;
}
