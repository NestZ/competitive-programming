#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      int n = s.length();
      for(int i = 1;i <= n;i++){
            if((i & 1) && (s[i - 1] == 'L'))return cout << "No", 0;
            else if(!(i & 1) && (s[i - 1] == 'R'))return cout << "No", 0;
      }
      cout << "Yes";
}