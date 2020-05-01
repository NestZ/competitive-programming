#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b;cin >> a >> b;
		int ans = abs(a - b) / 5;
		int curr = abs(a - b) % 5;
		if(curr == 1 || curr == 2)ans++;
		else if(curr == 3 || curr == 4)ans += 2;
		cout << ans << endl;
	}
}
