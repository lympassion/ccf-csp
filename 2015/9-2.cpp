/*
* description: 
*       我每次遇到这用的题，都是用总的和减去给的数量
*       但网上的解法都是用给的数量减去总的和
* Author: lympassion
* Date:   2021/2/23
*/

#include <iostream>

using namespace std;


int main(){
    int year, cnt, ind, month, day;
    int cnt_arr[12];
    int arr[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    scanf("%d%d", &year, &cnt);
    if(year % 400 == 0){
        arr[1] = 29;
    }
    else{
        if(year % 4 == 0 && year % 100 != 0){
            arr[1] = 29;
        }
    }

    cnt_arr[0] = arr[0];
    ind = 0;
    while (cnt_arr[ind] < cnt)
    {
        ind++;
        cnt_arr[ind] = arr[ind] + cnt_arr[ind-1];
    }

    month = ind+1;
    if(ind){
        day = cnt-cnt_arr[ind-1];
    }
    else{
        day = cnt;
    }

    printf("%d\n%d", month, day);
    return 0;
}

// #include<iostream>
// using namespace std;
// int leap(int y){
// 	if((y%4==0&&y%100!=0)||y%400==0)return 1;
// 	return 0;
// }
// int main(){
// 	int y,d;
// 	cin>>y>>d;
// 	int t=leap(y);
// 	int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
// 	int b[12]={31,28,31,30,31,30,31,31,30,31,30,31};
// 	int i=0;
// 	if(t==1){
// 		while(d>0){
// 			d-=a[i];
// 			i++;
// 		}
// 		cout<<i<<endl<<d+a[i-1];
// 	}else{
// 		while(d>0){
// 			d-=b[i];
// 			i++;
// 		}
// 		cout<<i<<endl<<d+b[i-1];
// 	}
// }
