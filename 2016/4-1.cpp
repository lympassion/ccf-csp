/*
* description: 
* Author: lympassion
* Date:   2021/2/21
*/

#include <iostream>
#include <algorithm>

using namespace std;


int arr[1003];

int main(){
    int n, ans;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    ans = 0;
    for(int i = 1; i < n-1; i++){
        if(arr[i] > max(arr[i-1], arr[i+1]) || arr[i] < min(arr[i-1], arr[i+1])){
            ans++;
        }
    }

    printf("%d", ans);
    return 0;
}

// #include<iostream>
// using namespace std;
// int a[1000]={0},b[1000]={0};
// int main()
// {
// 	int i,sum=0,n;
// 	cin>>n;
// 	for(i=0;i<n;i++)
// 	{
// 		cin>>a[i];
// 	}
// 	for(i=0;i<n;i++)
// 	{
// 		b[i]=a[i+1]-a[i];
// 	}
// 	for(i=0;i<n-2;i++)
// 	{
// 		if(b[i]*b[i+1]<0)
// 		{
// 			sum++;
// 		}
// 	}
// 	cout<<sum;
// 	return 0;
// }