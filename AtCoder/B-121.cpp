#include<bits/stdc++.h>
using namespace std;

int main(){
      string a,b;cin >> a >> b;
      string c = a + b;
      int x = stoi(c);
      if(pow((int)sqrt(x), 2) == x)cout << "Yes";
      else cout << "No";
}