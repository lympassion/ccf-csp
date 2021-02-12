#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int N=1e8+50;
int a[N];
// map<int, bool> mp;
int main()
{
	int cnt;
	float f = 6/2.0;
	cnt = f;
	if(f == (int)f){
		printf("%f", f);
	}
	
}

// #include<iostream>
// #include<iomanip>
// using namespace std;
 
// int main(){
//     int n;
//     cin >> n;
//     int num[n];
//     for(int i = 0; i < n; i++) cin >> num[i];
//     if(num[n - 1] >= num[0]){
//         cout << num[n - 1] << " ";
//         if(n % 2 == 1){
//             cout << num[n / 2];
//         }else{
//             double mid = (num[n / 2 - 1] + num[n / 2]) / 2.0;
//             if(mid == (int)mid) cout << (int)mid;
//             else cout << fixed << setprecision(1) << mid;
//         }
//         cout << " " << num[0];
//     }else{
//         cout << num[0] << " ";
//         if(n % 2 == 1){
//             cout << num[n / 2];
//         }else{
//             double mid = (num[n / 2 - 1] + num[n / 2]) / 2.0;
//             if(mid == (int)mid) cout << (int)mid;
//             else cout << fixed << setprecision(1) << mid;
//         }
//         cout << " " << num[n - 1];
//     }
//     cout << endl;
//     return 0;
// }