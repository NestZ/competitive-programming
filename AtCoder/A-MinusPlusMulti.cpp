#include<bits/stdc++.h>
using namespace std;

int main(){
      int a;cin >> a;
      int b;cin >> b;
      cout << max(a + b, max(a - b, a * b));
}