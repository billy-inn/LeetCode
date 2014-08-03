#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int m = points.size();
        if(m==0) return 0;
        bool *vis = (bool*)malloc(sizeof(bool)*m*m);
        memset(vis,false,sizeof(bool)*m*m);
        int tmp,x,x1,x2,y,y1,y2,ans=1;
        for(int i=0;i<m;i++)
		{
			int e=1;
            for(int j=i+1;j<m;j++)
			{
                x1=points[i].x,x2=points[j].x;
                y1=points[i].y,y2=points[j].y;
				if(x1==x2 && y1==y2) 
				{
					e++;
					vis[i*m+j]=true;
				}
			}
			if(e>ans) ans=e;
			for(int j=i+1;j<m;j++)
                if(!vis[i*m+j])
                {
                    x1=points[i].x,x2=points[j].x;
                    y1=points[i].y,y2=points[j].y;
                    tmp=e+1;
                    for(int k=j+1;k<m;k++) if(!vis[i*m+k])
                    {
                        x=points[k].x,y=points[k].y;
                        if((y1-y2)*(x-x1)==(x1-x2)*(y-y1))
                        {
                            tmp++;
                            vis[i*m+k]=vis[j*m+k]=true;
                        }
                    }
                    if(tmp>ans) ans=tmp;
                }
		}
        free(vis);
        return ans;
    }
};
int main()
{
	freopen("in.txt","r",stdin);
	vector<Point> points;
	Solution s;
	char c;
	int x,y;
	while((c=getchar()))
	{
		if(c==']') break;
		if(c=='(')
		{
			scanf("%d,%d)",&x,&y);
			points.push_back(Point(x,y));
		}
	}
	cout<<s.maxPoints(points)<<endl;
	return 0;
}
