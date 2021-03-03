#include<iostream>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Node{
	string value;
	double p;
	int num;
	int flag;
};
Node node[5005];
set<double> price;
set<double>::iterator it;
int main(){
	int n=1,i;
	long long maxnum=0;
	double maxp;
	int pos;
	while(cin>>node[n].value){	
		if(node[n].value!="cancel"){
		    cin>>node[n].p>>node[n].num;
		}	
		else{
			cin>>pos;
			node[n].flag=1;
			node[pos].flag=1;
		} 
		n++;  	
	}
	//将有效购买价格加入set集合中 
	for(i=1;i<n;i++){
		if(node[i].flag!=1&&node[i].value=="buy"){
			price.insert(node[i].p);
		}
	}
	for(it=price.begin();it!=price.end();it++){
		long long buynum=0,sellnum=0,num;
		double p=*it;
	 	for(i=1;i<n;i++){
	 		if(node[i].p>=p&&node[i].value=="buy"&&node[i].flag!=1)
	 		  buynum+=node[i].num;
            else if(node[i].p<=p&&node[i].value=="sell"&&node[i].flag!=1)
	 		  sellnum+=node[i].num;
		 }
		// for(i=1;i<n;i++){
	 	// 	if(node[i].p<=p&&node[i].value=="sell"&&node[i].flag!=1)
	 	// 	  sellnum+=node[i].num;
		//  }
		num=min(buynum,sellnum);
		if(num>=maxnum){
			maxnum=num;
			maxp=p;
		}
	 }
	printf("%.2lf %lld\n",maxp,maxnum);
	//也可使用cout输出
	//cout<<fixed<<setprecision(2)<<maxp<<" ";
	//cout<<maxnum<<endl;
	return 0;
} 


