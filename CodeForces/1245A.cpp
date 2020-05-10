#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int gcd(int a, int b){
	return (b ? gcd(b, a % b) : a);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		if(gcd(a, b) == 1)cout << "finite" << endl;
		else cout << "infinite" << endl;
	}
}
