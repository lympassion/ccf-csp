/*
* description: 
*       黄灯下来是红灯
*       注释中是更小巧的方法
* Author: lympassion
* Date:   2021/2/15
*/

#include <iostream>

using namespace std;


int main(){
    int r, g, y, n, k, t, circle;
    long long tm, tm2, tm3;
    int arr[3];

    scanf("%d %d %d", &r, &y, &g);
    arr[0] = y;
    arr[1] = r;
    arr[2] = g;
    circle = arr[0] + arr[1] + arr[2];
    scanf("%d", &n);
    tm = 0;
    while (n--)
    {
        scanf("%d %d", &k, &t);
        if(k == 0){
            tm += t;
        }
        else{
            tm2 = tm % circle;
            tm3 = t;  // tm3 表示某种灯还有多少秒
            switch (k)  // 这里要对k重新映射，黄灯下来要是红灯
            {
            case 2:  // y
                k = 1;
                break;
            case 1:  // r
                k = 2;
                break;  // 注意这里的break
            default:
                k = 3;
                break;
            }
            while (tm2 > tm3)
            {
                tm2 -= tm3;
                k++;  // 首先应该k++
                tm3 = arr[(k-1)%3];
            }
            t = tm3 - tm2;
            k = (k-1)%3 + 1;
            if(k == 3){  // g
            
            }
            else if(k==2){  // r
                tm += t;
            }
            else{  // y
                tm += t + arr[1];
            }
        }
        
    }

    printf("%lld", tm);
    
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     long long light[3], N, a, b, ans = 0;
//     cin >> light[0] >> light[2] >> light[1] >> N;
//     long long sum = light[0] + light[1] + light[2];  //sum为红绿灯变换一周的总时长
//     while (cin >> a >> b)
//         if (a == 0)  //是道路
//             ans += b;  //时长直接递增
//         else {  //是红绿灯
//             if (a == 1)  //将红绿灯标号变为light数组的下标
//                 a = 0;
//             else if (a == 3)
//                 a = 1;
//             //这一句首先做的事情就是将b从剩余时间变成已经亮了多长时间
//             // + ans 好理解的方式是假设就只有一个灯
//             b = (light[a] - b + ans) % sum;  //该红绿灯变换的最后一周的时长
// 
//             while (b > light[a]) {  //若b比当前红绿灯时长长
//                 b -= light[a];  //减去当前的红绿灯时长
//                 a = (a + 1) % 3;  //转向下一个红绿灯
//             }
//             if (a == 0)  //是红灯
//                 ans += light[a] - b;  //加上红灯剩余时长
//             else if (a == 2)  //是黄灯
//                 ans += light[a] - b + light[0];  //加上黄灯剩余时长以及红灯时长
//         }
//     cout << ans;
//     return 0;
// }
