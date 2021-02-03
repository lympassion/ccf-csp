/*
* description:
*    刚开始做的一道题，用时一天半
*    起初思路是两层for循环，但显然会超时（50分），如果是根据https://blog.csdn.net/qq_40763929/article/details/86726906
*    然后推导觉得当排序完成之后在相邻的两个数据之间做文章，但是考虑的比较复杂，就很难调bug（20分）
*    参考12-2_ref.cpp，改正过来依然是20分。
* Author: lympassion
* Date:   2021/2/2
*/

# include <stdio.h>
# include <stdlib.h>


struct predict
{
    int y;
    int res;
};

struct threshold
{
    int y;
    int pass, not_pass;  // 分别表示通过人数与不通过人数
    int sum;  // 表示正确预测人数
};


struct predict pre[100005];
struct threshold thrs[100005];

int m;

int cmp(const void *a, const void *b){
    // 下面这两种方式都可以，一定要注意括号，保证优先级，否则会报语法错误
    // return (*(struct predict*)a).y > (*(struct predict*)b).y;
    return ((struct predict*)a)->y > ((struct predict*)b)->y;
}

int cmp1(const void* a, const void* b){
    struct threshold thrs1 = *(struct threshold*)a; 
    struct threshold thrs2 = *(struct threshold*)b;

    if(thrs1.sum == thrs2.sum){
        return thrs1.y > thrs2.y; 
    }
    return thrs1.sum - thrs2.sum;
}


void rec_grade(int i, int k){
    if(pre[i].res == 0){
        thrs[k].not_pass++;
    }
    else{
        thrs[k].pass++;
    }
}



int main(){
    int m, k, grade_sum;

    scanf("%d", &m);
    
    for(int i = 0; i < m; i++){
        scanf("%d %d", &pre[i].y, &pre[i].res);
    }

    qsort(pre, m, sizeof(pre[0]), cmp);

    
    // 将相同安全系数的放到一起，统计该安全系数对应考试情况
    k = 0;
    thrs[0].y = pre[0].y;
    rec_grade(0, 0);
    for(int i = 1; i < m; i++){
        if(pre[i].y == thrs[k].y){
            rec_grade(i, k);
        }
        else{
            k++;
            thrs[k].y = pre[i].y;
            rec_grade(i, k);
        }
    }


    // grade_sum---记录比自己小的不合格，比自己大的合格
    grade_sum = 0;
    for(int i = 0; i <= k; i++){
        grade_sum += thrs[i].not_pass;
        thrs[i].not_pass = grade_sum;
    }
    grade_sum = 0;
    for(int i = k; i >= 0; i--){
        grade_sum += thrs[i].pass;
        thrs[i].pass = grade_sum;
    }
    
    for(int i = 0; i <= k; i++){
        if(i == 0){
            thrs[i].sum = thrs[i].pass;
        }
        else{
            thrs[i].sum = thrs[i-1].not_pass + thrs[i].pass;
        }
    }

    // 这里的个数写成了k，排序错误，这个bug要注意
    // qsort(thrs, k, sizeof(thrs[0]), cmp1);


    qsort(thrs, k+1, sizeof(thrs[0]), cmp1);
    printf("%d\n", thrs[k].y);

    return 0;
}