/*
* description: 
*       这道题是耗时最长并且得分最低的一道题，花费时间大概有五六个小时，但是后面不管怎么修改都是
*       只有10分，代码看着也越来越不知道如何修改了。
* Author: lympassion
* Date:   2021/2/22
*/

// 10分代码
// #include <iostream>
// #include <algorithm>

// using namespace std;


// int arr[15][10], arr2[4][4];
// int main(){
//     int n, flag1, flag2, flag3, ind1, ind2, ind3, ind4, ind5;


//     for(int i = 0; i < 15; i++){
//         for(int j = 0; j < 10; j++){
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     flag1 = flag2 = flag3 = 0;
//     for(int i = 0; i < 4; i++){
//         for(int j = 0; j < 4; j++){
//             scanf("%d", &arr2[i][j]);
//         }
//         flag1 += arr2[i][0];
//     }
//     scanf("%d", &n);

//     // if(!flag1){
//     //     n -= 1;
//     // }
//     n -= 1; 

//     ind1 = 12;
//     for(int i = 1; i < 12; i++){
//         for(int j = 0; j < 4; j++){
//             for(int k = n; k < n+4; k++){
//                 if(arr[j+i][k]*arr2[j][k] == 1){  
//                     ind1 = j+i;
//                     flag3 = 1;
//                     break;
//                 }
//             }
//             if(flag3){
//                 break;
//             }
//         }
//         if(flag3){
//             break;
//         }
//     }

//     flag2 = 0;
//     ind3 = ind4 = 0;
//     if(ind1 == 12){  // 处理多余的0
//         ind5 = 0;
//         for(int i = 3; i > -1; i--){
//             for(int j = 0; j < 4; j++){
//                 flag2 += arr[i][j];
//             }
//             if(!flag2){
//                 ind5 = 4-i;  // 几行为0
//                 break;
//             }
//         }
//         for(int i = 11+ind5; i < 15; i++){
//             ind4 = 0;  // 这个地方要记得清0
//             for(int j = n; j < n+4; j++){
//                 arr[i][j] = arr2[ind3][ind4] ? arr2[ind3][ind4] : arr[i][j];  // 这里的替换
//                 ind4++;
//             }
//             ind3++;
//         }
//     }

//     else{
//         for(int i = ind1-1; i < min(ind1+3, 15); i++){
//             ind4 = 0;  // 这个地方要记得清0
//             for(int j = n; j < n+4; j++){
//                 arr[i][j] = arr2[ind3][ind4] ? arr2[ind3][ind4] : arr[i][j];  // 这里的替换
//                 ind4++;
//             }
//             ind3++;
//         }
//     }

//     for(int i = 0; i < 15; i++){
//         for(int j = 0; j < 10; j++){
//             printf("%d%c", arr[i][j], j==9 ? '\n' : ' ');
//         }
//     }
//     return 0;
// }


// 满分代码
#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a[15][10];
	int b[4][4];
	int start;
	int upborder[4]={14,14,14,14},lowborder[4]={-10,-10,-10,-10};
	for(int i=0;i<15;i++)
		for(int j=0;j<10;j++)
			cin>>a[i][j];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			cin>>b[i][j];
	cin>>start;
	start=start-1;
	for(int i=start;i<start+4;i++)     //原始数组的上界 
		for(int j=0;j<15;j++)
			if(a[j][i]==1)
			{
				upborder[i-start]=j-1;
				break;
			}
	for(int i=0;i<4;i++)         //输入数组的下界 
		for(int j=0;j<4;j++)
			if(b[j][i]==1)
				lowborder[i]=j;
	int minx(20);
	int t(0);
	for(int i=0;i<4;i++)    //对比得最小距离 
		if(upborder[i]-lowborder[i]<minx)
		{//标记最短距离
			minx=upborder[i]-lowborder[i];
			t=i;
		}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(b[i][j]==1)//标记
				a[upborder[t]-lowborder[t]+i][start+j]=1;  // 这里挺难理解的
	for(int i=0;i<15;i++)
	{//输出
		for(int j=0;j<10;j++)
		{
			if(j==0)
				cout<<a[i][j];
			else
				cout<<" "<<a[i][j];
		}	
		cout<<endl;
	}
	return 0;
}

