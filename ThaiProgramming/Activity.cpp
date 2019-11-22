#include<bits/stdc++.h>
using namespace std;

long long int fac(long long int s, long long int e){
      if(s <= e)return e;
      return s * fac(s - 1, e);
}

int main(){
      long long int n;cin >> n;
      if(n == 1)return cout << 2, 0;
      if(!(n & 1))cout << fac(n, (n + 1) / 2 + 1) / fac(n / 2, 1);
      else cout << 2 * (fac(n, (n + 1) / 2 + 1) / fac(n / 2, 1));
}