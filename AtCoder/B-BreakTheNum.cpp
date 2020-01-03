#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair

int main(){
      int n;cin >> n;
      int ans = 1;
      while(ans <= n)ans = ans << 1;
      cout << (ans >> 1);
}