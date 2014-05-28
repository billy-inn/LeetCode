#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
	void reverseWords(string &s)
	{
		string t;
		int pre=-1;
		for(int i=0;i<s.size();i++)
			if(s[i]==' ')
			{
				if(pre!=-1)
				{
					if(t!="") t=' '+t;
					for(int j=i-1;j>=pre;j--) t=s[j]+t;
					pre=-1;
				}
			}
			else
			{
				if(pre==-1) pre=i;
			}
		if(pre!=-1)
		{
			if(t!="") t=' '+t;
			for(int i=s.size()-1;i>=pre;i--) t=s[i]+t;
		}
		s=t;
	}
};
int main()
{
	Solution a;
	string s="the sky is blue";
	a.reverseWords(s);
	cout<<s<<endl;
	return 0;
}
