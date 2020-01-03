#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      for(int i = int('a');i <= int('z');i++){
            if(s.find(char(i)) == string::npos)return cout << char(i), 0;
      }
      cout << "None";
}