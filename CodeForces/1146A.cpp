#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;
      cin >> s;
      int counter = 0;
      for(int i = 0;i < s.length();i++)if(s[i] == 'a')counter++;
      cout << (counter <= s.length() - counter ? counter * 2 - 1:s.length());
      return 0;
}