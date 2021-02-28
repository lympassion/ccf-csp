/*
* description: 
* Author: lympassion  
* Date:   2021/2/28
*/

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int arr[10004];

int main(){
    int n, val, max_cnt;
    set<int> s;
    set<int>::iterator it;

    scanf("%d", &n);
    max_cnt = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        s.insert(val);  // set默认从小到大排序
        arr[val]++;
        max_cnt = max(arr[val], max_cnt);
    }

    for(it = s.begin(); it != s.end(); it++){
        if(arr[*it] == max_cnt){
            printf("%d", *it);
            break;
        }
    }
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// int v[10001]={0};
// int n;
// int main()
// {
//     int a ;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         cin>>a;
//         ++v[a];
//     }
//      int maxN = 0,k = 0;
//      for(int i=0;i<10001;i++)
//         {
//             if(v[i]>maxN)
//                 {
//                     k = i;
//                     maxN = v[i];
//                 }
//         }
//         cout<<k;
//     return 0;
// }