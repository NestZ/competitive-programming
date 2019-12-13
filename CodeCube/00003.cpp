#include<bits/stdc++.h>
using namespace std;

int main(){
	  long long a;cin >> a;
	  long long b;cin >> b;
	  long long t = 1;
	  if(a > b){
			a ^= b;
			b ^= a;
			a ^= b;
	  }
	  while((b * t) % a != 0ll){
			t++;
	  }
	  cout << b * t;
}