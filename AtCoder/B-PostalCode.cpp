#include<bits/stdc++.h>
using namespace std;

int main(){
      int a,b;cin >> a >> b;
      string s;cin >> s;
      int n = s.length();
      for(int i = 0;i < n;i++){
            if(i == a && s[i] != '-')return cout << "No", 0;
            else if(i != a && !(s[i] >= '0' && s[i] <= '9'))return cout << "No", 0;
      }
      cout << "Yes";
}