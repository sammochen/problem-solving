#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

VLL F(25, -1);

ll f(ll x) {
	if (x < 0) return 0;
	if (F[x] != -1) return F[x];
	if (x == 0) return 1;
	F[x] = f(x-1) * x;
	return F[x];
}

string get(string s, ll pos) {
	if (s.empty()) return "";
	pos %= f(s.length());
	
	sort(s.begin(), s.end());
	REP(i,0,s.length()) {
		if (i * f(s.length() - 1) <= pos && pos < (i+1) * f(s.length() - 1)) {
			return to_string(s[i]) + get(s.substr(0,i) + s.substr(i+1), pos);
		}
	}
}

void solve() {
	string s;
	ll k;
	cin >> s >> k;
	sort(s.begin(), s.end());
	string ans = get(s, k);
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}