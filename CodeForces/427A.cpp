#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int curr = 0;
	int ans = 0;
	while(n--){
		int t;cin >> t;
		if(t < 0 && curr == 0)ans += abs(t);
		else if(t < 0 && curr > 0){
			ans += max(0, abs(t) - curr);
			curr = max(0, curr - abs(t));
		}
		else if(t > 0)curr += t;
	}
	cout << ans;
}
