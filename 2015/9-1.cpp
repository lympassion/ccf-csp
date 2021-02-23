/*
* description: 
*       这个里面因为把if( == )写成了if( = )，真的找半天没找出来
* Author: lympassion
* Date:   2021/2/23
*/

#include <iostream>

using namespace std;


int main(){
    int n, ans, last, val, n_cp;

    scanf("%d", &n);
    n_cp = n;
    ans = 0;
    while (n--)
    {
        scanf("%d", &val);
        // if(n = n_cp-1){  // 这个错误debug都查不出来
        if(n == n_cp-1){
            last = val;
            ans = 1;
        }
        else{
            if(last != val){
                ans++;
                last = val;
            }
        }
    }
    
    printf("%d", ans);
    return 0;
}