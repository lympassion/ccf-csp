/*
* description: 
*           这道题应该注意连续k这个条件，而不是简单的相加
* Author: lympassion
* Date:   2021/2/23
*/

#include <iostream>
#include <math.h>
#include <algorithm>


using namespace std;


int main(){
    int n, k, t, xl, yd, xr, yu;
    int through, stay, pos_x, pos_y, cnt, max_cnt, stay_cnt;

    scanf("%d %d %d %d %d %d %d", &n, &k, &t, &xl, &yd, &xr, &yu);

    through = stay = 0;
    for(int i = 0; i < n; i++){
        cnt      = 0;
        stay_cnt = 0;
        max_cnt  = 0;
        for(int j = 0; j < 2*t; j+=2){
            scanf("%d %d", &pos_x, &pos_y);
            if((pos_x>=xl && pos_x<=xr) && (pos_y>=yd && pos_y<=yu)){
                cnt += 1;
                stay_cnt++;
                max_cnt = max(max_cnt, stay_cnt);
            }
            else{
                stay_cnt = 0;
            }
        }

        through = cnt ? through+1 : through;
        if(max_cnt >= k){
            stay++;
        }
    } 

    printf("%d\n%d\n", through, stay);
    return 0;
}