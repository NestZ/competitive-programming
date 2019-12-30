#include<bits/stdc++.h>
using namespace std;

int main(){
      long long int a,b,k;cin >> a >> b >> k;
      if(a < k){
            b -= k - a;
            a = 0;
      }
      else a -= k;
      cout << a << " " << max(0ll, b);
}