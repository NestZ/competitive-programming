#include<bits/stdc++.h>
using namespace std;

int main(){
      map<string, string> m;
      m["Sunny"] = "Cloudy";
      m["Cloudy"] = "Rainy";
      m["Rainy"] = "Sunny";
      string s;cin >> s;
      cout << m[s];
}