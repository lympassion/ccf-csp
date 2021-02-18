/*
* description: 
* Author: lympassion
* Date:   2021/2/18
*/

#include <iostream>

using namespace std;


int main(){
    int n, ans, ans_50, ans_30;

    scanf("%d", &n);
    ans_50 = n / 50;
    n      %= 50;
    ans_30 = n / 30;
    n      %= 30;

    ans = 7 * ans_50 + 4 * ans_30 + n / 10; 
    printf("%d", ans);
    return 0;
}