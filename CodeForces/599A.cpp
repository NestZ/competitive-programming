#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a, b, c;cin >> a >> b >> c;
	int ans = min(a * 2 + b * 2, min(a + b + c, min((a + c) * 2, (b + c) * 2)));
	cout << ans;
}
