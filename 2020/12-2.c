# include <stdio.h>
# include <stdlib.h>


struct predict
{
    int y;
    int res;
};


struct predict pre[100005];

int m;

int cmp(const void *a, const void *b){
    // 下面这两种方式都可以，一定要注意括号，保证优先级，否则会报语法错误
    // return (*(struct predict*)a).y > (*(struct predict*)b).y;
    return ((struct predict*)a)->y > ((struct predict*)b)->y;
}

int* cal_correct(int i, int now){
    // 当flag = 1时，是要计算i=0的所有预测情况
    // 当flag = 0时，是要计算i>0的某个安全指数对应预测情况
    // cnt[0]-----相同安全指数的个数，cnt[1]----安全指数为i时，预测正确的个数
    // cnt[2]----返回j

    // 这里一定要注意static 类型的要下面再初始化，否则他的值会一直保留
    static int cnt[3];  
    cnt[0] = cnt[1] = 0;
    
    for(int j = i; j < m; j++){
        cnt[0] += 1;

        if(pre[j].y >= pre[i].y && pre[j].res != 0){
            cnt[1] += 1;
        }
        else if(pre[j].y < pre[i].y && pre[j].res == 0){
            cnt[1] += 1;
        }
        if((j==m-1) || (pre[j].y != pre[j+1].y)){
            break;
        }
        
    }
    for(int j = now; j < m; j++){
        if((j==m-1) || (pre[j].y != pre[j+1].y)){
            cnt[2] = j+1;
            break;
        }
        
    }
    return cnt;
}

int main(){
    int ans_y, ans_num, tmp_y, tmp_num, tmp_num_pre, last_ind;
    int* cnt_res = (int*) malloc(3 * sizeof(int));
    

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &pre[i].y, &pre[i].res);
    }

    qsort(pre, m, sizeof(pre[0]), cmp);

    ans_y   = tmp_y = pre[0].y;
    ans_num = 0;
    // 两遍for循环超时
    // for(int i = 0; i < m; i++){
    //     tmp_num = 0;
    //     tmp_y   = pre[i].y;  // 阙值
    //     for(int j = 0; j < m; j++){
    //         if(pre[j].y >= tmp_y && pre[j].res != 0){
    //             tmp_num += 1;
    //         }
    //         else if(pre[j].y < tmp_y && pre[j].res == 0){
    //             tmp_num += 1;
    //         }
    //     }
    //     // ans_y   = ans_num > tmp_num ? ans_y : tmp_y;  // 这里没有改变ans_num
    //     if(ans_num <= tmp_num){
    //         ans_y   = tmp_y;
    //         ans_num = tmp_num;
    //     }
    // }

    // 这个题最后发现是一道规律题 下一个不同数字a(i+1)的正确个数是现在的数字a(i)
    // 对应的正确个数 + (a(i)这个数的预测错误个数 - a(i)这个数的预测正确个数)
    // tmp_num = 0;
    for(int i = 0; i < m; i=cnt_res[2]){
        
        if(i == 0){  // 第一个单独处理
            // cnt_res = cal_correct(i, 1);
            // tmp_num = cnt_res[1];
            tmp_num = 0;
            tmp_y   = pre[i].y;  // 阙值
            for(int j = 0; j < m; j++){
                if(pre[j].y >= tmp_y && pre[j].res != 0){
                    tmp_num += 1;
                }
                else if(pre[j].y < tmp_y && pre[j].res == 0){
                    tmp_num += 1;
                }
                if(pre[j].y == pre[0].y){
                    cnt_res[2] = j+1;
                }
            }
        }
        else{
            cnt_res = cal_correct(last_ind, i);  // 这里的i-1是上一个安全指数对应的索引，而不是简单地向前推
            tmp_num = tmp_num + cnt_res[0] - 2*cnt_res[1];
        }

        if(ans_num <= tmp_num){
            ans_y   = pre[i].y;
            ans_num = tmp_num;
        }
        last_ind = i;
        // i++;
        // while ((i<m-1) && pre[i].y == pre[i+1].y)
        // {
        //     i++;
        // }
        
        // cnt_res[2] = cnt_res[2]==0 ? cnt_res[2]+1 : cnt_res[2]; // 否则再第二遍循环的时候会陷入i=1的循环
    }



    printf("%d\n", ans_y);

    return 0;
}