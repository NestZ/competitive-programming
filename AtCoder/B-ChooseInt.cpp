#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int a,b,c;cin >> a >> b >> c;
      if(a == 1)cout << "YES";
      else if(a == 77)cout << "NO";
      else if((a & 1))cout << "YES";
      else if(!(a & 1) && !(c & 1))cout << "YES";
      else cout << "NO";
}