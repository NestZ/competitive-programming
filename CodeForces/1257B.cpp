#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll a, b;cin >> a >> b;
		bool flag = false;
		if(a >= b)flag = true;
		else if(a > 3)flag = true;
		else{
			if(a == 1 && b == 1)flag = true;
			else if(a == 2 && b <= 3)flag = true;
			else if(a == 3 && b <= 3)flag = true;
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
