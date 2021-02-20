/*
* description: 
*       这一个得分为90
* Author: lympassion
* Date:   2021/2/21
*/

#include <iostream>

using namespace std;

int arr2[20][6], ans[500];

int main(){
    int n, ind1, ind2, val, cnt, ind_ans;

    scanf("%d", &n);
    ind_ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        ind1 = 0;
        cnt = 0;
        while (ind1 < 20 && 5-arr2[ind1][0] < val)
        {
            ind1++;
        }

        
        if(ind1 == 20){
            for(int j = 0; j < 20 && cnt < val; j++){
                for(int k  = 1; k < 6; k++){
                    if(!arr2[j][k]){
                        arr2[j][k] = 1;
                        arr2[j][0] += 1;
                        cnt++;
                        ans[ind_ans++] = (j+1) * 5 + k;
                    }
                    if(cnt == val){
                        break;
                    }
                }
            }
        }
        else{
            arr2[ind1][0] += val;
            ind2 = 1;
            while (arr2[ind1][ind2])
            {
                ind2++;
            }
            
            for(; cnt < val; cnt++){
                arr2[ind1][ind2+cnt] = 1;
                ans[ind_ans++] = ind1 * 5 + ind2 + cnt;
            }
        }
        ans[ind_ans++] = -1; 
    }

    for(int i = 0; i < ind_ans; i++){
        if(ans[i] == -1){
            continue;
        }
        printf("%d%c", ans[i], ans[i+1]==-1 ? '\n' : ' ');
    }
    return 0;
}