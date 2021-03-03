#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	if(m != 0 && abs(m) > n - 2)cout << -1 << endl;
	else if(m >= 0){
		int num = 2;
		int i = 0;
		if(m > 0){
			cout << 1 << ' ' << (m + 2) * 2 << endl;	
		}
		else cout << 1 << ' ' << 2 << endl;
		if(m > 0){
			for(;i < m + 1;i++){
				cout << num << ' ' << num + 1 << endl;
				num += 2;
			}
		}
		num++;
		for(;i < n - 1;i++){
			cout << num << ' ' << num + 1 << endl;
			num += 2;
		}
	}
	else cout << -1 << endl;
}
