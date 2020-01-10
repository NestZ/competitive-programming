#include<bits/stdc++.h>
using namespace std;
// size_t f = string::npos
// make pair, tuple
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

int main(){
      long long int a,b;cin >> a >> b;
      long long int x = min(a, b);
      long long int y = max(a, b);
      long long int c = x;
      long long int p = 2;
      while(c % x != 0 || c % y != 0){
            c = x * p++;
      }
      cout << c;
}