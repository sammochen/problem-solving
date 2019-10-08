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
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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

namespace SOLVE {	
	ll x, y, d, n;
	vector<PLL> v;
	map<PLL,ll> win;
	map<PLL,ll> done;

	PLL operator+(PLL a, PLL b) {
		return {a.first + b.first, a.second + b.second};
	}

	ll get(PLL p) {
		ll i = p.first, j = p.second;
		if (i*i + j*j > d*d) {
			return 1;
		}

		if (done[p]) return win[p];

		ll w = 0;
		for (PLL vv : v) {
			if (get(p + vv) == 0) {
				w = 1;
				break;
			}
		}

		done[p] = 1;
		win[p] = w;

		return w;
	}

	void main() {
		cin >> x >> y >> n >> d;
		v.resize(n);
		REP(i,0,n) {
			cin >> v[i].first >> v[i].second;
		}

		ll w = get({x,y});
		string ans = w ? "Anton" : "Dasha";
		cout << ans << endl;

	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
