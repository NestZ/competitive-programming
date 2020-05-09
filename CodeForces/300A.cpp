#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	int cnta = 0;
	int cntb = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		arr[i] = t;
		if(t == 0)c.push_back(t);
		else if(t < 0)cnta++;
		else cntb++;
	}
	for(int i = 0;i < n;i++){
		if(arr[i] == 0)continue;
		if(a.size() == 0 && arr[i] < 0)a.push_back(arr[i]);
		else if(cntb == 0 && arr[i] < 0 && !(cnta & 1)){
			cnta--;
			c.push_back(arr[i]);
		}
		else if(cntb == 0 && arr[i] < 0)b.push_back(arr[i]);
		else if(arr[i] > 0)b.push_back(arr[i]);
		else c.push_back(arr[i]);
	}
	cout << a.size() << ' ';
	for(int i : a)cout << i << ' ';
	cout << endl << b.size() << ' ';
	for(int i : b)cout << i << ' ';
	cout << endl << c.size() << ' ';
	for(int i : c)cout << i << ' ';
}
