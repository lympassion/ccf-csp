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


// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int N,L,T;
//     scanf("%d%d%d",&N,&L,&T);
//     pair<int,int>ball[N+1];//记录小球信息,小球编号从1开始,first成员记录小球所处位置，second成员记录小球当前的运动方向
//     int line[L+1]={0};//记录线段上小球信息，为0表示没有小球，否则表示小球编号
//     for(int i=1;i<=N;++i){//读取数据
//         scanf("%d",&ball[i].first);
//         ball[i].second=1;
//         line[ball[i].first]=i;
//     }
//     while(T--)//更新T次小球位置信息
//         for(int i=1;i<=N;++i){//遍历N个小球
//             line[ball[i].first]=0;//小球从当前位置移走
//             ball[i].first=ball[i].first+ball[i].second;//小球移动到即将到达的位置处
//             if(line[ball[i].first]!=0){//小球移动到即将到达的位置处有其他小球，将这两个小球运动方向均置反向
//                 ball[i].second=-ball[i].second;
//                 ball[line[ball[i].first]].second=-ball[line[ball[i].first]].second;
//             }else if(ball[i].first==0||ball[i].first==L)//小球移动到即将到达的位置是线段两端
//                 ball[i].second=-ball[i].second;//将这个小球运动方向均置反向
//             line[ball[i].first]=i;//小球移动到即将到达的位置处
//         }
//     for(int i=1;i<=N;++i)//输出
//         printf("%d ",ball[i].first);
//     return 0;
// }