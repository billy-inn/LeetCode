#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
	string convert(string s,int nRows)
	{
		if(nRows==1) return s;
		string ans="";
		int len=s.size();
		int seg=2*nRows-2;
		for(int i=0;i<len;i+=seg) ans+=s[i];
		for(int i=1;i<nRows-1;i++)
		{
			for(int j=i;j<len;j+=seg)
			{
				ans+=s[j];
				if(j+seg-2*i<len) ans+=s[j+seg-2*i];
			}
		}
		for(int i=nRows-1;i<len;i+=seg) ans+=s[i];
		return ans;
	}
};
int main()
{
	Solution s;
	cout<<s.convert("PAYPALISHIRING",2)<<endl;
	return 0;
}
