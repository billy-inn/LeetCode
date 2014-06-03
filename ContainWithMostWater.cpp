#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	int maxArea(vector<int> &height)
	{
		int len=height.size();
		int L=0,R=len-1;
		int ans=0;
		while(L<R)
		{
			ans=max(ans,(R-L)*min(height[L],height[R]));
			int tmp;
			if(height[L]>height[R])
			{
				tmp=R-1;
				while(L<tmp && height[tmp]<=height[R]) tmp--;
				R=tmp;
			}
			else
			{
				tmp=L+1;
				while(tmp<R && height[tmp]<=height[L]) tmp++;
				L=tmp;
			}
		}
		return ans;
	}
};
int main()
{

	return 0;
}
