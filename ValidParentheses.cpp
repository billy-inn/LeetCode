#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
class Solution
{
public:
	bool isValid(string s)
	{
		return dfs(s,0,s.size()-1);
	}
	bool dfs(string &s,int L,int R)
	{
		if(R<L) return true;
		switch (s[L])
		{
			case '(':
			{
				bool ans=false;
				for(int i=R;i>L;i--)
					if(s[i]==')')
						ans|=dfs(s,L+1,i-1)&dfs(s,i+1,R);
				return ans;
			}
			case '[':
			{
				bool ans=false;
				for(int i=R;i>L;i--)
					if(s[i]==']')
						ans|=dfs(s,L+1,i-1)&dfs(s,i+1,R);
				return ans;
			}
			case '{':
			{
				bool ans=false;
				for(int i=R;i>L;i--)
					if(s[i]=='}')
						ans|=dfs(s,L+1,i-1)&dfs(s,i+1,R);
				return ans;
			}
			default: return false;
		}
		return false;
	}
};
int main()
{
	Solution s;
	string str;
	while(cin>>str) cout<<s.isValid(str)<<endl;
	return 0;
}
