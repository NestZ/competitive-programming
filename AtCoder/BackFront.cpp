#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int mx = 0;
	vector<int> m(n + 1);
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		m[num]++;
		m[num] += m[num - 1];
		mx = max(mx, m[num]);
	}
	cout << n - mx << endl;
}
