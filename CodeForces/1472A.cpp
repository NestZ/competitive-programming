#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int w, h, n;cin >> w >> h >> n;
		int cnt = 0;
		while(w % 2 == 0){
			cnt++;
			w /= 2;
		}
		while(h % 2 == 0){
			cnt++;
			h /= 2;
		}
		if(pow(2, cnt) >= n)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
