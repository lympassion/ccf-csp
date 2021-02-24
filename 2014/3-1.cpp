/*
* description: 
* Author: lympassion
* Date:   2021/2/24
*/

#include <iostream>

using namespace std;

int arr1[502], arr2[1003];
int main(){
    int n, ans;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
        if(arr1[i] > 0){
            arr2[arr1[i]]++;
        }
    }

    ans = 0;
    for(int i = 0; i < n; i++){
        if(arr1[i] < 0 && arr2[-arr1[i]]){
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}

// 利用set中元素不重复的特性
// # include <iostream>
// # include <set>

// using namespace std;

// set<int> a;

// int main()
// {
//     int n = 0, x;
//     cin >> n;
//     for(int i = 0; i < n; i ++) {
//         cin >> x;
//         if(x < 0) x = 0 - x;
//         a.insert(x);
//     }
//     cout << n - a.size() << endl;
//     return 0;
// }