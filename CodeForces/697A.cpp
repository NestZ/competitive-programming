#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, s, x;cin >> t >> s >> x;
	if(x == t + 1 || x < t)cout << "NO";
	else if((x - t) % s == 0 || (x - t) % s == 1)cout << "YES";
	else cout << "NO";
}
