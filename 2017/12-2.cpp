/*
* description: 
*       一定要注意已经淘汰的人不参与后面的报数
* Author: lympassion
* Date:   2021/2/18
*/

#include <iostream>
#include <map>

using namespace std;


int arr[1003];
int main(){
    int n, k, cnt, ind;

    scanf("%d %d", &n, &k);
    arr[1002] = n;
    ind = 0;
    cnt = 1;
    while (arr[1002] != 1)
    {
        if(cnt % k == 0 || cnt % 10 == k){
            arr[ind%n] = 1;
            arr[1002] -= 1;
        }
        while (arr[(++ind)%n] == 1)  // 一直走到未被淘汰的人
        {
        }
        cnt++;
    }
    
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            printf("%d", i+1);
        }
    }
    return 0;
}