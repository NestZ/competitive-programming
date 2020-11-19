#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool overlap(tuple<int, int, int> &p1, tuple<int, int, int> &p2){
	if(pow(get<0>(p1) - get<0>(p2), 2) + pow(get<1>(p1) - get<1>(p2), 2) < pow(get<2>(p1) + get<2>(p2), 2))return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int cnt = 0;
	vector<tuple<int, int, int>> arr;
	for(int i = 0;i < n;i++){
		int x, y, r;cin >> x >> y >> r;
		arr.push_back(make_tuple(x, y, r));
	}
	sort(arr.begin(), arr.end());
	for(int i = 0;i < n - 1;i++){
		tuple<int, int, int> cur = arr[i];
		for(int j = i + 1;j < n;j++){
			tuple<int, int, int> other = arr[j];
			if(get<0>(cur) + 19 < get<0>(other))break;
			if(overlap(cur, other))cnt++;
		}
	}
	cout << cnt << endl;
}
