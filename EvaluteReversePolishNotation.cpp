#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
	int evalRPN(vector<string> &tokens)
	{
		stack<int> sta;
		int a,b;
		for(int i=0;i<tokens.size();i++)
		{
			string s=tokens[i];
			if(s[0]>='0' && s[0]<='9') sta.push(getnum(s));
			else if(s.size()>1)	sta.push(-getnum(s.substr(1)));
			else
			{
				b=sta.top();sta.pop();
				a=sta.top();sta.pop();
				//cout<<a<<" "<<s[0]<<" "<<b<<endl;
				switch (s[0])
				{
					case '+':sta.push(a+b);break;
					case '-':sta.push(a-b);break;
					case '*':sta.push(a*b);break;
					case '/':sta.push(a/b);break;
				}
			}
		}
		return sta.top();
	}
	int getnum(string s)
	{
		int ans=0;
		for(int i=0;i<s.size();i++) ans=ans*10+s[i]-'0';
		return ans;
	}
};
int main()
{
	vector<string> v;
	v.push_back("-1");
	v.push_back("1");
	v.push_back("*");
	v.push_back("-1");
	v.push_back("+");
	Solution s;
	cout<<s.evalRPN(v)<<endl;
	return 0;
}
