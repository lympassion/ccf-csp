/*
* description: 
* Author: lympassion
* Date:   2021/2/15
*/

#include <iostream>

using namespace std;

const int N=1e3+3;
int arr[N];

int main(){
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        if(i == 0){
            printf("%d", (arr[i]+arr[i+1]) / 2);
        }
        else if(i==n-1){
            printf("%d", (arr[i]+arr[i-1]) / 2);
        }
        else{
            printf("%d", (arr[i]+arr[i+1]+arr[i-1]) / 3);
        }
        printf("%c", i==n-1 ? '\n' : ' ');
    }
    return 0;
}