#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;cin >> a >> b >> c;
	int n = min({a, b / 2, c / 4});
	cout << n + n * 2 + n * 4;
}
