/*
* description: 
* Author: lympassion
* Date:   2021/2/15
*/

#include <iostream>

using namespace std;

int main(){
    int r, y, g, n, k, t;
    long long tm, need;

    scanf("%d %d %d", &r, &y, &g);
    scanf("%d", &n);
    tm = 0;
    while (n--)
    {
        scanf("%d %d", &k, &t);
        if(k == 0){
            need = t;
            tm += t;
        }
        else if(k == 3){  // g
            // if(need > t){  // 在实际生活中，即便时间不够，也是直接通过
            //     tm += t + y + r;
            // }
        }
        else if(k==2){  // y
            tm += t + r;
        }
        else{  // r
            tm += t;
        }
    }

    printf("%lld", tm);
    
    return 0;
}