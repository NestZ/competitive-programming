#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin >> n >> m;
	vector<vector<int>> v;
	vector<int> p;
	int ans = 0;
	for(int i = 0;i < m;i++){
		int k;cin >> k;
		vector<int> vt;
		for(int j = 0;j < k;j++){
			int t;cin >> t;
			vt.push_back(t);
		}
		v.push_back(vt);
	}
	for(int i = 0;i < m;i++){
		int t;cin >> t;
		p.push_back(t);
	}
	for(int i = 0;i < (1 << n);i++){
		bool flag = true;
		int ind = 0;
		for(vector<int> vv : v){
			int cnt = 0;
			for(int j : vv){
				if((1 << (j - 1)) & i)cnt++;
			}
			if((cnt & 1) != (p[ind] & 1)){
				flag = false;
				break;
			}
			ind++;
		}
		if(flag)ans++;
	}
	cout << ans;
}
// make pair, tuple
// make pair, tuple
// 
// __gcd(int, int);
// lcm = a * b / __gcd(a, b);
// 
// bool isPrime(int n){
//       if(n <= 1)return false;
//       if(n <= 3)return true;
//       if(n % 2 == 0 || n % 3 == 0)return false;
//       for(int i = 5;i * i <= n;i += 6){
//             if(n % i == 0 || n % (i + 2) == 0)return false;
//       }
//       return true;
// }
// int countSubString(string s, string temp){
//       int ans = 0;
//       size_t f = s.find(temp);
//       while(f != string::npos){
//             ans++;
//             f = s.find(temp, f + 1);
//       }
//       return ans;
// }
// 
// #Count leading & trailing zero of an integer bits
// __builtin_clz(n);
// __builtin_clzll(n);
//
// #Count 1s bits of an integer
// __builtin_popcount(n);
// __builtin_popcountll(n);
//
// #Error checking
// assert(n == 3);
// 
// #Error Printing
// cerr << "Some thing";

// #binary exponentiation
// long long binpow(long long a, long long b) {
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a;
//         a = a * a;
//         b >>= 1;
//     }
//     return res;
// }
