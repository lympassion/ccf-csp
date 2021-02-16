/*
* description: 
*       1. 这里要注意全局变量能够申请的空间大小，对于整型数组来说，最多为1e8
*       2. 如果要比较的不是数组，就一定要自己写cmp，与c不同，参数不能写const void*
*       3. const int N = 1e9+9; 卡了我好久，明明是动态申请的，结果就是0分，看了别人的代码，
*          是1e5+5，我改了之后就得分60，我去。
*       4. 和一个参考代码写的循环一样，但就是超时，现在尚不知道是什么原因
*       5. 后面可以AC的代码是自己写的，的60分的原因是const int N = 1e5+5;
*          改为const int N = 5e5+5;就可以AC了。
* Author: lympassion
* Date:   2021/2/4
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+5;

struct vector
{
    int index;
    int value;
}vec1[100005], vec2[100005];

// typedef struct vector vec;
// vec vec1[N], vec2[N];


// bool cmp(vector a, vector b){
//     return a.index < b.index;
// }



int main(){
    int n, a, b;
    int ind_i, ind_j;
    long long ans;

    // vec* vec1 = (vec*)malloc(sizeof(vec) * N);
    // vec* vec2 = (vec*)malloc(sizeof(vec) * N);


    scanf("%d %d %d", &n, &a, &b);

    for(int i = 0; i < a; i++){
        scanf("%d %d", &vec1[i].index, &vec1[i].value);
    }

    for(int i = 0; i < b; i++){
        scanf("%d %d", &vec2[i].index, &vec2[i].value);
    }

    // sort(vec1, vec1+a, cmp);
    // sort(vec2, vec2+b, cmp);


    ans = 0;
    ind_i = ind_j = 0;
    // while (ind_i<a && ind_j<b)
    // {
    //     if(vec1[ind_i].index == vec2[ind_j].index){
    //         ans += vec1[ind_i].value * vec2[ind_j].value;
    //         ind_i++;
    //         ind_j++;
    //     }
    //     else if(vec1[ind_i].index < vec2[ind_j].index){
    //         ind_i++;
    //     }
    //     else{
    //         ind_j++;
    //     }
    // }

    while(ind_i < a && ind_j < b){
        if(vec1[ind_i].index == vec2[ind_j].index){
            ans += vec1[ind_i].value * vec2[ind_j].value;
            ind_i++;
            ind_j++;
        }
        else if(vec1[ind_i].index < vec2[ind_j].index)
            ind_i++;
        else
            ind_j++;
    }

    // free(vec1);
    // free(vec2);

    printf("%lld\n", ans);

    return 0;
}



// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 5e5+5;
// struct vector
// {
//     int index;
//     int value;
// };
// typedef struct vector vec;
// vec vec1[N], vec2[N];
 
// int main(){
//     ios::sync_with_stdio(false);
//     int n, a, b;
//     int ind_i, ind_j;
//     long long ans;
//     cin >> n >> a >> b;
//     for(int i = 0; i < a; i++){
//         cin >> vec1[i].index >> vec1[i].value;
//     }
//     for(int i = 0; i < b; i++){
//         cin >> vec2[i].index >> vec2[i].value;
//     }
//     ans = 0;
//     ind_i = ind_j = 0;
//     while (ind_i<a && ind_j<b)
//     {
//         if(vec1[ind_i].index == vec2[ind_j].index){
//                 ans += vec1[ind_i].value * vec2[ind_j].value;
//                 ind_i++;
//                 ind_j++;
//             }
//         else if(vec1[ind_i].index < vec2[ind_j].index){
//             ind_i++;
//         }
//         else{
//             ind_j++;
//         }
//     }
//     printf("%lld\n", ans);
//     return 0;
// }