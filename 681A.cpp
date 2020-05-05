#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	bool flag = false;
	while(n--){
		string s;cin >> s;
		int a, b;cin >> a >> b;
		if(a >= 2400 && b > a)flag = true;
	}
	if(flag)cout << "YES";
	else cout << "NO";
}
