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
        int t=line.find(' ');//���ҵ�һ���ո��ַ���λ�ã��ÿո��ַ����������ָ��������ֵ
        string s1=line.substr(0,t),s2=line.substr(t+2,line.size()-t-3);//s1�洢��������s2�洢ȥ����β"�ַ���ֵ
        strReplace[s1]=s2;//����������ֵ��Ӧ����
    }
    smatch result;
    for(string&i:html){
        auto j=i.cbegin();//����regex_search�ĵ�������Ҫ��const_iterator����
        while(regex_search(j,i.cend(),result,regex("\\{\\{ ([^\\}]+) \\}\\}"))){//���ַ����в��������ַ���ƥ��ɹ�
            for(;j!=result[0].first;++j)//����ӿ�ʼ������λ�õ�ƥ��ɹ������ַ�������ʼλ�õ������ַ�
                printf("%c",*j);
            auto k=strReplace.find(result[1]);//�鿴strReplace���Ƿ�����Ӧ�ı�����
            printf("%s",k!=strReplace.end()?(k->second).c_str():"");//�����������Ӧ��ֵ
            j=result[0].second;//����һ����ʼ����λ�ø���Ϊ��ǰƥ��ɹ������ַ�����ĩβλ��
        }
        for(;j!=i.cend();++j)//��������һ��ƥ��ɹ������ַ�����ĩβλ�õ������ַ���ĩβλ�õ������ַ�
            printf("%c",*j);
        puts("");//����
    }
    return 0;
}
