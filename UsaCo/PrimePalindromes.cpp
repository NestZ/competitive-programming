/*
ID: nestz
LANG: C++14
TASK: pprime
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

set<string> ans;
vector<int> arr;
int n = 0;

bool is_prime(int num){
	for(int i = 2;i * i <= num;i++){
		if(num % i == 0)return false;
	}
	return true;
}

void dfs(){
	if((int)arr.size() > n)return;
	if(arr.size() == 1){
		if(is_prime(arr[0]))ans.insert(to_string(arr[0]));
	}
	if(arr.size() != 0){
		string num = "";
		for(int i = 0;i < int(arr.size());i++){
			num += arr[i] + '0';
		}
		string rev_num = num;
		reverse(rev_num.begin(), rev_num.end());
		for(int i = 0;i <= 10;i++){
			string real_num = num;
			if(i == 10){
				real_num += rev_num;
			}
			else{
				real_num += '0' + i;
				real_num += rev_num;
			}
			if(is_prime(stoi(real_num)))ans.insert(real_num);
		}
	}
	for(int j = 0;j <= 9;j++){
		arr.push_back(j);
		dfs();
		arr.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("pprime.out", "w", stdout);
	freopen("pprime.in", "r", stdin);
	
	int l, r;cin >> l >> r;
	int t = r;
	while(t > 0){
		t /= 10;
		n++;
	}
	n /= 2;
	dfs();
	vector<int> real_ans;
	for(string s : ans)
		if(stoi(s) >= l && stoi(s) <= r)
			real_ans.push_back(stoi(s));
	sort(real_ans.begin(), real_ans.end());
	for(int i : real_ans)cout << i << endl;
}
