/*
* description: 
* Author: lympassion
* Date:   2021/2/21
*/

#include <iostream>

using namespace std; 

int arr[1003];
int main(){
    int n, ans;

    scanf("%d", &n);
    ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(i > 0){
            ans = max(ans, abs(arr[i]-arr[i-1]));
        }
    }
    
    printf("%d", ans);
    return 0;
}