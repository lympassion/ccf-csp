#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
const int N=1e8+50;
int a[N];
// map<int, bool> mp;
int main()
{
	int cnt;
	cnt = 5;
	
	switch(cnt){
		case 5:
			printf("sfas\n");
			cnt++;
		default:
			cnt += 3;
			cnt *= 2;
	}
	printf("%d", cnt);
}

