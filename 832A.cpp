#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll a, b;cin >> a >> b;
	ll res = a / b;
	if(res & 1)cout << "YES";
	else cout << "NO";
}
