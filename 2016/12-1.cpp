/*
* description: 
*       好好读题
* Author: lympassion
* Date:   2021/2/20
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1003];


int main(){
    int n, cnt1, cnt2;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);
    cnt1 = cnt2 = 0;
    for(int i = n/2-1; i > -1; i--){
        if(arr[i] < arr[n/2]){
            cnt1 = i+1;
            break;
        }
    }
    for(int i = n/2+1; i < n; i++){
        if(arr[i] > arr[n/2]){
            cnt2 = n-i;
            break;
        }
    }

    // printf("%d", (cnt1 && cnt1==cnt2) ? arr[n/2] : -1);  // cnt1 = cnt2 = 0 也是符合题意的
    printf("%d", (cnt1==cnt2) ? arr[n/2] : -1);
    return 0;
}


// for(int n=0; n<N; n++) {
//     if(arr[n] < num) cntSmall++;
//     if(arr[n] > num) cntBig++;
// }
// if(cntSmall==cntBig) cout << num;
// else cout << -1;