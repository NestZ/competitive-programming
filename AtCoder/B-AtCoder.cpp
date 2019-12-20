#include<bits/stdc++.h>
using namespace std;

int main(){
      int maxx = 0;
      int curr = 0;
      string s;cin >> s;
      int n = s.length();
      for(int i = 0;i < n;i++){
            if(s[i] == 'A' || s[i] == 'T' ||
            s[i] == 'G' || s[i] == 'C'){
                  curr++;
            }
            else{
                  if(curr > maxx)maxx = curr;
                  curr = 0;
            }
      }
      cout << max(maxx, curr);
}