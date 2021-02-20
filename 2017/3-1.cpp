/*
* description: 
* Author: lympassion
* Date:   2021/2/20
*/

#include <iostream>

using namespace std;


int main(){
    int n, k, ans, cnt, wgt;

    scanf("%d %d", &n, &k);
    ans = cnt = 0;
    while (n--)
    {
        scanf("%d", &wgt);
        cnt += wgt;
        if(cnt >= k || n == 0){
            ans++;
            cnt = 0;
        }
    }
    
    printf("%d", ans);
    return 0;
}