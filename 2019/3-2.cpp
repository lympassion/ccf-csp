/*
* description: 
*       1. 再解这一道题的时候，特意了解了一下%的运算规则，并且除了python代表取模(商向负无穷方向舍入)，
*          其它语言的这个都代表着取余(商向0方向舍入)。
* Author: lympassion
* Date:   2021/2/14
*/

#include <iostream>
#include <list>

using namespace std;


int main(){
    int n, val1, val2;
    char cha[8], cha_tmp;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", &cha);
        list<int>  num;
        list<char> op;

        for(int i = 0; i < 7; i++){
            if(i%2 == 1){
                if(cha[i] == 'x'){
                    // val1 = (cha[i-1]-'0') * (cha[++i]-'0');  逻辑错误
                    val1 = num.back();
                    num.pop_back();
                    val1 *= cha[++i]-'0';
                    num.push_back(val1);
                }
                else if(cha[i] == '/'){
                    // val1 = (cha[i-1]-'0') / (cha[++i]-'0');
                    val1 = num.back();
                    num.pop_back();
                    val1 /= cha[++i]-'0';
                    num.push_back(val1);
                }
                else{
                    op.push_back(cha[i]);
                }
            }
            else{
                num.push_back(cha[i]-'0');
            }
        }
        while (!op.empty())
        {
            cha_tmp = op.front();
            op.pop_front();
            val1 = num.front();
            num.pop_front();
            val2 = num.front();
            num.pop_front();
            if(cha_tmp == '+'){
                num.push_front(val1 + val2);
            }
            else{
                num.push_front(val1 - val2);
            }
        }
        printf("%s\n", num.front()==24 ? "Yes" : "No");
    }
    
    for(int i = 0; i < -1; i++){
        printf("%d\n", n);
    }
    return 0;
}