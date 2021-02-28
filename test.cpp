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
    int m, n;

    printf("%s", 40+'0');
    
    return 0;
}