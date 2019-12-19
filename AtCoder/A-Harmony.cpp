#include<bits/stdc++.h>
using namespace std;

int main(){
      int a;cin >> a;
      int b;cin >> b;
      if((a + b) & 1)cout << "IMPOSSIBLE";
      else cout << (a + b) / 2;
}