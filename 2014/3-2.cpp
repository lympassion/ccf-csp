/*
* description: 
*       这道题做得很不顺手，关键在于找到一个中间的窗口，把他换来换去的，索引应该如何改变，
*       最后看了网上的。直接用一个权重结合sort函数即可。
* Author: lympassion  
* Date:   2021/2/28
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct window
{
    int x1, y1;
    int x2, y2;
    int id;
    int wgt;  // 越上层权重越高
};

window win[10];

bool cmp(window a, window b){
    return a.wgt > b.wgt;
}

int main(){
    int n, m, x, y, wgt, id;

    scanf("%d%d", &n, &m);
    wgt = 0;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &win[i].x1, &win[i].y1, &win[i].x2, &win[i].y2);
        win[i].id  = i+1;
        win[i].wgt = wgt++;
    }

    while (m--)
    {
        scanf("%d%d", &x, &y);
        id = -1;
        sort(win, win+n, cmp);
        for(int i = 0; i < n; i++){
            if(win[i].x1 <= x && win[i].x2 >= x && win[i].y1 <= y && win[i].y2 >= y){
                id         = win[i].id;
                win[i].wgt = wgt++;
                break;
            }
        }

        if(id == -1){
            printf("%s\n", "IGNORED");
        }
        else{
            printf("%d\n", id);
        }
    }
    
    return 0;
}