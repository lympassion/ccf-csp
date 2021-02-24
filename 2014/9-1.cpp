/*
* description: 
* Author: lympassion
* Date:   2021/2/24
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1003];
int main(){
    int n, ans;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);
    ans = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] - arr[i-1] == 1){
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}