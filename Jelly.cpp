#include<iostream>
using namespace std;

int main(){
  int jelly[3];
  int n = 0;

  for(int i = 0;i < 3;i++){
    cin >> jelly[i];
  }

  int i = 0;
  while(jelly[0] + jelly[1] + jelly[2] != 3){
    if(jelly[i] == 1){
      i++;
    }
    else if(jelly[i] % 2 != 0){
      jelly[i] -= 1;
    }
    else if(jelly[i] % 2 == 0){
      jelly[i] /= 2;
      n += 1;
    }
  }

  cout << n;

  return 0;
}
