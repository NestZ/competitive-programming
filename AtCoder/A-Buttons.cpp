#include<bits/stdc++.h>
using namespace std;

int main(){
      int a;cin >> a;
      int b;cin >> b;
      if(a == b)return cout << a + b, 0;
      cout << (max(a, b) * 2) - 1;
}