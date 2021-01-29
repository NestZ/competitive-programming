#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	string a, b;cin >> a >> b;
	//0: sleep
	//1: stand
	int start, last;
	ll ans;
	//sleep
	if(n > 1 && a[0] == a[1]){
		last = 0;
		start = 2;
		ans = 6;
	}
	else{
		last = 1;
		start = 1;
		ans = 3;
	}
	for(int i = start;i < n;){
		//stand
		if(last == 1){
			ans = ans * 2ll % MOD;
			if(a[i] != b[i]){
				last = 0;
				i += 2;
			}
			else i++;
		}
		else{
			if(a[i] != b[i]){
				ans = ans * 3ll % MOD;
				i += 2;
			}
			else{
				last = 1;
				i++;
			}
		}
	}
	cout << ans << endl;
}
