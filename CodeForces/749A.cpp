#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	cout << n / 2 << endl;
	while(n > 0){
		if(n != 3){
			cout << 2 << ' ';
			n -= 2;
		}
		else{
			cout << 3 << ' ';
			n -= 3;
		}
	}
}
