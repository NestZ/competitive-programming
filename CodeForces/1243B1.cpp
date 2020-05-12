#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		string a;cin >> a;
		string b;cin >> b;
		int cnt = 0;
		int p1 = 0;
		int p2 = 0;
		for(int i = 0;i < n;i++){
			if(a[i] != b[i]){
				if(cnt == 0)p1 = i;
				else if(cnt == 1)p2 = i;
				cnt++;
			}
		}
		if(cnt == 2){
			swap(a[p1], b[p2]);
			if(a == b)cout << "Yes";
			else cout << "No";
		}
		else if(cnt == 0)cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}
