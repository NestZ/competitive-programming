#include<bits/stdc++.h>
using namespace std;
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

int main(){
    long long int MOD = 1e9 + 7;
    int n,m;cin >> n >> m;
    vector<long long int> dp(n + 5, 0);
    vector<bool> v(n + 5, true);
    dp[0] = 1;
    for(int i = 0;i < m;i++){
        int t;cin >> t;
        v[t] = false;
    }
    for(int i = 1;i <= n;i++){
        if(!v[i])continue;
        if(i - 1 >= 0)dp[i] += dp[i - 1];
        if(i - 2 >= 0)dp[i] += dp[i - 2];
        dp[i] %= MOD;
    }
    cout << dp[n];
}