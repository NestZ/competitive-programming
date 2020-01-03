#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair

int main(){
      int a,b;cin >> a >> b;
      if(a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0)cout << "Possible";
      else cout << "Impossible";
}