#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int N = 1e4 + 10;

using vv = vector<int>;

vv convert(string &s) {
	vv dig(s.size());
	for (int i = 0; i < s.size(); ++i)
	dig[i] = s[s.size() - i - 1] - '0';
	return dig;
}

bool les(vv &a, vv &b) {
	if (a == b) return 0;
	if (a.size() != b.size()) return a.size() < b.size();
	for (size_t i = a.size() - 1; ~i; --i) if (a[i] != b[i]) return a[i] < b[i];
	return 0;
}

int a1(vv &x) {
	return x[0] & 1;
}

vv mns(vv &a, vv &b) {
    int maxlen = max(a.size(), b.size());
	int minlen = min(a.size(), b.size());
    vv nw(maxlen); int jw = 0;
    for (int i = 0; i < minlen; ++i) {
        int t = a[i] - b[i] - jw;
        jw = 0; if (t < 0) t += 10, jw = 1;
        nw[i] = t;
    } for (int i = minlen; i < a.size(); ++i) {
        int t = a[i] - jw;
        jw = 0; if (t < 0) t += 10, jw = 1;
        nw[i] = t;
    } while (nw.back() == 0) nw.pop_back();
	return nw;
}

void divi(vv &dig) {
    vv nw(dig.size()); int ad = 0;
    for (int i = dig.size() - 1; ~i; --i) {
        int t = ad * 10 + dig[i];
        if (t >= 2) nw[i] = t / 2, t %= 2;
        ad = t;
    } while (nw.back() == 0) nw.pop_back();
	dig = nw;
}

void tims(vv &dig) {
    vv nw(dig.size()); int ad = 0;
    for (int i = 0; i < dig.size(); ++i) {
        nw[i] = dig[i] * 2 + ad;
        ad = nw[i] / 10, nw[i] %= 10;
    } if (ad) nw.push_back(ad);
	dig = nw;
}

void pnt(vv &dig, char sep = '\n') {
	for (size_t i = dig.size() - 1; ~i; --i) putchar(dig[i] + '0');
    putchar(sep);
}

inline vv gcd(vv m, vv n) {
	if (m == n) return m;
	if (les(m, n)) return gcd(n, m);
	if (a1(m)) {
		if (a1(n)) return gcd(n, mns(m, n));
		else {
			divi(n);
			return gcd(m, n);
		}
	} else {
		divi(m);
		if (a1(n)) return gcd(m, n);
		else {
			divi(n);
			auto q = gcd(m, n);
			tims(q);
			return q;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string a, b; cin >> a >> b;
	vv A = convert(a), B = convert(b);

	int cnt = 0; while (A != B) {
		if (les(A, B)) swap(A, B);
		auto aA = a1(A), aB = a1(B);
		if (aA && aB) {
			auto q = mns(A, B);
			tie(A, B) = make_tuple(B, q);
		} else {
			if (!aA) divi(A);
			if (!aB) divi(B);
			if (!aA && !aB) ++cnt;
		}
	}

	// pnt(A);
	while (cnt--) tims(A);
	pnt(A);
	return 0;
}
