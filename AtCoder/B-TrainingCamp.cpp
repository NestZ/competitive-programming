#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      long long int n;cin >> n;
      long long int i = 1;
      long long int ans = 1;
      while(i <= n){
            ans = ans % ((long long int)1e9 + 7) * i;
            i++;
      }
      cout << ans % ((long long int)1e9 + 7);
}