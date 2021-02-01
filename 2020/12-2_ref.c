#include <stdio.h>
#include <stdlib.h>

#define maxn 100005


struct node
{
    int x,y;
} s[maxn];
struct node1
{
    int x,y,a,b,sum;
} s1[maxn];

int cmp(const void* t1,const void* t2)
{
    return (*(struct node*)t1).x<(*(struct node*)t2).x;
}
int cmp1(const void* t1, const void* t2)
{
    if((*(struct node1*)t1).sum==(*(struct node1*)t2).sum)
        return (*(struct node1*)t1).x<(*(struct node1*)t2).x;
    return (*(struct node1*)t1).sum<(*(struct node1*)t2).sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&s[i].x,&s[i].y);
    }
    qsort(s+1,n, sizeof(s[0]), cmp);
    int k=1;
    s1[k].x=s[1].x;
    if(s[1].y==1)
        s1[k].b++;
    else
        s1[k].a++;
    for(int i=2; i<=n; i++)
    {
        if(s[i].x==s1[k].x)
        {
            if(s[i].y==1)
                s1[k].b++;
            else
                s1[k].a++;
        }
        else
        {
            k++;
            s1[k].x=s[i].x;
            if(s[i].y==1)
                s1[k].b++;
            else
                s1[k].a++;
        }
    }
    int a=0;
    int b=0;
    int sum=0;
    for(int i=1; i<=k; i++)
    {
        sum+=s1[i].a;
        s1[i].a=sum;
    }
    sum=0;
    for(int i=k; i>=1; i--)
    {
        sum+=s1[i].b;
        s1[i].b=sum;
    }
    s1[0].a=0;
    for(int i=1; i<=k; i++)
        s1[i].sum=s1[i-1].a+s1[i].b;
    qsort(s1+1,k,sizeof(s1[0]), cmp1);

    printf("%d\n",s1[k].x);
    return 0;
}

