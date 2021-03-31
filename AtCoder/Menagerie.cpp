#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
typedef long long int ll;
 
void fill_ans(string &s, vector<int> &arr){
	int n = s.length();
	for(int i = 1;i < n - 1;i++){
		if(arr[i] == 0){
			if(s[i] == 'o')arr[i + 1] = arr[i - 1];
			else arr[i + 1] = (arr[i - 1] ^ 1);
		}
		else{
			if(s[i] == 'o')arr[i + 1] = (arr[i - 1] ^ 1);
			else arr[i + 1] = arr[i - 1];
		}
	}
}

bool check(string &s, vector<int> &arr){
	int n = s.length();
	for(int i = 0;i < n;i++){
		int last = i - 1;
		int front = i + 1;
		if(i == 0)last = n - 1;
		else if(i == n - 1)front = 0;
		if(arr[i] == 0){
			if(s[i] == 'o' && arr[last] != arr[front])return false;
			else if(s[i] == 'x' && arr[last] == arr[front])return false;
		}
		else{
			if(s[i] == 'o' && arr[last] == arr[front])return false;
			else if(s[i] == 'x' && arr[last] != arr[front])return false;
		}
	}
	return true;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n;cin >> n;
	string s;cin >> s;
	vector<int> ans(n, -1);
	//0S 1W
	for(int i = 0;i <= 1;i++){
		for(int j = 0;j <= 1;j++){
			fill(ans.begin(), ans.end(), -1);
			ans[0] = i; ans[1] = j;
			fill_ans(s, ans);
			if(check(s, ans)){
				for(int e : ans){
					if(e == 0)cout << 'S';
					else cout << 'W';
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
