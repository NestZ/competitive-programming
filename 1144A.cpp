#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      for(int i = 0;i < n;i++){
            string s;
            cin >> s;
            if(s.length() == 1){
                  cout << "Yes\n";
                  continue;
            }
            sort(s.begin(),s.end());
            for(int j = 0;j < s.length() - 1;j++){
                  if(s[j + 1] - s[j] != 1){
                        cout << "No\n";
                        break;
                  }
                  else if(s[j + 1] - s[j] == 1 && j == s.length() - 2)cout << "Yes\n";
            }
      }
      return 0;
}