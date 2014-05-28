#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class Solution
{
public:
	bool isPalindrome(int x)
	{
		if(x<0) return false;
		string s="";
		while(x)
		{
			s+='0'+x%10;
			x/=10;
		}
		int len=s.size();
		for(int i=0;i<=len/2;i++)
			if(s[i]!=s[len-1-i])
				return false;
		return true;
	}
};
int main()
{
	return 0;
}
