#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	int w = 0;
	int l = 0;
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	for(int i = 0;i < n;i++){
		if(a[i] == 1 && b[i] == 0)w++;
		else if(a[i] == 0 && b[i] == 1)l++;
	}
	if(w == 0 && l == 0)cout << -1;
	else if(w == 0)cout << -1;
	else cout << (l + 1 + w - 1) / w;
}
