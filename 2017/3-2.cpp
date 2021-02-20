/*
* description: 
* Author: lympassion
* Date:   2021/2/20
*/

#include <iostream>
#include <list>

using namespace std;


int main(){
    int n, m, p, q, q_abs, cnt;

    scanf("%d%d", &n, &m);
    list<int>ls;
    list<int>::iterator it;
    for(int i = 1; i <= n; i++){
        ls.push_back(i);
    }

    while (m--)
    {
        scanf("%d%d", &p, &q);
        for(it = ls.begin(); it != ls.end(); it++){
            if(*it == p){
                it = ls.erase(it);  // 一定要将返回值赋给it，否则it随机值
                // ls.insert(it+q, p);
                advance(it, q);  // 非随机访问存储器（ls[i]不支持）不能it+q
                ls.insert(it, p);
                break;
            }
        }
    }

    cnt = 0;
    for(it = ls.begin(); it != ls.end(); it++){
        cnt++;
        printf("%d%c", *it, cnt==n ? '\n' : ' ');
    }
    
    return 0;
}