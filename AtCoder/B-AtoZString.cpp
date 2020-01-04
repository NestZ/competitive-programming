#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      string s;cin >> s;
      size_t start = s.find('A');
      size_t f = s.find('Z');
      while(f < start || s.find('Z', f + 1) != string::npos)f = s.find('Z', f + 1);
      cout << f - start + 1;
}