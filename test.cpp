#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int N=1e3+50;
struct node{
	int x,y;
	node(){
	}
	node(int a,int b)
	{
		x=a;
		y=b;
	}

	bool operator <(const node &oth)const
	{
		if(x!=oth.x)
			return x<oth.x;
		return y<oth.y;
	}
}h[N];
map<node,bool>mp;//查询某个点是否存在，存在=1，否则=0 
int c[6];
int main()
{
	int n,x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		h[i]=node(x,y);
		mp[h[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		x=h[i].x;
		y=h[i].y;
		if(mp[node(x+1,y)]&&mp[node(x-1,y)]&&mp[node(x,y+1)]&&mp[node(x,y-1)])
		{
			cnt=mp[node(x+1,y+1)]+mp[node(x+1,y-1)]+mp[node(x-1,y+1)]+mp[node(x-1,y-1)];
			c[cnt]++;
		}
		
	}
	for(int i=0;i<5;i++)
		printf("%d\n",c[i]);
	return 0;
}
