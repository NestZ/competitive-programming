#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      for(int i = 0;i < n;i++){
            string s;cin >> s;
            string ans;
            if(s.find("X") != string::npos)ans = "No - Runtime error";
            else if(s.find("T") != string::npos)ans = "No - Time limit exceeded";
            else if(s.find("-") != string::npos)ans = "No - Wrong answer";
            else ans = "Yes";
            cout << "Case #" << (i + 1) << ": " << ans << "\n"; 
      }
}