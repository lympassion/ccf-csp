/*
* description: 
* Author: lympassion  
* Date:   2021/2/28
*/

#include <iostream>
#include <string.h>

using namespace std;

char arr[20], ans[20];
int main(){
    int val, right, cnt;

    scanf("%s", arr);
    val = arr[12]-'0';
    right = 0;
    cnt = 1;
    for(int i = 0; i < 11; i++){
        if(arr[i] == '-'){
            continue;
        }
        else{
            right += (arr[i] - '0') * cnt;
            cnt++;
        }
    }
    right %= 11;

    if(right == val || (right==10 && val=='X'-'0')){
        printf("%s", "Right");
    }
    else{
        memcpy(ans, arr, 12);
        right = right==10 ? 40 : right;
        printf("%s%c", ans, right+'0');
    }
    return 0;
}

// #include<iostream>
// #include<string>
// using namespace std;
// int main()
// {
// 	string str;
// 	char jy;
// 	cin>>str;
// 	long long sum=0;
// 	int count=0;
// 	for(int i=0;i<11;i++)
// 	{
// 		if(str[i]>='0'&&str[i]<='9')
// 		{
// 			count++;
// 			sum=sum+(str[i]-'0')*count;
// 		}
// 	}
// 	if(sum%11==10)
// 	{
// 		jy='X';
// 	}
// 	else
// 	{
// 		jy=sum%11+'0';
// 	}
// 	if(jy==str[12])
// 	{
// 		cout<<"Right"<<endl;
// 	}
// 	else
// 	{
// 		for(int i=0;i<12;i++)
// 		{
// 			cout<<str[i];
// 		}
// 		cout<<jy<<endl;
// 	}
// 	return 0;
// }
