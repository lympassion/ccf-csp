/*
* description: 
* Author: lympassion
* Date:   2021/2/12
*/

#include <iostream>

using namespace std;

const int N = 1e5+5;
int arr[N];
int main(){
    int n;
    int max_v, min_v, val, sum, flag, mid_v_i;
    float mid_v_f;

    scanf("%d", &n);
    sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        if(i == 0){
            max_v = val;
        }
        else if(i == n-1){
            min_v = val;
        }

        if(n%2 == 0){
            if(i == n/2-1 || i == n/2){
                sum += val;
            }
        }
        else{
            if(i==n/2){
                sum += val;
            }
        }
    }

    mid_v_f = n%2==0 ? sum/2.0 : sum; 
    flag = 1;
    if(n%2 == 0 && sum%2 != 0){
        flag = 0;
    }
    mid_v_i = mid_v_f;
    if(max_v < min_v){
        sum   = max_v;
        max_v = min_v;
        min_v = sum;
    }

    
    if(flag){
        printf("%d %d %d", max_v, mid_v_i, min_v);
    }
    else{
        printf("%d %.1f %d", max_v, mid_v_f, min_v);
    }
    return 0;
}