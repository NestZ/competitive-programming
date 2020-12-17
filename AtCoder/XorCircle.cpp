#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	map<int, int> m;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		m[arr[i]]++;
	}
	int fst = arr[0];
	int lst = 0;
	for(int i = 1;i < n;i++){
		if(m[fst ^ arr[i]] > 0){
			lst = arr[i];
			break;
		}
	}
	m[lst]--;
	bool ans = true;
	for(int i = 1;i < n;i++){
		if(m[fst ^ lst] > 0){
			m[fst ^ lst]--;
			int old_fst = fst;
			fst = lst;
			lst = (old_fst ^ lst);
		}
		else ans = false;
	}
	if(ans)cout << "Yes";
	else cout << "No";
	cout << endl;
}
