#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int a, b;cin >> a >> b;
		if(a > b){
			if((a - b) & 1)cout << 2;
			else cout << 1;
		}
		else if(a == b)cout << 0;
		else if((b - a) & 1)cout << 1;
		else cout << 2;
		cout << endl;
	}
}
