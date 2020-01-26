#include<bits/stdc++.h>
using namespace std;
// make pair, tuple
// __gcd(int, int)
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

int main(){
    long long int n;cin >> n;
    long long int ans = INT64_MAX;
    long long int f = pow(n, 0.5);
    for(long long int i = 1ll;i <= f + 5;i++){
        if(n / i == (n + (i - 1ll)) / i){
            ans = min(ans, (n / i) - 1ll + (i - 1ll));
        }
    }
    cout << ans;
}