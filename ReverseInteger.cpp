#include <iostream>
#include <cstdio>
using namespace std;
class Solution
{
public:
	int reverse(int x)
	{
		int ans=0;
		while(x)
		{
			ans=ans*10+x%10;
			x/=10;
		}
		return ans;
	}
};
int main()
{
	Solution s;
	int n;
	while(scanf("%d",&n)!=EOF) cout<<s.reverse(n)<<endl;
	return 0;
}
