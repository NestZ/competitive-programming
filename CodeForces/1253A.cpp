#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0;i < n;i++)cin >> a[i];
		for(int i = 0;i < n;i++)cin >> b[i];
		set<int> s;
		vector<int> p;
		bool flag = true;
		for(int i = 0;i < n;i++){
			if(a[i] != b[i]){
				s.insert(a[i] - b[i]);
				if(a[i] - b[i] > 0)flag = false;
				p.push_back(i);
			}
		}
		int temp = p.size();
		for(int i = 1;i < temp;i++){
			if(p[i] - p[i - 1] != 1)flag = false;
		}
		if(s.size() > 1)flag = false;
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
