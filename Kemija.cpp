#include<iostream>
using namespace std;

int main(){
  string code;
  string decoded = "";
  int i;

  getline(cin,code);

  for(i = 0;i < code.size();i++){
    decoded += code[i];
    if(code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u'){
      i += 2;
    }
  }

  cout << decoded;

  return 0;
}
