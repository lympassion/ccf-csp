/*
* description: 
*       遇到的一个问题就是如果单纯对一个行进行削除，那么可能本应消除的列就消除不了，
*       我的解决方法是标记，而不消除
* Author: lympassion
* Date:   2021/2/23
*/

#include <iostream>
#include <string.h>

using namespace std;

int arr[30][30];
int res[30][30];
int main(){
    int n, m, beg, end, ind, flag;

    scanf("%d%d", &n, &m);
    ind = 0;
    memset(res, 1, sizeof(res));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    ind = 1;
    for(int i = 0; i < n; i++){  // 对于行
        beg = end = 0;
        for(int j = 0; j < m; j=end){
            flag = 0;
            // while (end < n && arr[i][end] == arr[i][beg])  这个地方debug了好久
            while (end < m && arr[i][end] == arr[i][beg])
            {
                end++;
                flag = 1;
            }
            if(end-beg > 2){
                for(int k = beg; k < end; k++){
                    res[i][k] = 0;
                }
            }
            beg = end;
            if(!flag){
                end++;
            }
        }
    }

    ind = 2;
    for(int j = 0; j < m; j++){  // 对于列
        beg = end = 0;
        for(int i = 0; i < n; i=end){
            flag = 0;
            while (end < n && arr[end][j] == arr[beg][j])
            {
                end++;
                flag = 1;
            }
            if(end-beg> 2){
                for(int k = beg; k < end; k++){
                    res[k][j] = 0;
                }
            }
            beg = end;
            if(!flag){
                end++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d%c", !res[i][j] ? 0 : arr[i][j], j==m-1 ? '\n' : ' ');
        }
    }
    return 0;
}


// #include <stdio.h>

// int main() {
//     int board[31][31] = {0};
//     bool remove[31][31] = {0};
//     int N, M, tst;
//     scanf("%d%d", &N, &M);
//     for(int n=0; n<N; n++) {
//         for(int m=0; m<M; m++) {
//             scanf("%d", &board[n][m]);
//         }
//     }
//     int color;
//     int cnt;
//     for(int n=0; n<N; n++) {
//         color = board[n][0];
//         cnt = 1;
//         for(int m=1; m<=M; m++) {
//             if(board[n][m]==color) {
//                 cnt++;
//             }
//             else {
//                 if(cnt>=3) {
//                     while(cnt) {
//                         tst = m-cnt;
//                         remove[n][m-cnt] = true;
//                         cnt--;
//                     }
//                 }
//                 color = board[n][m];
//                 cnt = 1;
//             }
//         }
//     }
//     for(int m=0; m<M; m++) {
//         color = board[0][m];
//         cnt = 1;
//         for(int n=1; n<=N; n++) {
//             if(board[n][m]==color) {
//                 cnt++;
//             }
//             else {
//                 if(cnt>=3) {
//                     while(cnt) {
//                         remove[n-cnt][m] = true;
//                         cnt--;
//                     }
//                 }
//                 color = board[n][m];
//                 cnt = 1;
//             }
//         }
//     }
//     for(int n=0; n<N; n++) {
//         for(int m=0; m<M; m++) {
//             if(remove[n][m]) printf("%d ", 0);
//             else printf("%d ", board[n][m]);
//         }
//         printf("\n");
//     }
// }