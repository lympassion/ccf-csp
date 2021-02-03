/*
* description: 
*       程序中错误的逻辑这次没有删去，错误的原因是可能同样都是A类的点，但可能就分布在直线的两侧
*       这种情况没有考虑到
* Author: lympassion
* Date:   2021/2/23
*/

#include <iostream>

using namespace std;


struct position
{
    int x;
    int y;
    char type[5];
};

typedef struct position pos;
pos pos1[1003];

int main(){
    int n, m;
    int para1, para2, para3, val_A, val_B, flag_A, flag_B, flag;
    char cha;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d %c", &pos1[i].x, &pos1[i].y, &(pos1[i].type));
    }

    // for(int i = 0; i < m; i++){
    //     flag = flag_A = flag_B = 0;
    //     scanf("%d %d %d", &para1, &para2, &para3);

    //     for(int j = 0; j < n; j++){
    //         cha = pos1[j].type[0];
    //         if(pos1[j].type[0] == 'A'){
    //             val_A  = para1 + para2*pos1[j].x + para2*pos1[j].y;
    //             flag_A = 1;
    //         }
    //         else{
    //             val_B  = para1 + para2*pos1[j].x + para2*pos1[j].y;
    //             flag_B = 1;
    //         }
            
    //         if(flag_A && flag_B){
    //             if(val_A*val_B > 0){
    //                 printf("%s\n", "No");
    //                 flag = 1;
    //                 break;
    //             }
    //         }
    //     }

    //     if(!flag){
    //         printf("%s\n", "Yes");
    //     }
    // }

    int val, cnt1, cnt2, cnt3, cnt4;
    for(int i = 0; i < m; i++){
        cnt1 = cnt2 = cnt3 = cnt4 = 0;
        scanf("%d %d %d", &para1, &para2, &para3);

        for(int j = 0; j < n; j++){

            // val  = para1 + para2*pos1[j].x + para2*pos1[j].y; 这种错误

            val  = para1 + para2*pos1[j].x + para3*pos1[j].y;

            if(val > 0){ // 同一个方向下面只应该有一个
                if(pos1[j].type[0] == 'A'){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
            else{
                if(pos1[j].type[0] == 'A'){
                    cnt3++;
                }
                else{
                    cnt4++;
                }
            }
            
        }

        printf("%s\n", ((cnt1&&cnt2) || (cnt3&&cnt4)) ? "No" : "Yes");
    }
    return 0;
}