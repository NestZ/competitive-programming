#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<pair<int, int>> arr;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		arr.push_back({0, a});
		arr.push_back({1, b});
	}
	sort(arr.begin(), arr.end());
	if(n & 1){
		int cnts = 0;
		int cnte = 0;
		int start = INT_MAX;
		int end = 0;
		for(int i = 0;i < 2 * n;i++){
			int fst = arr[i].first;
			int snd = arr[i].second;
			if(fst == 0){
				if(cnts == (n - 1) / 2){
					start = min(start, snd);
				}
				else cnts++;
			}
			fst = arr[2 * n - i - 1].first;
			snd = arr[2 * n - i - 1].second;
			if(fst == 1){
				if(cnte == (n - 1) / 2){
					end = max(end, snd);
				}
				else cnte++;
			}
		}
		cout << end - start + 1 << endl;
	}
	else{
		int w1 = n / 2 - 1;
		int w2 = n / 2;
		int cnt = 0;
		int ans = 0;
		int start = 0;
		int end = 0;
		for(int i = 0;i < 2 * n;i++){
			int fst = arr[i].first;
			int snd = arr[i].second;
			if(fst == 0){
				if(cnt == w1){
					start = snd;
					cnt++;
				}
				else if(cnt == w2){
					int ns = (start + snd + 1) / 2;
					if((start + snd) / 2 != ns)ans++;
					start = ns;
					break;
				}
				else cnt++;
			}
		}
		cnt = 0;
		for(int i = 2 * n - 1;i >= 0;i--){
			int fst = arr[i].first;
			int snd = arr[i].second;
			if(fst == 1){
				if(cnt == w1){
					end = snd;
					cnt++;
				}
				else if(cnt == w2){
					int ne = (end + snd + 1) / 2;
					if((end + snd) / 2 != ne)ans--;
					end = ne;
					break;
				}
				else cnt++;
			}
		}
		ans += (end - start + 1) * 2 - 1;
		cout << ans << endl;
	}
}
