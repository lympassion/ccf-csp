/*
* description:
*       网上写的简单的用的是find 
* Author: lympassion
* Date:   2021/3/3
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char s[102], in_s[102];
    int n, bl, len, ind;

    scanf("%s%d%d", &s, &bl, &n);
    len = strlen(s);
    while (n--)
    {
        scanf("%s", in_s);
        ind = 0;
        for(int i = 0; i < strlen(in_s); i++){
            if(bl){  // 大小写敏感
                if(in_s[i] == s[ind]){
                    ind++;
                }
                else{
                    ind = 0; 
                }
            }
            else{
                if(tolower(in_s[i])  == tolower(s[ind])){
                    ind++;
                }
                else{
                    ind = 0; 
                }
            }
            if(ind == len){
                printf("%s\n", in_s);
                break;
            }
        }
    }
    
    return 0;
}

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