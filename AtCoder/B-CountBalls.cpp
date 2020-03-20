#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n,a,b;cin >> n >> a >> b;
	cout << a * (n / (a + b)) + min(n % (a + b), a);
}
