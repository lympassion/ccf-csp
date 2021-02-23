#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a[15][10];
	int b[4][4];
	for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            b[i][j] = i+j;
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            b[i][j] = i ? i : ;
        }
    }
	return 0;
}