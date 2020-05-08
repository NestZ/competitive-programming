#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	if(n % 10 == 0)return cout << n, 0;
	else if(n % 10 <= 5)n -= n % 10;
	else n += 10 - n % 10;
	cout << n;
}
