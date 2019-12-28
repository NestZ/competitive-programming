#include<bits/stdc++.h>
using namespace std;

int main(){
      int d,n;cin >> d >> n;
      int s = 1;for(int i = 0;i < d;i++)s *= 100;
      if(n < 100)cout << n * s;
      else cout << 101 * s;
}