#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
      if(a == 0)return b;
      return gcd(b % a, a);
}

int main(){
      int a;cin >> a;
      int b;cin >> b;
      cout << gcd(a, b);
}