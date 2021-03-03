#include<iostream>
#include<algorithm>
using namespace std;
string Str,str,bks;int opt,n;

char op(char c){
    return toupper(c); 
}
inline void trans(string &s){
    // transform(s.begin(),s.end(),s.begin(),::tolower);  //every c=tolow(c)
    transform(s.begin(),s.end(),s.begin(),op);
    
}
int main(){
    cin>>Str;
    cin>>opt>>n;
    if(!opt) trans(Str);
    for(int i=0,pos;i<n;i++){
        cin>>str;bks=str;
        if(!opt) trans(str);
        pos=str.find(Str);  // 返回找到的初始位置，没有找的的话返回值为-1，~(-1) = 0
        // printf("%d %d\n", pos, ~pos);
        if(~pos) cout<<bks<<"\n";  
    }
    return 0;
}