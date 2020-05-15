#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		set<int> s;
		for(int i = 0;i < n;i++){
			s.insert(((i +  (arr[i] % n)) + n) % n);
		}
		if((int)s.size() != n)cout << "NO";
		else cout << "YES";
		cout << endl;
	}
}
