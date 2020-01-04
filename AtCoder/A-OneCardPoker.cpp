#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int a,b;cin >> a >> b;
      if(a == 1 && b == 1 || a == b)cout << "Draw";
      else if(a == 1)cout << "Alice";
      else if(b == 1)cout << "Bob";
      else if(a < b)cout << "Bob";
      else cout << "Alice";
}