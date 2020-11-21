#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

map<vector<int>, int> m;
vector<int> w;
vector<int> arr;
vector<int> ar;
vector<int> want;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, p;cin >> n >> p;
	for(int i = 1;i <= n;i++){
		arr.clear();
		for(int j = 0;j < p;j++){
			int num;cin >> num;
			arr.push_back(num);
		}
		m[arr] = i;
	}
	for(int i = 0;i < p;i++){
		int num;cin >> num;
		w.push_back(num);
	}
	if(m.count(w)){
		cout << m[w] << endl;
		return 0;
	}
	for(auto pa : m){
		ar = pa.first;
		want.clear();
		for(int i = 0;i < p;i++){
			want.push_back(w[i] - ar[i]);
		}
		if(m.count(want) && m[want] != m[ar]){
			cout << min(m[want], m[ar]) << ' ' << max(m[want], m[ar]) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}
