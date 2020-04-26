#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		int sum = 0;
		for(int i = 0;i < n;i++){
			int k;cin >> k;
			sum += k;
		}
		cout << min(m, sum) << endl;
	}
}
