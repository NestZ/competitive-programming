#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int s(string s1, string s2){
      if(s1.length() < s2.length())return 1;
      else if(s1.length() > s2.length())return 2;
      int n = s1.length();
      for(int i = 0;i < n;i++){
            if((int)s1[i] > (int)s2[i])return 2;
            else if((int)s1[i] < (int)s2[i])return 1;
      }
      return 3;
}

int main(){
      string a,b;cin >> a >> b;
      if(s(a, b) == 3)cout << "EQUAL";
      else if(s(a, b) == 1)cout << "LESS";
      else if(s(a, b) == 2)cout << "GREATER";
}