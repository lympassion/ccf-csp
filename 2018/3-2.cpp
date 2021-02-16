/*
* description: 
* Author: lympassion
* Date:   2021/2/15
*/

#include <iostream>
#include <string.h>

using namespace std;

struct coordinate
{
    int pos;
    int direction;
};

typedef struct coordinate coor;
coor c[102];

int main(){
    int n, L, t, tmp;
    int arr[1003];

    memset(arr, 0, sizeof(arr));
    scanf("%d %d %d", &n, &L, &t);
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i].pos);
        arr[c[i].pos]++;  // 在c[i]位置的球的个数
        c[i].direction = 1;
    }

    while (t--)
    {
        for(int i = 0; i < n; i++){
            if(arr[c[i].pos] == 2){
                c[i].direction *= -1;
                for(int j = i+1; j < n; j++){  // j = i是逻辑错误
                    if(c[j].pos == c[i].pos){
                        c[j].direction *= -1;
                        break;
                    }
                }
            }
            else if(c[i].pos == L){
                c[i].direction *= -1;
            }
            else if(c[i].pos==0){
                c[i].direction *= -1;
            }
            arr[c[i].pos] = 0;
            c[i].pos += c[i].direction;
            tmp = c[i].pos;
            arr[c[i].pos]++;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d%c", c[i].pos, i==n-1 ? '\n' : ' ');
    }
    return 0;
}