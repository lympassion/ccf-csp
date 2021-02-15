/*
* description: 
* Author: lympassion
* Date:   2021/2/15
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6+6;
int arr[N];
int main(){
    int n, a, b, val, ans;
    
    scanf("%d", &n);
    for(int i = 0; i < 2*n; i++){
        scanf("%d %d", &a, &b);
        val = max(val, b);
        for(int j = a; j < b; j++){
            arr[j]++;
        }
    }

    ans = 0;
    for(int i = 0; i < val; i++){
        if(arr[i] == 2){
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}