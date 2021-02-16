#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int mxr = 0;
	vector<tuple<int, int, int>> arr;
	for(int i = 0;i < n;i++){
		int p, q, r;cin >> p >> q >> r;
		arr.emplace_back(p, q, q + r - 1);
		mxr = max(mxr, p);
	}
	sort(arr.begin(), arr.end());
	int cur = 0;
	for(int i = 1;i <= mxr;i++){
		for(int j = 1;j <= 70;j++){
			auto p = arr[cur];
			int r = get<0>(p);
			int s = get<1>(p);
			int e = get<2>(p);
			while(cur < n && (i > r || (j > e && i == r))){
				cur++;
				p = arr[cur];
				r = get<0>(p);
				s = get<1>(p);
				e = get<2>(p);
			}
			if(r == i && s <= j && j <= e)cout << 'x';
			else cout << 'o';
		}
		cout << endl;
	}
}
