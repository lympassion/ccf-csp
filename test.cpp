#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> v(m);
    for(int i = 1 ; i <= m ; i++){
        v[i-1] = i;
    }

    for(int i = 0 ; i < n ; i++){
        int x,w;
        vector<int>::iterator it;
        cin>>x>>w;
        for(it = v.begin() ; it != v.end() ; it++){
            if(*it == x){
                break;
            }
        }
        v.erase(it);
        v.insert(it+w,x);   
    }

    cout<<v[0];
    for(int i = 1 ; i < m ; i++){
        cout<<" "<<v[i];
    }

    return 0;
 } 