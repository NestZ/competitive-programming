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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  string vowels = "aeiou";
  vector<tuple<char, int, int>> arr;
  vector<string> s(n);
  for(int i = 0;i < n;i++){
    cin >> s[i];
    char lst = 0;
    int cnt = 0;
    for(int j = 0;j < (int)s[i].length();j++){
      if(vowels.find_first_of(s[i][j]) != string::npos){
        lst = s[i][j];
        cnt++;
      }
    }
    arr.push_back({lst, cnt, i});
  }
  sort(arr.begin(), arr.end());
  vector<pair<int, int>> com, semi, tmp;
  for(int i = 0;i < n;i++){
    char cur_lst = get<0>(arr[i]);
    char nxt_lst = get<0>(arr[i + 1]);
    int cur_cnt = get<1>(arr[i]);
    int nxt_cnt = get<1>(arr[i + 1]);
    int cur_ind = get<2>(arr[i]);
    int nxt_ind = get<2>(arr[i + 1]);
    if(i < n - 1 && cur_lst == nxt_lst && cur_cnt == nxt_cnt){
      com.push_back({cur_ind, nxt_ind});
      i++;
    }
    else tmp.push_back({cur_cnt, cur_ind});
  }
  sort(tmp.begin(), tmp.end());
  for(int i = 0;i < (int)tmp.size() - 1;i++){
    int cur_cnt = tmp[i].first;
    int nxt_cnt = tmp[i + 1].first;
    int cur_ind = tmp[i].second;
    int nxt_ind = tmp[i + 1].second;
    if(cur_cnt == nxt_cnt){
      semi.push_back({cur_ind, nxt_ind});
      i++;
    }
  }
  vector<pair<pair<string, string>, pair<string, string>>> ans;
  int semi_p = 0;
  for(int i = 0;i < (int)com.size();i++){
    if(semi_p == (int)semi.size()){
      if(i + 1 < (int)com.size()){
        auto up = make_pair(s[com[i + 1].first], s[com[i].first]);
        auto down = make_pair(s[com[i + 1].second], s[com[i].second]);
        ans.push_back({up, down});
        i++;
      }
    }
    else{
      auto up = make_pair(s[semi[semi_p].first], s[com[i].first]);
      auto down = make_pair(s[semi[semi_p].second], s[com[i].second]);
      ans.push_back({up, down});
      semi_p++;
    }
  }
  cout << ans.size() << endl;
  for(auto p : ans){
    auto up = p.first;
    auto down = p.second;
    cout << up.first << ' ' << up.second << endl;
    cout << down.first << ' ' << down.second << endl;
  }
}
