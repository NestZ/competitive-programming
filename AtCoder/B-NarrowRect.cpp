#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int w,a,b;cin >> w >> a >> b;
      if(b <= a + w && b >= a)cout << 0;
      else if(b + w <= a + w && b + w >= a)cout << 0;
      else cout << min(abs(a + w - b), abs(a - (b + w)));
}