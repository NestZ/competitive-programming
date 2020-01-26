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
long long int v(long long int a, long long int b, long long int x){
    return a * x + b * to_string(x).length();
}

int main(){
    long long int a,b,x;
    cin >> a >> b >> x;
    long long int l = 1;
    long long int r = 1e9;
    long long int mid = (l + r) / 2;
    while(l <= r){
        mid = (l + r) / 2;
        if(v(a, b, mid) == x)return cout << mid, 0;
        else if(v(a, b, mid) > x)r = mid - 1;
        else l = mid + 1;
    }
    cout << (v(a, b, mid) > x ? mid - 1 : mid);
}