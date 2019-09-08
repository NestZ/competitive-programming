#include<bits/stdc++.h>
using namespace std;

int main(){
      int h1,h2,m1,m2;
      char temp1,temp2;
      cin >> h1 >> temp1 >> m1;
      cin >> h2 >> temp2 >> m2;
      int minute = (h2 - h1) * 60 + m2 - m1;
      minute /= 2;
      string s1 = to_string(h1 + (minute + m1) / 60);
      string s2 = to_string((m1 + minute) % 60);
      if(s1.length() == 1)s1 = '0' + s1;
      if(s2.length() == 1)s2 = '0' + s2;
      cout << s1 << ':' << s2; 
      return 0;
}
