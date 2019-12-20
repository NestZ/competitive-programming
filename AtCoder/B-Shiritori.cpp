#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      set<string> s;
      string last;
      for(int i = 0;i < n;i++){
            string str;cin >> str;
            if(i > 0){
                  if(str[0] != last[last.length() - 1] || s.count(str) != 0)return cout << "No", 0;
            }
            last = str;
            s.insert(str);
      }
      cout << "Yes";
}