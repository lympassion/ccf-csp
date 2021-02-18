/*
* description: 
*       这道题的思路是参照网上的
*       就是因为输入的地方没有判断，所以卡了好久，最后debug发现后面的结构体内容是随机的
* Author: lympassion
* Date:   2021/2/18
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct key
{
    int tm;  // 时间标志
    int key;  // 钥匙编号
    int flag; // 0 取出   1 归还
};

// key ky[2003];
int status[1003];

bool cmp(key k1, key k2){
    if(k1.tm == k2.tm){
        if(k1.flag == k2.flag){
            return k1.key < k2.key;  // 3. 编号从小到大归还
        }
        return k1.flag > k2.flag;  // 2. 先归还再借
    }
    return k1.tm < k2.tm;  // 1. 使用时间少的先还
}


int main(){
    int n, k, w, s, c, ind;
    

    scanf("%d %d", &n, &k);
    const int K = k;
    key ky[2*K];
    for(int i = 0; i < n; i++){
        status[i]  = i+1;  // 有钥匙在钥匙盒
    }
    for(int i = 0; i < 2*k; i++){
        if(i % 2 == 0){  // 之前没有判断，所以少一半的输入，最好的方法还是用参考的代码
            scanf("%d %d %d", &w, &s, &c);
        }
        ky[i].key  = w;
        ky[i].flag = 0;
        ky[i].tm   = s;
        
        i++;
        ky[i].key  = w;
        ky[i].flag = 1;
        ky[i].tm   = s+c;
    }

    sort(ky, ky+2*k, cmp);
    for(int i = 0;i < 2*k; i++){
        ind = ky[i].key;
        if(!ky[i].flag){  // 取钥匙
            for(int j = 0; j < n; j++){
                if(status[j] == ky[i].key){
                    status[j] = 0;
                    break;
                }
            }
        }
        else{
            for(int j = 0; j < n; j++){
                if(status[j] == 0){
                    status[j] = ky[i].key;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d%c", status[i], i==n-1 ? '\n' : ' ');
    }
    return 0;
}



// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int n, k, w, s, c, key[1001];


// struct Teacher//定义教师结构体
// {
// 	int key;//钥匙编号
// 	int time;//使用钥匙时间
// 	int flag;//设置标识符
// };

// bool cmp(const Teacher& t1, const Teacher& t2)//自定义比较函数
// {
// 	if (t1.time != t2.time)//使用时间少的先还
// 	{
// 		return t1.time < t2.time;
// 	}
// 	else if (t1.flag != t2.flag)//先归还后取出
// 	{
// 		return t1.flag > t2.flag;
// 	}
// 	else//钥匙编号从小到大归还
// 	{
// 		return t1.key < t2.key;
// 	}
// }

// int main()
// {
// 	std::ios::sync_with_stdio(false);
// 	vector<Teacher> v;//定义结构体向量
// 	cin >> n >> k;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		key[i] = i;
// 	}
    
//     Teacher t;
// 	for (int i = 0; i < k; i++)
// 	{
// 		cin >> w >> s >> c;
		
// 		t.key = w;
// 		t.time = s;
// 		t.flag = 0;//设置取出标识
// 		v.push_back(t);
// 		t.key = w;
// 		t.time = s + c;
// 		t.flag = 1;//设置归还标识
// 		v.push_back(t);
// 	}
// 	sort(v.begin(), v.end(), cmp);//自定义排序
// 	for (int i = 0; i < v.size(); i++)
// 	{
// 		Teacher t = v[i];
// 		if (!t.flag)//取出钥匙
// 		{
// 			for (int j = 1; j <= n; j++)
// 			{
// 				if (key[j] == t.key)
// 				{
// 					key[j] = 0;
// 					break;
// 				}
// 			}
// 		}
// 		else//归还钥匙
// 		{
// 			for (int j = 1; j <= n; j++)
// 			{
// 				if (key[j] == 0)//找到空挂钩
// 				{
// 					key[j] = t.key;
// 					break;
// 				}
// 			}
// 		}
// 	}
// 	for (int i = 1; i <= n; i++)
// 	{
// 		cout << key[i] << " ";
// 	}
// 	cout << endl;
// 	return 0;
// }
