/*
* description: 
* Author: lympassion
* Date:   2021/2/24
*/

#include <iostream>

using namespace std;

int arr[1003];
int main(){
    int n, val;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &val);
        printf("%d ", ++arr[val]);  // csp的检查对于末尾多余的空格不管
    }
    
    return 0;
}