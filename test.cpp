/**
**画线用一个函数画就行，在画的路上判断+和另一个|或-的存在就行 
**填充用一个 dfs就行 
**/
 
#include<iostream>
#include<string.h>
using namespace std;
 
char g[105][105];
int n,m,q;
int action,x1,x2,y1,y2,x,y;
char c;
 
int dirX[]={0,0,-1,1};
int dirY[]={1,-1,0,0};
void dfs(int i,int j){
	//cout<<i<<" "<<j<<endl;
	if(i<0||i>=m||j<0||j>=n)return ;
	if(g[j][i]=='+'||g[j][i]=='-'||g[j][i]=='|'||g[j][i]==c)return ;
	g[j][i]=c;
	for(int k=0;k<4;k++){
		dfs(i+dirX[k],j+dirY[k]);
		
	}	
}
int main(){
	memset(g,'.',sizeof(g));
	cin>>m>>n>>q;
	while(q--){
		cin>>action;
		if(action==0){
			cin>>x1>>y1>>x2>>y2;
			
			if(x1==x2){//同一列 
				int maxY=y1>y2?y1:y2;
				int minY=y1>y2?y2:y1;
				for(int j=minY;j<=maxY;j++){
				if(g[j][x1]=='-'||g[j][x1]=='+'){
						g[j][x1]='+';
					}else{
						g[j][x1]='|';
					}
				} 
			}else{
				int maxX=x1>x2?x1:x2;
				int minX=x1>x2?x2:x1;			
				for(int j=minX;j<=maxX;j++){
					if(g[y1][j]=='|'||g[y1][j]=='+'){
						g[y1][j]='+';
					}else{
						g[y1][j]='-';
					}
				} 
			}			
			
		}else{
			cin>>x>>y>>c;
			dfs(x,y);			
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			cout<<g[i][j]/*<<" "我自己这个傻逼*/;
		}cout<<endl;
	}
	return 0;
}