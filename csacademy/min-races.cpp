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

namespace SOLVE {	
	ll bs(VLL &A, ll x) {
		ll L = 0, R = A.size() - 1;
		while (L < R) {
			ll M = (L+R)/2;
			if (A[M] >= x) L = M+1;
			else R = M;
		}
		return L;
	}

	void main() {
		ll n, k;
		cin >> n >> k;

		vector<PLL> A(n); // {place, class}
		REP(i,0,n) {
			cin >> A[i].second >> A[i].first;
		}

		sort(A.begin(), A.end());

		// go through it and keep a track of ends
		VLL ends(n); // will always be big->small
		ll size = 0;
		REP(i,0,n) {
			ll v = A[i].second;
			if (size == 0 || v <= ends[size - 1]) {
				ends[size] = v;
				size++;
			} else {
				// look for the largest A[i] where A[i] < v
				ll ind = bs(ends, v);
				ends[ind] = v;
			}
		}
		
		cout << size << endl;
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
