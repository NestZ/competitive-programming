#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int q = 0;q < 5;q++){
		int n;cin >> n;
		vector<pair<int, int>> v1;
		vector<pair<int, int>> v2;
		for(int i = 0;i < n - 1;i++){
			int a, b;cin >> a >> b;
			if(a > b)swap(a, b);
			v1.emplace_back(a, b);
		}
		for(int i = 0;i < n - 1;i++){
			int a, b;cin >> a >> b;
			if(a > b)swap(a, b);
			v2.emplace_back(a, b);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		bool ans = true;
		for(int i = 0;i < n - 1;i++){
			if(v1[i].first != v2[i].first || v1[i].second != v2[i].second)
				ans = false;
		}
		if(ans)cout << 'Y';
		else cout << 'N';
	}
	cout << endl;
}
