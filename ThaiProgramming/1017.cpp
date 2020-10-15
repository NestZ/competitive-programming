#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int arr[n + 5][n + 5];
	set<int> s;
	map<int, int> m;
	int t;
	for(int i = 0;i < n;i++){
		t = 0;
		for(int j = 0;j < n;j++){
			cin >> arr[i][j];
			m[arr[i][j]]++;
			if(m[arr[i][j]] == 2)return cout << "No", 0;
			t += arr[i][j];
		}
		s.insert(t);
	}
	t = 0;
	for(int i = 0;i < n;i++)t += arr[i][i];
	s.insert(t);
	t = 0;
	for(int i = n - 1;i >= 0;i--)t += arr[i][n - i - 1];
	s.insert(t);
	for(int i = 0;i < n;i++){
		t = 0;
		for(int j = 0;j < n;j++)t += arr[j][i];
		s.insert(t);
	}
	if(s.size() == 1)cout << "Yes";
	else cout << "No";
}
