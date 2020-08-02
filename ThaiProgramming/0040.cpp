#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;cin >> n;
  for(int i = 0;i < n;i++){
    string temp;cin >> temp;
    if(temp == "2")cout << "T\n";
    else if(temp[temp.length() - 1] & 1)cout << "T\n";
    else cout << "F\n";
  }

  return 0;
}
