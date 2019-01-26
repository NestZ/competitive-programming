#include<iostream>

using namespace std;

int main(){
  int n,A = 0,B = 0,G = 0,i,max;

  cin >> n;

  char answer[n];
  cin >> answer;

  char Adrian[n];
  char Bruno[n];
  char Goran[n];

  for(i=1;i<=n;i++){
    if(i % 3 == 1)Adrian[i-1] = 'A';
    else if(i % 3 == 2)Adrian[i-1] = 'B';
    else if(i % 3 == 0)Adrian[i-1] = 'C';

    if(i % 2 == 1)Bruno[i-1] = 'B';
    else if(i % 4 == 0)Bruno[i-1] = 'C';
    else Bruno[i-1] = 'A';

    if(i % 6 == 1 || i % 6 == 2)Goran[i-1] = 'C';
    else if(i % 6 == 3 || i % 6 == 4)Goran[i-1] = 'A';
    else if(i % 6 == 5 || i % 6 == 0)Goran[i-1] = 'B';
  }

  /*for(i=0;i<n;i++){
    cout << Adrian[i];
  }
  cout << "\n";*/

  for(i=0;i<n;i++){
    if(Adrian[i] == answer[i])A++;
    if(Bruno[i] == answer[i])B++;
    if(Goran[i] == answer[i])G++;
  }

  max = A;
  if(B > max)max = B;
  if(G > max)max = G;

  cout << max << "\n";

  if(A == max)cout << "Adrian" << "\n";
  if(B == max)cout << "Bruno" << "\n";
  if(G == max)cout << "Goran" << "\n";

  return 0;
}
