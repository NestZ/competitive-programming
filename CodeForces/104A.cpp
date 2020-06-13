#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	if(n <= 10 || n > 21)return cout << 0, 0;
	int w = n - 10;
	if(w == 10)cout << 15;
	else cout << 4;
}
