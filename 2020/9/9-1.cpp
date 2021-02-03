#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct distance
{
    int id;
    int xx;
    int yy;
    double res;
};

typedef struct distance dis;
dis dis1[202];

bool cmp(dis a, dis b){
    /*
    * 这里的这个cmp函数不能写成下面这样
    * 一定要通过if来判断
    */

    // return a.res <= b.res;

    if(a.res == b.res){
        return a.id < b.id;
    }
    return a.res < b.res;
}



int main(){
    int n, x, y;

    scanf("%d %d %d", &n, &x, &y);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &dis1[i].xx, &dis1[i].yy);
        dis1[i].id = i+1;
        dis1[i].res = pow((pow(abs(dis1[i].xx - x), 2) + pow(abs(dis1[i].yy - y), 2)), 0.5);
        // dis1[i].res = pow(abs(dis1[i].xx - x), 2) + pow(abs(dis1[i].yy - y), 2);

    }
    
    sort(dis1, dis1+n, cmp);
    for(int i = 0; i < 3; i++){
        printf("%d\n", dis1[i].id);
    }
    return 0;
}