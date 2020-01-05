#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      long long int a,b,x;cin >> a >> b >> x;
      if(a == 0)cout << b / x + 1;
      else cout << b / x - (a - 1ll) / x;
}