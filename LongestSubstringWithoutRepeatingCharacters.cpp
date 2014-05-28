#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define SIZE 256
class Solution 
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int vis[SIZE];
		int len=s.size(),ans=0,pre=-1;
		memset(vis,-1,sizeof(vis));
		for(int i=0;i<len;i++)
		{
			char ch=s[i];
			if(vis[ch]!=-1) pre=max(pre,vis[ch]);
			vis[ch]=i;
			if(i-pre>ans) ans=i-pre;
		}
		return ans;
	}
};
int main()
{
	Solution s;
	cout<<s.lengthOfLongestSubstring("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac")<<endl;
	return 0;
}
