#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int n,l;cin >> n >> l;
      vector<string> v;
      for(int i = 0;i < n;i++){
            string t;cin >> t;
            v.push_back(t);
      }
      sort(v.begin(), v.end());
      for(string t : v){
            cout << t;
      }
}