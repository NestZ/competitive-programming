#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      long long int sum = 0;
      vector<long long int> v;
      for(int i = 0;i < 2 * n;i++){
            int t;cin >> t;
            v.push_back(t);
      }
      int l = v.size();
      sort(v.begin(), v.end());
      for(int i = 0;i < l / 2;i++){
            sum += v[i] * v[l - i - 1];
      }
      cout << sum;
}