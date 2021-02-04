#include <iostream>

using namespace std;

bool isOK(int n){
	
	if(n%7==0)
		return false;
	
	while(n>0){
		if(n%10==7)
			return false;
		n=n/10;
	}
	
	return true;
}

int main(int argc, char** argv) {
	
	int res[4]={0}; 
	int n;
	int num=0;
	int count=0;
	
	cin>>n;
	
	for(int i=0;count<n;i++){
		if(!isOK(++num))
			res[i%4]++;
		else
			count++;
	}
	
	for(int i=0;i<4;i++)
		cout<<res[i]<<endl;
	
	return 0;
}