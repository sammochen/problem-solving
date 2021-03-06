/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	VLL A;
	ll n;
	map<ll,ll> dp;
	map<ll,ll> done;

	ll states(ll k) {
		if (k == 1) return 0;
		if (done[k]) return dp[k];
		ll ans = inf;
		for (ll a : A) {
			if (k % a == 0) ans = min(ans, 1 + states(k / a));
		}
		done[k] = 1;
		dp[k] = ans;
		return ans;
	}

	VLL ans = {1};
	void get(ll k) {
		for (ll a : A) {
			if (k % a == 0) {
				if (states(k) == 1 + states(k/a)) {
					ans.push_back(ans[ans.size() - 1] * a);
					get(k / a);
					return;
				}
			}
		}
	}

	void main() {
		ll k;
		cin >> k >> n;
		A.resize(n);
		REP(i,0,n) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());

		if (states(k) == inf) {
			cout << -1 << endl;
			return;
		}

		get(k);
		
		REP(i,0,ans.size()) {
			cout << ans[i];
			if (i == ans.size() - 1) cout << endl;
			else cout << ' ';
		}
		



	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
