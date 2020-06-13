#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int last;cin >> last;
	if(last > 15)return cout << 15, 0;
	for(int i = 0;i < n - 1;i++){
		int t;cin >> t;
		if(t > last + 15)return cout << last + 15, 0;
		last = t;
	}
	cout << min(90, last + 15);
}
