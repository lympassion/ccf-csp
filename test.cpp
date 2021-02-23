#include <iostream>
#include<algorithm>


using namespace std;

int main()
{
	int a[15][10];
	int b[4][4];
	int start;
	int upborder[4]={14,14,14,14},lowborder[4]={-10,-10,-10,-10};
	for(int i=0;i<15;i++)
		for(int j=0;j<10;j++)
			cin>>a[i][j];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			cin>>b[i][j];
	cin>>start;
	start=start-1;
	for(int i=start;i<start+4;i++)     //原始数组的上界 
		for(int j=0;j<15;j++)
			if(a[j][i]==1)
			{
				upborder[i-start]=j-1;
				break;
			}
	for(int i=0;i<4;i++)         //输入数组的下界 
		for(int j=0;j<4;j++)
			if(b[j][i]==1)
				lowborder[i]=j;
	int minx(20);
	int t(0);
	for(int i=0;i<4;i++)    //对比得最小距离 
		if(upborder[i]-lowborder[i]<minx)
		{//标记最短距离
			minx=upborder[i]-lowborder[i];
			t=i;
		}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(b[i][j]==1)//标记
				a[upborder[t]-lowborder[t]+i][start+j]=1;
	for(int i=0;i<15;i++)
	{//输出
		for(int j=0;j<10;j++)
		{
			if(j==0)
				cout<<a[i][j];
			else
				cout<<" "<<a[i][j];
		}	
		cout<<endl;
	}
	return 0;
}