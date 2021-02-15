/*
* description: 
*       不管是多简单的题，还是老老实实把测试样例走一遍
* Author: lympassion
* Date:   2021/2/15
*/

#include <iostream>

using namespace std;

int main(){
    int n, ans, n_last, score_last;

    n          = 1;
    ans        = 0;
    n_last     = 0;
    score_last = 0;
    while (n)
    {
        scanf("%d", &n);
        if(n == 2){
            if(n_last<=1){
                ans += 2;
                score_last = 2;
            }
            else{
                ans += score_last + 2;
                score_last += 2;
            }
        }
        else if(n){
            ans += 1;
            score_last = 1;
        }
        n_last = n;
    }
    
    printf("%d", ans);
    return 0;
}

// #include <iostream>
// using namespace std;
// int main(){
// 	int n=1; 	    	        //输入
// 	int sum=0;		          //总和
// 	int p=0;			     //连续的跳到中心的连续次数
// 	while(n){
// 		cin>>n;
// 		if(n==1){
// 			sum+=n;			
// 			p=0;				//连续次数清零 
// 		}
// 		else if(n==2){
// 			++p;
// 			sum+=2*p;
// 		}
// 	 }
// 	 cout<<sum;
// 	return 0;
// } 