#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b;cin >> a >> b;
		bool flag = false;
		if(a == 1 || b == 1)flag = true;
		if(a == 2 && b == 2)flag = true;
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
