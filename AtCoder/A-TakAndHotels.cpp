#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int n,k,x,y;cin >> n >> k >> x >> y;
      cout << (x * min(n, k)) + y * (max(0, n - k));
}