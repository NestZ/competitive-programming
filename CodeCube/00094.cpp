#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      vector<char> v;
      for(int i = 0;i < n;i++){
            char temp;cin >> temp;
            v.push_back(temp);
            if(i > 0 && v[i] == v[i - 1])return cout << "Wrong Answer", 0;
      }
      cout << "Accepted";
}