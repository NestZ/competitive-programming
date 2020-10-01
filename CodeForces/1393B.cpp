#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> m(100005, 0);
	int c4 = 0;
	int c2 = 0;
	for(int i = 0;i < n;i++){
		int l;cin >> l;
		m[l]++;
	}
	for(int i = 0;i < 100005;i++){
		if(m[i] > 0){
			c2 += m[i] / 2;
			c4 += m[i] / 4;
		}
	}
	int q;cin >> q;
	for(int i = 0;i < q;i++){
		char c;cin >> c;
		int l;cin >> l;
		if(c == '+'){
			m[l]++;
			if(m[l] % 2 == 0)c2++;
			if(m[l] % 4 == 0)c4++;
		}
		else{
			if(m[l] % 2 == 0)c2--;
			if(m[l] % 4 == 0)c4--;
			m[l]--;
		}
		if(c2 >= 4 && c4 >= 1)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
