#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int num = n;
      int t = 0;
      while(n > 0){
            t += n % 10;
            n /= 10;
      }
      if(num % t == 0)cout << "Yes";
      else cout << "No";
}