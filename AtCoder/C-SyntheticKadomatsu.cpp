#include<bits/stdc++.h>
using namespace std;

int n, A, B, C;
vector<int> l;

int dfs(int curr, int a, int b,int c){
	if(curr == n){
		return min({a, b, c}) > 0 ?
		abs(a - A) + abs(b - B) + abs(c - C) - 30 : 1e9 + 5;
	}
	int res1 = dfs(curr + 1, a, b, c);
	int res2 = dfs(curr + 1, a + l[curr], b, c) + 10;
	int res3 = dfs(curr + 1, a, b + l[curr], c) + 10;
	int res4 = dfs(curr + 1, a, b, c + l[curr]) + 10;
	return min({res1, res2, res3, res4});
}

int main(){
	cin >> n >> A >> B >> C;
	l.resize(n);
	for(int i = 0;i < n;i++)cin >> l[i];
	cout << dfs(0, 0, 0, 0);
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
