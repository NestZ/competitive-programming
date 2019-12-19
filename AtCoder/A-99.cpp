#include<bits/stdc++.h>
using namespace std;

int main(){
      int a;cin >> a;
      int b;cin >> b;
      if(a > 9 || b > 9 || a * b < 0)return cout << -1, 0;
      cout << a * b;
}