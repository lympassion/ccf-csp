/*
* description: 
*       起初修改好之后提交一直只有50分，后面又读了一下题，
*       发现要记录发生苹果掉落的棵树，所以要加一个判断，以免
*       重复， 其实最好的方法实在判断mp[i] == 1 的地方改变D
* Author: lympassion
* Date:   2021/2/12
*/

#include <iostream>
#include <map>

using namespace std;

const int N = 1e3+3;
const int M = 1e3+3;

int arr[N][M];

map<int, bool> mp;
int main(){
    int n, m, T, D, E;
    int flag, cnt_left;

    scanf("%d", &n);
    T = D = E = 0;
    for(int i = 0; i < n; i++){
        cnt_left = 0;
        flag = 1;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
            if(j != 0 && arr[i][j] >= 1){
                if(cnt_left != arr[i][j]){
                    if(flag){  // 这一定要判断一下
                        D += 1;
                        flag = 0;
                    }
                    
                    mp[i] = 1;
                    cnt_left = arr[i][j];  // update
                }
                
            }

            if(arr[i][j] < 1){
                cnt_left += arr[i][j];
            }
            else{
                cnt_left = arr[i][j];
            }
            
        }
        T += cnt_left;
    }

    for(int i = 0; i < n; i++){
        if(mp[i] && mp[(i+1)%n] && mp[(i-1+n)%n]){
            E += 1;
        }
    }

    printf("%d %d %d", T, D, E);
    return 0;
}