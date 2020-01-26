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

int c(int x){
    if(x == 0)return 0;
    return c(x >> 1) + (x & 1);
}

int main(){
    int n;cin >> n;
    int a[n + 5];
    int x[n + 5][n + 5];
    int y[n + 5][n + 5];
    for(int i = 0;i < n;i++){
        cin >> a[i];
        for(int j = 0;j < a[i];j++){
            cin >> x[i][j] >> y[i][j];
        }
    }
    int ans = 0;
    for(int b = 1;b < (1 << n);b++){
        bool flag = true;
        for(int i = 0;i < n;i++){
            if(b & (1 << i)){
                for(int j = 0;j < a[i];j++){
                    if(((b >> (x[i][j] - 1)) & 1) ^ y[i][j])flag = false;
                }
            }
        }
        if(flag)ans = max(ans, c(b));
    }
    cout << ans;
}