/*
* description:
* Author: lympassion
*       scanf不支持任何c++的class, 如scanf("%s", sring)
*       这道题想着用正则表达式来做要合理一些，只是自己之前几乎没怎么用过，就借鉴了网上的使用正则表达式的题解
* Date:   2021/3/5
*/

// #include <iostream>
// #include <unordered_map>
// #include <string>
// #include <regex>

// using namespace std;

// int main(){
//     int m, n, ind;
//     string name, value, var, line;
//     unordered_map<string, string>mp;
//     vector<string>html;

//     scanf("%d %d", &m, &n);
//     for(int i = 0 ; i < m; i++){
//         getline(cin, line);
//         html.push_back(line);
//     }
//     for(int i = 0; i < n; i++){
//         getline(cin, line);
//         ind = line.find(' ');
//         name = line.substr(0, ind);
//         value = line.substr(ind+2, line.length()-ind-3);
//         mp[name] = value;
//     }

//     smatch res;
//     for(string &i: html){
//         auto cha = i.begin();  // auto类型 cha其实是一个指向字符的指针
//         regex ex("\\{\\{ [0-9a-zA-Z_]{1,} \\}\\}");  // C++转义字符要使用"\\"
//         while (regex_search(cha, i.end(), res, ex))
//         {
//             for(; cha != res[0].first; cha++){
//                 printf("%c", *cha);
//             }
//             auto k = mp.find(res[1]);
//             printf("%s", k != mp.end() ? (k->second).c_str() : "");
//             cha = res[0].second;
//         }
//         for(; cha != i.end(); cha++){
//             printf("%c", *cha);
//         }
//         printf("%c", '\n');
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    scanf("%d%d%*c",&m,&n);
    vector<string>html;
    string line;
    while(m--){
        getline(cin,line);
        html.push_back(line);
    }
    unordered_map<string,string>strReplace;
    while(n--){
        getline(cin,line);
        int t=line.find(' ');//查找第一个空格字符的位置，该空格字符可以用来分割变量名和值
        string s1=line.substr(0,t),s2=line.substr(t+2,line.size()-t-3);//s1存储变量名，s2存储去除首尾"字符的值
        strReplace[s1]=s2;//将变量名和值对应起来
    }
    smatch result;
    for(string&i:html){
        auto j=i.cbegin();//传入regex_search的迭代器需要是const_iterator类型
        while(regex_search(j,i.cend(),result,regex("\\{\\{ ([^\\}]+) \\}\\}"))){//在字符串中查找有子字符串匹配成功
            for(;j!=result[0].first;++j)//输出从开始搜索的位置到匹配成功的子字符串的起始位置的所有字符
                printf("%c",*j);
            auto k=strReplace.find(result[1]);//查看strReplace中是否有相应的变量名
            printf("%s",k!=strReplace.end()?(k->second).c_str():"");//输出变量名对应的值
            j=result[0].second;//将下一个开始搜索位置更新为当前匹配成功的子字符串的末尾位置
        }
        for(;j!=i.cend();++j)//输出从最后一个匹配成功的子字符串的末尾位置到整个字符串末尾位置的所有字符
            printf("%c",*j);
        puts("");//换行
    }
    return 0;
}
