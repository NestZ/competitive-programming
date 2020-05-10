#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int w = n * (n + 1) / 2;
	m %= w;
	for(int i = 1;i <= n;i++){
		if(m >= i)m -= i;
		else break;
	}
	cout << m;
}
