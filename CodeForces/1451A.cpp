#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		if(n == 1)cout << 0;
		else if(n == 2)cout << 1;
		else if(n == 3)cout << 2;
		else{
			if(n % 2 == 0)cout << 2;
			else cout << 3;
		}
		cout << endl;
	}
}
