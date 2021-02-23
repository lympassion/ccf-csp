/*
* description: 
* Author: lympassion
* Date:   2021/2/23
*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char str[20];
    int ans, ind;

    ans = ind = 0;
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    while (str[ind] != 0)
    {
        ans += str[ind++] - '0';
    }
    
    printf("%d", ans);
    return 0;
}

