#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> ans;
		dfs(digits,0,"",ans);
		return ans;
	}
	void dfs(string digits,int dep,string s,vector<string> &v)
	{
		if(dep==digits.size()) 
		{
			v.push_back(s);
			return;
		}
		switch (digits[dep])
		{
			case '2':
			{
				for(char c='a';c<='c';c++)
					dfs(digits,dep+1,s+c,v);
				break;
			}
			case '3':
			{
				for(char c='d';c<='f';c++)
					dfs(digits,dep+1,s+c,v);
				break;
			}
			case '4':
			{
				for(char c='g';c<='i';c++)
					dfs(digits,dep+1,s+c,v);
				break;
			}
			case '5':
			{
				for(char c='j';c<='l';c++)
					dfs(digits,dep+1,s+c,v);
				break;
			}
			case '6':
			{
				for(char c='m';c<='o';c++)
					dfs(digits,dep+1,s+c,v);
				break;
			}
			case '7':
			{
				for(char c='p';c<='s';c++)
					dfs(digits,dep+1,s+c,v);
				break;
			}
			case '8':
			{
				for(char c='t';c<='v';c++)
					dfs(digits,dep+1,s+c,v);
				break;
			}
			case '9':
			{
				for(char c='w';c<='z';c++)
					dfs(digits,dep+1,s+c,v);
				break;
			}
		}
	}
};
int main()
{
	Solution s;
	vector<string> ans=s.letterCombinations("23");
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
	return 0;
}
