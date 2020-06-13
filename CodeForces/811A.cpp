#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	bool v = true;
	int curr = 1;
	while(a >= 0 && b >= 0){
		if(v)a -= curr++;
		else b -= curr++;
		v = !v;
	}
	if(v)cout << "Valera";
	else cout << "Vladik";
}
