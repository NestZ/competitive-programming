#include<bits/stdc++.h>
using namespace std;

int main(){
      long long int a,b,c;
      cin >> a >> b >> c;
      cout << c * 2 + min(a,b) * 2 + (a == b ? 0:1);
      return 0;
}