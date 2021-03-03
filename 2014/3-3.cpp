/*
* description: 
* Author: lympassion
*       stringstream的用法，很好地解决了不定长度且带有空格的问题  
* Date:   2021/3/3
*/

#include <iostream>
#include <string.h>
#include <sstream>  // stringstream

using namespace std;

int with_opts[27];
int ans_opts[27];
string ans_args[27];  // 而不是char 
 
int main(){
    string str, cmd, opt, arg;
    char opts[53];
    int n, ind;

    scanf("%s", opts);
    int tmp = strlen(opts);
    for(int i = 0; i < strlen(opts);){
        if(opts[i+1]==':'){
            with_opts[opts[i]-'a'] = 2;
            i+=2;
        }
        else{
            with_opts[opts[i]-'a'] = 1;
            i++;
        }
    }

    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        getline(cin, str);
        stringstream stream;
        stream.str(str);
        stream >> cmd;
        while (stream >> opt)
        {
            if(opt.length() != 2 || (opt[0] != '-' || (opt[1]<'a' || opt[1] > 'z'))){
                break;
            }
            else{
                ind = opt[1] - 'a';
                if(with_opts[ind] == 2){
                    // stream >> arg;
                    if(stream >> arg){  // 还要验证是否带有参数
                        ans_args[ind] = arg;
                        ans_opts[ind] = ind+1;
                    }
                    else{
                        break;
                    }
                }
                else if(with_opts[ind] == 1){
                    ans_opts[ind] = ind+1;
                }
                else{
                    break;
                }
            }
        }

        printf("Case %d: ", i+1);
        for(int i = 0; i < 26; i++){
            if(ans_opts[i]){
                if(with_opts[i] == 2){
                    printf("-%c %s ", ans_opts[i]+'a'-1, ans_args[i].c_str());  // 不用c.str会乱码
                    // cout << ans_args[i] << ' ';
                }
                else if(with_opts[i] == 1){
                    printf("-%c ", ans_opts[i]+'a'-1);
                }
            }
            
        }
        printf("%c", '\n');
        memset(ans_opts, 0, sizeof(ans_opts));
    }
    
    return 0;
}