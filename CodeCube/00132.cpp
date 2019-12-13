#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      long long int curr = 1;
      for(int i = 0;i < n;i++){
            curr += curr * 3ll;
      }
      cout << curr;
}