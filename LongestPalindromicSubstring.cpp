#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
	string longestPalindrome(string s)
	{
		string t="$";
		for(int i=0;i<s.size();i++)
			t+='#',t+=s[i];
		t+='#';
		get(t);
		int ans=0,pos;
		string str="";
		for(int i=1;i<t.size();i++)
			if(p[i]>ans)
			{
				ans=p[i];
				pos=i;
			}
		for(int i=pos-ans+1;i<pos+ans;i++)
			if(t[i]!='#') str+=t[i];
		return str;
	}
	int p[2010];
	void get(string str)
	{
		int mx=0,id;
		for(int i=1;i<str.size();i++)
		{
			if(mx>i) p[i]=min(p[2*id-i],mx-i);
			else p[i]=1;
			for(;str[i+p[i]]==str[i-p[i]];p[i]++)
				;
			if(p[i]+i>mx)
			{
				mx=p[i]+i;
				id=i;
			}
		}
	}
};
int main()
{
	string str="abac";
	Solution s;
	cout<<s.longestPalindrome(str)<<endl;
	return 0;
}
