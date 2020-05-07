#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int b, k;cin >> b >> k;
	int cnt = 0;
	for(int i = 0;i < k;i++){
		int t;cin >> t;
		if(i == k - 1){
			if(t & 1)cnt++;
		}
		else if(t % 2 != 0 && b % 2 != 0)cnt++;
	}
	if(cnt & 1)cout << "odd";
	else cout << "even";
}
