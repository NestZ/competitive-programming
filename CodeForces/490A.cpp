#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(3, 0);
	vector<int> v;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		v.push_back(t);
		arr[t - 1]++;
	}
	int ans = *min_element(arr.begin(), arr.end());
	cout << ans << endl;
	set<int> in;
	for(int i = 0;i < ans;i++){
		set<int> s;
		for(int j = 0;j < n;j++){
			if(s.count(v[j]) == 0 && in.count(j) == 0){
				s.insert(v[j]);
				cout << j + 1 << ' ';
				in.insert(j);
			}
		}
		cout << endl;
	}
}
