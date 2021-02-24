/*
* description: 
*       参考网上的解法
* Author: lympassion
* Date:   2021/2/24
*/

#include <iostream>

using namespace std;

const int EAST = 0;
const int SOUTH = 1;
const int SOUTHWEST = 2;
const int NORTHEAST = 3;

struct direct
{
    int row;
    int col;
};

direct direct1[4] = {
        {0, 1},  // east
        {1, 0},  // south
        {1, -1},  // southwest
        {-1, 1},  // northeast
    };

int arr[502][502];
int main(){
    int n, row, col, next;               
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    row = col = 0;
    printf("%d ", arr[row][col]);
    next = EAST;
    while (row != n-1 || col != n-1)
    {
        row += direct1[next].row;
        col += direct1[next].col;
        printf("%d ", arr[row][col]);
        switch(next){
            case EAST:
            if(row == 0){
                next = SOUTHWEST;
            }
            else if(row == n-1){
                next = NORTHEAST;
            }
            break;
            case SOUTHWEST:
            if(row == n-1){
                next = EAST;
            }
            else if(col == 0){
                next = SOUTH;
            }
            break;
            case SOUTH:
            if(col == 0){
                next = NORTHEAST;
            }
            else if(col == n-1){
                next = SOUTHWEST;
            }
            break;
            case NORTHEAST:
            if(col == n-1){  // 这两个的顺序不能反
                next = SOUTH;
            }
            else if(row == 0){
                next = EAST;
            }
            break;
        }
    }
    
    return 0;
}