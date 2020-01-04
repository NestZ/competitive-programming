#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      map<int, int> m;
      m[1] = 1;
      m[3] = 1;
      m[5] = 1;
      m[7] = 1;
      m[8] = 1;
      m[10] = 1;
      m[12] = 1;
      m[4] = 2;
      m[6] = 2;
      m[9] = 2;
      m[11] = 2;
      m[2] = 3;
      int a,b;cin >> a >> b;
      if(m[a] == m[b])cout << "Yes";
      else cout << "No";
}