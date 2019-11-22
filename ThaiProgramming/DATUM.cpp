#include<iostream>

using namespace std;

int main(){
  int D,M,sum,i;
  int Month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

  cin >> D;
  cin >> M;

  for(i=M-1;i>0;i--){
    sum += Month[i-1];
  }

  sum += D;
  sum = sum % 7;

  if(sum == 1)cout << "Thursday";
  else if(sum == 2)cout << "Friday";
  else if(sum == 3)cout << "Saturday";
  else if(sum == 4)cout << "Sunday";
  else if(sum == 5)cout << "Monday";
  else if(sum == 6)cout << "Tuesday";
  else if(sum == 0)cout << "Wednesday";

  return 0;
}
