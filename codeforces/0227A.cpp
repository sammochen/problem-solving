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
	PLL operator-(PLL a, PLL b) {
		return {a.first - b.first, a.second - b.second};
	}

	ll cross(PLL a, PLL b) {
		return a.first * b.second - a.second * b.first;
	}

	void main() {
		PLL a, b, c;
		cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

		PLL ba = b - a;
		PLL cb = c - b;

		ll dir = cross(ba,cb);
		string ans;
		if (dir == 0) ans = "TOWARDS";
		if (dir < 0) ans = "RIGHT";
		if (dir > 0) ans = "LEFT";

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
