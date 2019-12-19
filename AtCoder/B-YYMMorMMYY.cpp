#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      int a = stoi(s.substr(0, 2));
      int b = stoi(s.substr(2, 2));
      if(a <= 12 && b <= 12 && a > 0 && b > 0)cout << "AMBIGUOUS";
      else if(a > 0 && a <= 12 && b > 12)cout << "MMYY";
      else if(a > 12 && b <= 12 && b > 0)cout << "YYMM";
      else if(a == 0 && b <= 12 && b > 0)cout << "YYMM";
      else if(a > 0 && a <= 12 && b == 0)cout << "MMYY";
      else if(a == 0 && b == 0)cout << "NA";
      else if(a > 12 && b > 12)cout << "NA";
      else if(a == 0 && b > 12)cout << "NA";
      else if(a > 12 && b == 0)cout << "NA";
}