#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;cin >> n >> t;
	for(int i = 0;i < n;i++){
		int s;cin >> s;
		int fr = 86400 - s;
		t -= fr;
		if(t <= 0){
			cout << i + 1;
			break;
		}
	}
}
