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
    int n;cin >> n;
    long long int a[n + 5];
    long long int b[n + 5];
    long long int ans = 0;
    for(int i = 0;i < n + 1;i++)cin >> a[i];
    for(int i = 0;i < n;i++)cin >> b[i];
    for(int i = 0;i < n;i++){
        ans += min(a[i], b[i]);
        if(b[i] > a[i]){
            ans += min(a[i + 1], b[i] - a[i]);
            a[i + 1] = max(0ll, a[i + 1] - (b[i] - a[i]));
        }
    }
    cout << ans;
}