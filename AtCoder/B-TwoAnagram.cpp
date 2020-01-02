#include<bits/stdc++.h>
using namespace std;

int main(){
      string s1,s2;cin >> s1 >> s2;
      int n1 = s1.length();
      int n2 = s2.length();
      if(n1 < n2 && s1.substr(0, n1) == s2.substr(0, n1))return cout << "Yes", 0;
      for(int i = 0;i < n1;i++){
            for(int j = 0;j < n2;j++){
                  if(s2[j] > s1[i])return cout << "Yes", 0;
            }
      }
      cout << "No";
}