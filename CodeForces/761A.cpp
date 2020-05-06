#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	if(abs(a - b) <= 1 && a + b > 0)cout << "YES";
	else cout << "NO";
}
