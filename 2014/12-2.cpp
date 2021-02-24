/*
* description: 
*       1. 参考网上的解法
*       2. 又忘了case的break
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


// #include <iostream>

// using namespace std;

// const int EAST = 0;
// const int SOUTH = 1;
// const int SOUTHWEST = 2;
// const int NORTHEAST = 3;
 
// struct {
//     int drow;
//     int dcol; //EAST  SOUTH  SOUTHWEST  NORTHEAST
// } direct[] = {{0, 1}, {1, 0}, {1, -1}, {-1, 1}};
 
// const int N = 500;
 
// int a[N][N];
 
// int main()
// {
//     int n;
 
//     // 输入数据
//     cin >> n;
//     for(int i=0; i<n; i++)
//         for(int j=0; j<n; j++)
//             cin >> a[i][j];
 
//     // Z字形扫描，输出结果
//     int row=0, col=0, next=EAST;
//     cout << a[row][col];
//     while(row != n - 1 || col != n - 1) {
//         row += direct[next].drow;
//         col += direct[next].dcol;
//         cout << " " << a[row][col];
 
//         if(next == EAST && row == 0)
//             next = SOUTHWEST;
//         else if(next == EAST && row == n - 1)
//             next = NORTHEAST;
//         else if(next == SOUTH && col == 0)
//             next = NORTHEAST;
//         else if(next == SOUTH && col == n - 1)
//             next = SOUTHWEST;
//         else if(next == SOUTHWEST && row == n - 1)  // 虽然当next == SOUTHWEST还有第三种情况，但是这里是elseif，
//             next = EAST;                            // 不满足条件就不会变
//         else if(next == SOUTHWEST && col == 0)
//             next = SOUTH;
//         else if(next == NORTHEAST && col == n - 1)
//             next = SOUTH;
//         else if(next == NORTHEAST && row == 0)
//             next = EAST;
//     }
//     cout << endl;
 
//     return 0;
// }
