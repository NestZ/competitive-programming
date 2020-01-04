#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int x,a,b;cin >> x >> a >> b;
      if(b <= a)cout << "delicious";
      else if(b - a <= x)cout << "safe";
      else cout << "dangerous";
}