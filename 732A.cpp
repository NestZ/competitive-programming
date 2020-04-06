#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int k, r;cin >> k >> r;
	int ans = 1;
	while(ans * k % 10 != 0 && ans * k % 10 != r){
		ans++;
	}
	cout << ans;
}
