#include<iostream>
using namespace std;

int main(){
  string op1;
  string op2;
  char operate;
  string ans = "";
  int max;

  cin >> op1 >> operate >> op2;

  if(operate == '*'){
    ans += '1';
    int n = op1.size() + op2.size() - 2;
    for(int i = 0;i < n;i++)ans += '0';
  }
  else{
    if(op1.size() > op2.size()){
      max = op1.size();
      ans += '1';
    }
    else if(op1.size() < op2.size()){
      max = op2.size();
      ans += '1';
    }
    else{
      max = op1.size();
      ans += '2';
    }

    int diff = op1.size() - op2.size();

    if(diff < 0)diff *= -1;

    for(int j = 1;j < max;j++){
      if(j == diff)ans += '1';
      else ans += '0';
    }
  }

  cout << ans;

  return 0;
}
