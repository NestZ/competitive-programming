#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<bool> inv(10, false);

bool valid(int n){
	while(n > 0){
		if(inv[n % 10])return false;
		n /= 10;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;cin >> n >> k;
	for(int i = 0;i < k;i++){
		int d;cin >> d;
		inv[d] = true;
	}
	for(int i = n;;i++){
		if(valid(i)){
			cout << i << endl;
			break;
		}
	}
}
