#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int arr[3][3];
	set<int> s;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			cin >> arr[i][j];
		}
	}
	int n;cin >> n;
	while(n--){
		int t;cin >> t;
		s.insert(t);
	}
	set<int> t;
	int dr = 0;
	int dl = 0;
	int r = 0;
	int c = 0;
	for(int i = 0;i < 3;i++){
		if(s.count(arr[i][i]) != 0)dl++;
		if(s.count(arr[i][3 - i - 1]) != 0)dr++;
	}
	if(dr == 3 || dl == 3)return cout << "Yes", 0;
	for(int i = 0;i < 3;i++){
		r = 0;
		c = 0;
		for(int j = 0;j < 3;j++){
			if(s.count(arr[i][j]) != 0)r++;
			if(s.count(arr[j][i]) != 0)c++;
			if(r == 3 || c == 3)return cout << "Yes", 0;
		}
	}
	cout << "No";
}
