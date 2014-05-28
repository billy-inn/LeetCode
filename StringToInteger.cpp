#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
class Solution
{
public:
	int atoi(const char* str)
	{
		long long ans=0;
		int len=strlen(str);
		int sta=0;
		while(str[sta]==' ' && sta<len) sta++;
		if(str[sta]=='-' || str[sta]=='+')
		{
			int i=sta+1;
			while(i<len && isdigit(str[i]) && ans<=INT_MAX)
			{
				ans=ans*10+str[i]-'0';
				i++;
			}
			if(ans>INT_MAX) return str[sta]=='-'?INT_MIN:INT_MAX;
			return str[sta]=='-'?-ans:ans;
		}
		else
		{
			int i=sta;
			while(i<len && isdigit(str[i]) && ans<=INT_MAX)
			{
				ans=ans*10+str[i]-'0';
				i++;
			}
			if(ans>INT_MAX) return INT_MAX;
			return ans;
		}
	}
};
int main()
{
	Solution s;
	char str[100];
	while(scanf("%s",str)!=EOF) cout<<s.atoi(str)<<endl;
	return 0;
}
