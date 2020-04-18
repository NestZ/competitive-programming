#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<pair<int,int>> arr;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		arr.push_back({a, b});
	}
	sort(arr.begin(), arr.end());
	int curr = arr[0].second;
	for(int i = 1;i < n;i++){
		if(curr <= arr[i].second)curr = arr[i].second;
		else{
			curr = arr[i].first;
		}
	}
	cout << curr;
}
