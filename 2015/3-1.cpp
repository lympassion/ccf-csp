/*
* description: 
* Author: lympassion
* Date:   2021/2/23
*/

#include <iostream>

using namespace std;

int arr[1003][1003];
int main(){
    int n, m;

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = m-1; i > -1; i--){
        for(int j = 0; j < n; j++){
            printf("%d%c", arr[j][i], j==n-1 ? '\n' : ' ');
        }
    }
    return 0;
}