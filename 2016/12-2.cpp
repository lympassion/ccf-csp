/*
* description: 
* Author: lympassion
* Date:   2021/2/20
*/

#include <iostream>

using namespace std;


int main(){
    int s, t, a, flag, ind;

    scanf("%d", &t);

    // S-3500
    // 1500 
    int gap[6] = {1500, 4500, 9000, 35000, 55000, 80000};
    double tax_rate[7] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
    double total[6];
    int arr[6] = {1500};
    for(int i = 1; i < 6; i++){
        arr[i] = gap[i] - gap[i-1];
    }
    for(int i = 0; i < 6; i++){
        total[i] = arr[i] * (1-tax_rate[i]);
        if(i>0){
            total[i] += total[i-1];
        }
    }
    a = t-3500;

    if(a <= 0){
        s = t;
    }
    else{
        flag = 0;  
        ind = 0;  // 一定要初始化
        for(int i = 5; i > -1; i--){
            if(a > total[i]){
                ind = i;
                flag = 1;
                break;
            }
        }
        // s = (a - total[ind]) / tax_rate[ind+1] + gap[ind] + 3500;
        if(flag){
            s = (a - total[ind]) / (1-tax_rate[ind+1]) + gap[ind] + 3500;
        }
        else{
            s = a / (1-tax_rate[ind]) + 3500;  // 起初没有考虑到这种情况，一直卡90分
        }
    }

    printf("%d", s);
    return 0;
}