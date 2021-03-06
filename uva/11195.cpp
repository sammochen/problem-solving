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

namespace SOLVE {
	ll n;

	vector<string> A;

	ll on(ll ind, ll mask) {
		return ((1LL << ind) & mask) ? 1 : 0;
	}

	ll maskor(ll ind, ll mask) {
		return ((1LL << ind) | mask);
	}

	ll test = 1;

	// n * 2^n * 2^n * 2^n = TLE ):
	ll get(ll row, ll col, ll d1, ll d2) {
		if (row == n) return 1;

		ll best = 0;
		REP(i,0,n) {
			ll ok = 1;
			if (A[row][i] == '*') ok = 0;

			if (on(i, col | d1 | d2)) ok = 0;

			if (ok) {
				best += get(row + 1, maskor(i, col), maskor(i, d1) << 1, maskor(i, d2) >> 1);
			}
		}

		return best;
		
	}

	void main() {	
		in(n);
		if (n == 0) exit(0);
		
		A.clear();
		A.resize(n);
		REP(i,0,n) in(A[i]);

		ll ans = get(0,0,0,0);
		printf("Case %lld: %lld\n", test++, ans);
	}
}


signed main() {
	while (1) {
		SOLVE::main();
	}

	return 0;
}
