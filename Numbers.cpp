#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;

int findMin(int n[], int size, bool start){
  int min = 9;
  int pos;
  for(int i = 0;i < size;i++){
      if(!start && n[i] <= min && n[i] != 0 && n[i] > -1){
        min = n[i];
        pos = i;
      }
      else if(start && n[i] <= min && n[i] > -1){
      min = n[i];
      pos = i;
      }
  }
  return pos;
}

int main(){
  int n;

  cin >> n;

  int number[n];

  for(int j = 0;j < n;j++)
    cin >> number[j];

  cout << number[findMin(number, n, false)];
  number[findMin(number, n, false)] = -1;
  for(int k = 0;k < n-1;k++){
    cout << number[findMin(number, n, true)];
    number[findMin(number, n, true)] = -1;
  }

  return 0;
}
