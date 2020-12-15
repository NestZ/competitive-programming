#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int cnt = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;cin >> c;
			if(c == '#')cnt++;
		}
	}
	if(cnt == n + m - 1)cout << "Possible";
	else cout << "Impossible";
	cout << endl;
}
