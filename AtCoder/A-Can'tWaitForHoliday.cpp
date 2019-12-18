#include<bits/stdc++.h>
using namespace std;

int main(){
      map<string, int> m;
      m["SUN"] = 0;
      m["MON"] = 1;
      m["TUE"] = 2;
      m["WED"] = 3;
      m["THU"] = 4;
      m["FRI"] = 5;
      m["SAT"] = 6;
      string s;cin >> s;
      cout << 7 - m[s];
}