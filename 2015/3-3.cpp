/*
* description:
*       这一道题看似不难，但实际上做了很久，而且没拿到满分，最后发现是经过一个闰月之后month[1] 恒为29了。
*       从一开始就应该画一个简单的日历
* Author: lympassion
* Date:   2021/3/5
*/

#include <iostream>

using namespace std;

bool leapyear(int a){
    bool flag = false;
    if(a % 400 == 0 || (a % 100 != 0 && a % 4 == 0)){
        flag = true;
    }
    return flag;
}

int main(){
    int a, b, c, y1, y2, cnt, day, cnt_date, cnt_month, bgn_year;
    int month[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    int days[7] = {
        1, 2, 3, 4, 5, 6, 7
    };

    scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2);
    cnt = 0;
    bgn_year = 1850;
    for(int i = bgn_year; i < y1; i++){
        cnt += leapyear(i) ? 366 : 365;
    }

    for(int i = y1; i <= y2; i++){
        cnt_month = 0;
        // if(leapyear(i)){  // 出错点
        //     month[1] = 29;
        // }
        month[1] = leapyear(i) ? 29 : 28;
        for(int j = 0; j < a-1; j++){
            cnt_month += month[j];
        }
        day = days[(cnt+cnt_month)%7]; // a月1日的前一天是星期几
        // day=(b-1)*7+((weekd>=c)?(c+7-weekd):(c-weekd));
        if(c > day){
            cnt_date = (b-1) * 7 + c - day;
        }
        else{
            cnt_date = (b-1) * 7 + 7 - day + c;  // 在这一个月的哪一天
        }
        
        if(cnt_date <= month[a-1]){
            printf("%d/%02d/%02d", i, a, cnt_date);
        }
        else{
            printf("none");
        }
        printf("\n");
        cnt += leapyear(i) ? 366 : 365;
    }
    return 0;
}


// #include <iostream>
// using namespace std;
// int m[2][13]={{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
// {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
// int leapyear(int year)
// {
//     return (year%4==0&&year%100!=0)||year%400==0;
// }

// int main()
// {
//     int i,j,a,b,c,y1,y2,weekd,day,y,days,data;
//     cin>>a>>b>>c>>y1>>y2;
//     //计算1850年到起始年的天数
//     for(days=0,i=1850;i<y1;i++)
//         days+=365+leapyear(i);
//     //计算年月日并且输出
//     for(i=y1;i<=y2;i++)
//     {
//         //0为非闰年,1为闰年
//         y=leapyear(i);
//         //计算从1850年开始,到i年a月1日的天数
//         for(data=days,j=1;j<a;j++)
//             data+=m[y][j];
//         // 计算i年a月1日的前一天为星期几
//         weekd=1+data%7;
//         // 计算i年的a月第b个星期c是当月的几号
//         day=(b-1)*7+((weekd>=c)?(c+7-weekd):(c-weekd));
//         if(day>m[y][a])
//             cout<<"none"<<endl;
//         else
//         {
//             cout<<i<<"/";
//             if(a<10)
//                 cout<<"0";
//             cout<<a<<"/";
//             if(day<10)
//                 cout<<"0";
//             cout<<day<<endl;
//         }
//         // 为计算下一年做准备：计算从1850年到下一年开始的天数
//         days+=365+leapyear(i);
//     }
//     return 0;
// }