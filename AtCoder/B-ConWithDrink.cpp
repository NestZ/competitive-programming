#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int n;cin >> n;
      int arr[n + 5];
      int sum = 0;
      for(int i = 0;i < n;i++){
            cin >> arr[i];
            sum += arr[i];
      }
      int m;cin >> m;
      for(int i = 0;i < m;i++){
            int p,x;cin >> p >> x;
            cout << sum - (arr[p - 1] - x) << "\n";
      }
}