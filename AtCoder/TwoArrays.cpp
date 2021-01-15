#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	ll w = 0;
	ll h = 0;
	for(int i = 0;i < n;i++){
		if(a[i] > b[i])w += a[i] - b[i];
		else if(a[i] < b[i])h += (b[i] - a[i]) / 2;
	}
	if(h >= w)cout << "Yes";
	else cout << "No";
	cout << endl;
}
