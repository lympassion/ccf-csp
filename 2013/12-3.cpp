/*
* description: 
*       这道题暴力求解可以AC，对于注释中的单调栈法，用了贪心的思想，
*       但是目前来说不太好理解
* Author: lympassion  
* Date:   2021/2/28
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1003];
int main(){
    int n, max_sq, width, hight;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    max_sq = 0;
    for(int i = 0; i < n; i++){
        hight = arr[i];
        for(int j = i; j < n; j++){
            width = j-i+1;
            hight = min(hight, arr[j]);
            if(max_sq < width * hight){
                max_sq = width * hight;
            }
        }
    }

    printf("%d", max_sq);
    return 0;
}

// #include <iostream>
// #include <stack>
// #include <algorithm>
// using namespace std;


// int getAnswer(int n , int* height){ //单调栈算法
//     int ans = 0;
//     stack<int> myStack ;
//     myStack.push(0); //哨兵
//     for(int i = 1 ; i <= n+1 ;){
//         if(height[myStack.top()] > height[i]){
//             int nowHeight = height[myStack.top()];
//             myStack.pop();
//             ans = max(ans,(i-myStack.top()-1)*nowHeight);
//         }
//         else
//             myStack.push(i++);
//     }
//     return ans;
// }


// int main()
// {
//     int n;
//     cin>>n ;
//     int* height = new int[n+2]();

//     for(int i = 1; i <= n ; ++i)
//         cin>>height[i];
//     cout<<getAnswer(n,height)<<endl;
//     delete[] height; 
//     return 0;
// }
