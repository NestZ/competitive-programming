#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;cin >> a >> b >> c;
	if(a + c <= b)return cout << (a + c) * 2, 0;
	if(b + c <= a)return cout << (b + c) * 2, 0;
	cout << (min(a, b) + c + max(a, b)) / 2 * 2;
}
