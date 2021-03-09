/*
* description:
* Author: lympassion
*       填充的规则就像向一个不规则容器注水一样，方向性该如何把控感觉比较复杂
*       想了半天最感觉一些地方有些问题，看了题解，使用dfs，dfs的使用过程中还是有很多bug
* Date:   2021/3/5
*/

#include <iostream>
#include <string.h>

using namespace std;
int m, n; // m代表宽，n代表高
char c;

char arr[102][102];
int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, -1, 1};
void dfs(int x, int y, char c){
    if(x<0 || x >=m || y < 0 || y >= n){
        return;
    }
    else if(arr[y][x] == '-' || arr[y][x] == '|' || arr[y][x] == '+' || arr[y][x] == c){  
        // 这里忘了写arr[y][x] == c 造成函数陷入循环
        return;
    }
    else{
        arr[y][x] = c;
    }
    for(int i = 0 ; i < 4; i++){
        dfs(x+dirX[i], y+dirY[i], c);
    }
}


int direction[8];
int main(){
    memset(arr, '.', sizeof(arr));
    int q, flag, x1, y1, x2, y2, x, y, maxX, maxY, minX, minY;
    char tmpC;

    scanf("%d%d%d", &m, &n, &q);

    while (q--)
    {
        scanf("%d", &flag);
        if(!flag){  // 画-
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            maxX = x1 < x2 ? x2 : x1;
            maxY = y1 < y2 ? y2 : y1;
            minX = x1 < x2 ? x1 : x2;
            minY = y1 < y2 ? y1 : y2;
            if(x1 == x2){ // 在同一列
                for(int i = minY; i <= maxY; i++){
                    if(arr[n-1-i][x1] == '-' || arr[n-1-i][x1] == '+'){
                        arr[n-1-i][x1] = '+';
                    }
                    else{
                        arr[n-1-i][x1] = '|';
                    }
                }
            }
            else{
                for(int i = minX; i <= maxX; i++){
                    if(arr[n-1-y1][i] == '|' || arr[n-1-y1][i] == '+'){
                        arr[n-1-y1][i] = '+';
                    }
                    else{
                        arr[n-1-y1][i] = '-';
                    }
                }
            }
        }
        else{  // 开始填充
            scanf("%d%d %c", &x, &y, &c);  // scanf("%d%d%c", &x, &y, &c); 这样的话c = ' '
            tmpC =c;
            y = n-1-y;
            dfs(x, y, c);
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%c", arr[i][j]);
        }
        printf("%c", '\n');
    }
    return 0;
}