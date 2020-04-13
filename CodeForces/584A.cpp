#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, t;cin >> n >> t;
	if(n == 1 && t == 10)return cout << -1, 0;
	if(t == 10)cout << 1 << string(n - 1, '0');
	else cout << string(n, '0' + t);
}
