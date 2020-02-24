#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	int n;cin >> n;
	int ans;
	vector<int> v(n);
	for(int i = 0;i < n;i++){
		cin >> v[i];
		if(i == 0)ans = v[0];
		if(i > 0)ans = gcd(ans, v[i]);
	}
	cout << ans;
}
