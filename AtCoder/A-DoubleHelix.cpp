#include<bits/stdc++.h>
using namespace std;

int main(){
      map<char, char> m;
      m['A'] = 'T';
      m['T'] = 'A';
      m['G'] = 'C';
      m['C'] = 'G';
      char c;cin >> c;
      cout << m[c];
}