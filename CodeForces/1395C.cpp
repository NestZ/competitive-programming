#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < m;i++)cin >> b[i];
	for(int i = 0;i < (1 << 9);i++){
		int cnt = 0;
		for(int j = 0;j < n;j++){
			bool h = false;
			for(int k = 0;k < m;k++){
				if((i | (a[j] & b[k])) == i)h = true;
			}
			if(h)cnt++;
		}
		if(cnt == n)return cout << i, 0;
	}
}
