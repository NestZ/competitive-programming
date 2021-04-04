#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void nsw(vector<int> &arr){
  int n = arr.size();
  vector<int> na;
  for(int i = n / 2;i < n;i++)
    na.push_back(arr[i]);
  for(int i = 0;i < n / 2;i++)
    na.push_back(arr[i]);
  for(int i = 0;i < n;i++)arr[i] = na[i];
}

void tsw(vector<int> &arr){
  int n = arr.size();
  for(int i = 0;i < n - 1;i += 2)
    swap(arr[i], arr[i + 1]);
}

bool check(vector<int> &arr){
  int n = arr.size();
  for(int i = 1;i <= n;i++){
    if(arr[i - 1] != i)return false;
  }
  return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

  int n;cin >> n;
  int ans = INT_MAX;
  vector<int> arr(2 * n);
  for(int i = 0;i < 2 * n;i++)cin >> arr[i];
  bool isn = false;
  vector<int> tmp(arr);
  if(check(arr))ans = 0;
  for(int i = 0;i < n;i++){
    if(isn)nsw(tmp);
    else tsw(tmp);
    if(check(tmp))ans = min(ans, i + 1);
    isn = !isn;
  }
  isn = true;
  tmp = vector<int>(arr);
  for(int i = 0;i < n;i++){
    if(isn)nsw(tmp);
    else tsw(tmp);
    if(check(tmp))ans = min(ans, i + 1);
    isn = !isn;
  }
  if(ans == INT_MAX)cout << -1;
  else cout << ans;
  cout << endl;
}
