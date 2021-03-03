/*
* description:
*       1. 这里的scanf double的时候是scanf("%lf")
*       2. 本来想的好好的有关ans_num, num要是long long型的。结果百密一疏，把buy_num, sell_num定义成了int的
*          找了半天bug
* Author: lympassion
* Date:   2021/3/3
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct stock{
    double price;
    int num;
    char type[10];
    int flag;
};

stock stk[5003];
double arr_price[5003];

bool cmp(double a, double b){
    return a > b;
}

int main(){
    int total, pass, ind;
    long long ans_num, num, buy_num, sell_num;
    double price, ans_price;

    total = 0;
    while (scanf("%s", &stk[total].type) != EOF)  
    {
        if(stk[total].type[0] == 'c'){
            scanf("%d", &pass);
            stk[pass-1].flag = 1;
            stk[total].flag = 1;  
        }
        else{
            scanf("%lf %d", &stk[total].price, &stk[total].num);
        }
        total++;  // cancel 的这一行也要计数
    }
    
    ind = 0;
    for(int i = 0; i < total; i++){
        if(stk[i].flag != 1 && stk[i].type[0] == 'b'){
            arr_price[ind++] = stk[i].price;
        }
    }
    
    sort(arr_price, arr_price+ind, cmp);
    ans_num = 0;
    ans_price = 0;
    for(int i = 0; i < ind; i++){
        buy_num = sell_num = 0;
        price = arr_price[i];  // 假设现在的价格价格就是price
        for(int j = 0; j < total; j++){
            if(stk[j].flag != 1){  // 这里把j写成了i
                if(stk[j].type[0] == 'b' && stk[j].price >= price){
                    buy_num += stk[j].num;
                }
                else if(stk[j].type[0] == 's' && stk[j].price <= price){
                    sell_num += stk[j].num;
                }
            }
        }
        num = min(buy_num, sell_num);
        if(ans_num < num){
            ans_num = num;
            ans_price = price;
        }
    }

    printf("%.2lf %lld", ans_price, ans_num);
    return 0;
}