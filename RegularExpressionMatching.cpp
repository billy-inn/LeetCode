#include <iostream>
#include <cstdio>
using namespace std;
class Solution
{
public:
	bool isMatch(const char *s,const char *p)
	{
		int lp=strlen(p),ls=strlen(s);
		int i,j;
		for(i=0,j=0;i<lp;i++,j++)
		{
			if(p[i+1]=='*')
			{
				if(isMatch(s+j,p+i+2)) return true;
				for(int k=j;k<ls;k++) 
					if(s[k]==p[i] || p[i]=='.')
					{
						if(isMatch(s+k+1,p+i+2))
							return true;
					}
					else break;
				return false;
			}
			if(j>=ls) return false;
			if(p[i]=='.') continue;
			if(p[i]!=s[j]) return false;
		}
		if(j!=ls) return false;
		return true;
	}
};
int main()
{
	Solution S;
	char s[100],p[100];
	while(cin>>s>>p) cout<<S.isMatch(s,p)<<endl;
	return 0;
}
