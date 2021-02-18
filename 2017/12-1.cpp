/*
* description: 
* Author: lympassion
* Date:   2021/2/15
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a < b;
}
int main(){
    int n, ans;
    int arr[1003];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n, cmp);
    ans = 10000;
    for(int i = 1; i < n; i++){
        ans = ans<(arr[i]-arr[i-1]) ? ans : (arr[i]-arr[i-1]);
    }
    printf("%d\n", ans);
    return 0;
}
