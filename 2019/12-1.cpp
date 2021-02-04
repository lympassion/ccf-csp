/*
* description: 
*       这道题当时自己做只做了40分，和做的好的一比较，感觉主要原因是
*       人家都是把同一个逻辑放在一个地方处理（比如一个函数里面），
*       这样每一个函数实现什么功能就很明确。而我却把
*       对于同一个变量的修改放到了一个函数里，还有这个函数的外面，这样就是
*       逻辑不清晰，直接后果就是分不清楚哪里错了。
* Author: lympassion
* Date:   2021/2/4
*/

#include <iostream>
#include <cstring>

using namespace std;

int ind;


bool val_7(int val){ 
    if(val % 7 == 0){
        return false;
    }

    while (val > 0)
    {
        if(val % 10 == 7){
            return false;
        }
        else{
            val /= 10;
        }
    }

    return true;
}

int main(){
    int n;
    int cnt[4], ans, num;

    scanf("%d", &n);

    memset(cnt, 0, sizeof(cnt[0])*4);
    ans = 0;
    num = 1;
    ind = 0;
    while (ans < n)
    {
        if(!val_7(num++)){
            cnt[ind] += 1;
        }
        else{
            ans++;
        }
        ind = (ind+1) % 4;
    }

    for(int i = 0; i < 4; i++){
        printf("%d\n", cnt[i]);
    }
    
    return 0;
}
