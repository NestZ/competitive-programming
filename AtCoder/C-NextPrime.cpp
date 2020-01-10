#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple
bool isPrime(int n){
      if(n <= 1)return false;
      if(n <= 3)return true;
      if(n % 2 == 0 || n % 3 == 0)return false;
      for(int i = 5;i * i <= n;i += 6){
            if(n % i == 0 || n % (i + 2) == 0)return false;
      }
      return true;
}

int main(){
      int n;cin >> n;
      for(int i = n;;i++){
            if(isPrime(i))return cout << i, 0;
      }
}