#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, n;cin >> p >> n;
	vector<int> arr(p, -1);
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(arr[t % p] == -1)arr[t % p] = t;
		else return cout << i + 1, 0;
	}
	cout << -1;
}
