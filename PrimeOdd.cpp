#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
  int n;
  string num;
  string num2;

  cin >> n;
  bool check[n];

  for(int i = 0;i < n;i++){
    cin >> num;
    num2 = num[num.size()-1];
    if(stoi(num2) % 2 == 0)check[i] = false;
    else check[i] = true;
  }

  for(int i = 0;i < n;i++){
    if(check[i] == true)cout << "T\n";
    else cout << "F\n";
  }

  return 0;
}
