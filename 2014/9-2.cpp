/*
* description: 
*       这个题目开始考虑的化感觉很复杂，参考了网上的做法，感觉好巧妙
* Author: lympassion
* Date:   2021/2/24
*/

#include <iostream>

using namespace std;

int arr[102][102];
int main(){
    int n, x1, y1, x2, y2, ans;

    scanf("%d", &n);
    ans = 0;
    while (n--)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for(int i = x1; i < x2; i++){  // i <= x2 是错误的
            for(int j = y1; j < y2; j++){
                arr[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(arr[i][j]){
                ans++;
            }
        }
    }

    printf("%d", ans);
    return 0;
}