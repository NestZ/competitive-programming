#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	for(int i = 0;i < t;i++){
		int n;cin >> n;
		vector<tuple<int, int, int>> arr;
		vector<tuple<int, int, int>> temp(n);
		map<tuple<int, int, int>, char> m;
		bool flag = true;
		int lastc = 0;
		int lastj = 0;
		for(int j = 0;j < n;j++){
			int a, b;cin >> a >> b;
			arr.push_back(make_tuple(a, b, j));
			temp[j] = arr[j];
		}
		sort(temp.begin(), temp.end());
		lastc = get<1>(temp[0]);
		m[temp[0]] = 'C';
		for(int j = 1;j < n;j++){
			if(get<0>(temp[j]) >= lastc){
				lastc = get<1>(temp[j]);
				m[temp[j]] = 'C';
			}
			else if(get<0>(temp[j]) >= lastj){
				lastj = get<1>(temp[j]);
				m[temp[j]] = 'J';
			}
			else{
				flag = false;
				break;
			}
		}
		if(!flag)cout << "Case #" << i + 1 << ": " << "IMPOSSIBLE" << endl;
		else{
			cout << "Case #" << i + 1 << ": ";
			for(tuple<int, int, int> p : arr)cout << m[p];
			cout << endl;
		}
	}
}
