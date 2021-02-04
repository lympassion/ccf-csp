/*
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
};
typedef struct vector vec;
vec vec1[N], vec2[N];

int main(){
    ios::sync_with_stdio(false);
    int n, a, b;
    int ind_i, ind_j;
    long long ans;
    cin >> n >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> vec1[i].index >> vec1[i].value;
    }
    for(int i = 0; i < b; i++){
        cin >> vec2[i].index >> vec2[i].value;
    }
    ans = 0;
    ind_i = ind_j = 0;
    while (ind_i<a && ind_j<b)
    {
        if(vec1[ind_i].index == vec2[ind_j].index){
                ans += vec1[ind_i].value * vec2[ind_j].value;
                ind_i++;
                ind_j++;
            }
        else if(vec1[ind_i].index < vec2[ind_j].index){
            ind_i++;
        }
        else{
            ind_j++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}