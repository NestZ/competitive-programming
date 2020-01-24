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
    int n,m;cin >> n >> m;
    int mi[n + 5];
    int wc[n + 5];
    for(int i = 0;i < n + 5;i++){
        mi[i] = 0;
        wc[i] = 0;
    }
    int ac = 0;
    int wa = 0;
    for(int i = 0;i < m;i++){
        int t;cin >> t;
        string s;cin >> s;
        if(s == "WA" && mi[t] == 0){
            wc[t]++;
        }
        else if(s == "AC" && mi[t] == 0){
            ac++;
            wa += wc[t];
            mi[t] = 1;
        }
    }
    cout << ac << " " << wa;
}