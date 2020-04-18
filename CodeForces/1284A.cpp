#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m;cin >> n >> m;
	vector<string> a(n);
	vector<string> b(m);
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < m;i++)cin >> b[i];
	int q;cin >> q;
	for(int i = 0;i < q;i++){
		int t;cin >> t;
		t--;
		cout << a[t % n] + b[t % m] << endl;
	}
}
