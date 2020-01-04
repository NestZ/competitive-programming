#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int n,m;cin >> n >> m;
      int arr[n + 5];
      for(int i = 0;i < n;i++)arr[i] = 0;
      for(int i = 0;i < m;i++){
            int t,t2;cin >> t >> t2;
            arr[t]++;
            arr[t2]++;
      }
      for(int i = 0;i < n;i++)cout << arr[i + 1] << "\n";
}