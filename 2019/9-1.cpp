/*
* description: 
* Author: lympassion
* Date:   2021/2/12
*/

#include <iostream>

using namespace std;

int a[1003][1003];
int main(){
    int n, m;
    int cnt_left, num, ind, total;

    scanf("%d %d", &n, &m);
    num = 0;
    total = 0;
    for(int i = 0; i < n; i++){
        cnt_left = 0;
        for(int j = 0; j < m+1; j++){
            scanf("%d", &a[i][j]);
            cnt_left += a[i][j];
        }

        if(num < a[i][0]-cnt_left){
            ind = i+1;
            num = a[i][0]-cnt_left;
        }
        total += cnt_left;
    }

    printf("%d %d %d", total, ind, num);
    return 0;
}