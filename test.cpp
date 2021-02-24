#include <iostream>
#include <algorithm>

using namespace std;

struct info
{
    int cnt;
    int val;
};

info info1[1003];

int main(){
    int cnt = 0;

    for(int i = 0; i < 1003; i++){
        if(info1[i].cnt != 0 || info1[i].val != 0){
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}