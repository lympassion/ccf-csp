/*
* description: 
* Author: lympassion
* Date:   2021/2/24
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct info
{
    int cnt;
    int val;
};

info info1[1003];

bool cmp(info a, info b){
    if(a.cnt == b.cnt){
        return a.val < b.val;
    }
    return a.cnt > b.cnt;
}

int main(){
    int n, val;

    scanf("%d", &n);
    for(int i = 0; i < 1003; i++){
        info1[i].cnt = 0;
        info1[i].val = 0;
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        info1[val].val = val;
        info1[val].cnt += 1;
    }
    
    sort(info1, info1+1003, cmp);
    for(int i = 0; i < 1003; i++){
        if(info1[i].cnt > 0){
            printf("%d %d\n", info1[i].val, info1[i].cnt);
        }
    }
    return 0;
}