#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr(6);
	map<int, int> m;
	vector<int> d;
	for(int i = 0;i < 6;i++){
		cin >> arr[i];
		m[arr[i]]++;
		if(m[arr[i]] > 4)d.push_back(arr[i]);
	}
	for(pair<int, int> p : m){
		if(p.second < 4){
			for(int i = 0;i < p.second;i++)d.push_back(p.first);
		}
	}
	if(d.size() != 2)return cout << "Alien", 0;
	if(d[0] == d[1])cout << "Elephant";
	else cout << "Bear";
}
