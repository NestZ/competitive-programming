#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      vector<int> v;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            v.push_back(t);
      }
      cout << *max_element(v.begin(), v.end()) << "\n";
      cout << *min_element(v.begin(), v.end());
}