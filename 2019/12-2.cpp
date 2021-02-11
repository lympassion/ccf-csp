/*
* description: 
*       cmp函数一定要注意
*       第二次提交错误是因为有一个测试输出没注释
*       注释的那种做法是在网上找的，其实本来就是想要用
*       注释的这种做法，因为这种做法逻辑更简单一些
* Author: lympassion
* Date:   2021/2/12
*/

#include <iostream>
#include <algorithm>

using namespace std;


struct coordinate
{
    int x;
    int y;
};

typedef struct coordinate coor;
coor c[1003];

bool cmp(coor c1, coor c2){
    // if(c1.x < c2.x){
    //     return c1.x < c2.x;
    // }
    // return c1.y < c2.y;
    if(c1.x == c2.x){
        return c1.y < c2.y;
    }
    return c1.x < c2.x;
}

int main(){
    int n;

    int ind, valx, valy, diff_x, diff_y;
    int cnt0, cnt1, ans[5] = {0};

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &c[i].x, &c[i].y);
    }

    sort(c, c+n, cmp);

    for(int i = 0; i < n; i++){
        cnt0 = 0;
        cnt1 = 0;
        valx = c[i].x;
        valy = c[i].y;
        ind  = i-1;
        diff_x = diff_y = 0;
        while (ind >= 0 && diff_x < 2)  // 从这个数向左边开始找
        {
            diff_x = abs(c[i].x - c[ind].x);
            diff_y = abs(c[i].y - c[ind].y);
            if(diff_x * diff_y == 0 && (diff_x==1 || diff_y ==1)){
                cnt0++;
            }
            else if(diff_x * diff_y == 1){
                cnt1 += 1;
            }
            ind--;            
        }

        ind = i+1;
        diff_x = 0;
        while (ind < n && diff_x < 2)  // 从这个数向右边开始找
        {
            diff_x = abs(c[i].x - c[ind].x);
            diff_y = abs(c[i].y - c[ind].y);
            if((diff_x * diff_y == 0) && (diff_x==1 || diff_y ==1)){
                cnt0++;
            }
            else if(diff_x * diff_y == 1){
                cnt1 += 1;
            }
            ind++;            
        }
        
        if(cnt0 == 4){
            ans[cnt1]++;
        }
    }
    
    for(int i = 0; i < 5; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}

// #include <iostream>
// #include <map>

// using namespace std;

// const int N = 1e3+3;

// struct coordinate
// {
//     int x;
//     int y;
//     coordinate(){  // 必须要有这样一个构造函数
//     }
//     coordinate(int a, int b){
//         x = a;
//         y = b;
//     }
//     bool operator < (const coordinate &c)const{
//         if(x == c.x){
//             return y < c.y;
//         }
//         return x < c.x;
//     }
    
// }c[N];

// map<coordinate, bool>mp;

// int main(){
//     int n;
//     int x, y, cnt;
//     int ans[5] = {0};

//     scanf("%d", &n);
//     for(int i = 0; i < n; i++){
//         scanf("%d %d", &c[i].x, &c[i].y);
//         mp[c[i]] = 1;
//     }

//     for(int i = 0; i < n; i++){
//         x = c[i].x;
//         y = c[i].y;

//         if(mp[coordinate(x-1, y)] && mp[coordinate(x+1, y)] && mp[coordinate(x, y-1)] && mp[coordinate(x, y+1)]){
//             cnt = mp[coordinate(x-1, y+1)] + mp[coordinate(x-1, y-1)] + mp[coordinate(x+1, y-1)] + mp[coordinate(x+1, y+1)];
//             ans[cnt]++;
//         }
//     }

//     for(int i = 0; i < 5; i++){
//         printf("%d\n", ans[i]);
//     }
//     return 0;
// }