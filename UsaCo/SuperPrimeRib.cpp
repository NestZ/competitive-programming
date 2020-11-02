/*
ID: nestz
LANG: C++14
TASK: sprime
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;
vector<int> ans;

bool is_prime(string s){
	int num = stoi(s);
	if(num == 1)return false;
	for(int i = 2;i * i <= num;i++){
		if(num % i == 0)return false;
	}
	return true;
}

void dfs(string s){
	if(s.length() > n)return;
	if(s.length() == n){
		ans.push_back(stoi(s));		
		return;
	}
	for(int i = 1;i <= 9;i++){
		if(is_prime(s + to_string(i))){
			dfs(s + to_string(i));
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("sprime.out", "w", stdout);
	freopen("sprime.in", "r", stdin);
	
	cin >> n;
	dfs("");
	for(int i : ans)cout << i << endl;
}
