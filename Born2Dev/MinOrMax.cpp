#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;cin >> a >> b;
	if(a > b)cout << 'A';
	else if(b > a)cout << 'B';
	else cout << "AB";
}
