#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      string a,b,c;cin >> a >> b >> c;
      if(a[a.length() - 1] == b[0] && b[b.length() - 1] == c[0])cout << "YES";
      else cout << "NO";
}