#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int s;cin >> s;
	if(s < 0){
		s = -s;
		s = min(s / 100 * 10 + s % 10, s / 10);
		s = -s;
	}
	cout << s;
}
