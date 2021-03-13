#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m, d;cin >> n >> m >> d;
	if(d == 0){
		printf("%.7f", double(m - 1) * ((double)n / double(n * n)));
	}
	else{
		printf("%.7f", double(m - 1) * (double(2.0) * (n - d) / double(n * n)));
	}
	cout << endl;
}
