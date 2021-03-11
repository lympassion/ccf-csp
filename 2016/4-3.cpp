/*
* description:
* Author: lympassion
*       这个题自己写的得了60分，
*       网上的题解用了stl中的vector，并且最重要的是就是路径统一，如果不是绝对路径，那就用当前路径+输入路径；否则就是
*       绝对路径，还有一点是要注意录入方法getline()
* Date:   2021/3/11
*/

// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     int p, ind, len;
//     // char curr_path[1003], path[1003], ans_path[2003];
//     string curr_path, path, ans_path;

//     scanf("%d", &p);
//     // scanf("%s", curr_path);  // scanf 不支持任何class的输入
//     cin >> curr_path;  // 正规化之后的路径
//     while (p--)
//     {
//         cin >> path;
//         len = path.length();
//         ans_path = curr_path;
//         for(int i = 0; i < len;){
//             if(i == 0 && path[0] == '/'){  // 以 / 开头
//                 ind = path.find(".");
//                 if(ind == -1){
//                     ans_path = path;
//                     break;
//                 }
//                 ans_path = path.substr(0, ind);
//                 i = ind;
//             }
//             else if(i < len-1 && path[i] == '.' && path[i+1] == '.'){  // 遇到 ..
//                 if(ans_path.length() > 1 && ans_path[ans_path.length()-1] == '/'){
//                     ans_path = ans_path.substr(0, ans_path.length()-1);
//                 } 
//                 ind = ans_path.rfind("/");
//                 ans_path = ans_path.substr(0, ind+1);
//                 i += 3;
//             }
//             else if(path[i] == '.'){  // 遇到 .
//                 i += 2;
//             }
//             else if(i < len-1 && path[i] == '/' && path[i+1] != '/'){  // 遇到 /
//                 ans_path += '/';
//                 i++;
//             }
//             else{
//                 ans_path += path[i];
//                 i++;
//             }
//         }
//         for(ind = ans_path.length()-1; ind > 0; ind--){
//             if(ans_path[ind] != '/'){
//                 break;
//             }
//         }
//         ans_path = ans_path.substr(0, ind+1);
//         printf("%c", ans_path[0]);
//         for(int i = 1; i < ans_path.length(); i++){
//             if(ans_path[i] == '/' && ans_path[i-1] == '/'){
//                 continue;
//             }
//             printf("%c", ans_path[i]);
//         }
//         printf("%c", '\n');
//     }
    
//     return 0;
// }

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string curr_path, path;
vector<string>v;
int main(){
    int p;
    string s;

    scanf("%d", &p);
    cin >> curr_path;
    getchar();
    while (p--)
    {
        // cin >> path;
        getline(cin, path);  // 一定要用这个方式录入，因为有可能输入的路径都是几个空格，而上面的方式输出是错误的
        v.clear();
        if(path[0] != '/'){  // 将路径统一
            path = curr_path + '/' + path;
        }
        for(int i = 0; i < path.length(); i++){  // 方便后面用stringstream
            if(path[i] == '/'){
                path[i] = ' ';
            }
        }
        stringstream ss;
        ss.str(path);
        while (ss >> s)
        {
            if(s == "."){
                continue;
            }
            else if(s == ".."){
                if(!v.empty()){
                    v.pop_back();
                }
            }
            else{
                v.push_back(s);
            }
        }
        
        printf("/");
        for(int i = 0; i < v.size(); i++){
            printf("%s", v[i].c_str());
            if(i != v.size()-1){
                printf("%c", '/');
            }
        }
        printf("%c", '\n');
    }
    
    return 0;
}