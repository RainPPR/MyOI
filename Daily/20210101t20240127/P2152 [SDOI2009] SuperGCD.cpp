#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int N = 1e4 + 10;

using ttp = signed char;

struct bigint {

vector<ttp> dig; // 倒序遍历 

bigint() { dig.clear(); }
bigint(size_t l) { dig.resize(l); }
bigint(vector<ttp> &dig): dig(dig) {}
bigint(string &s) {
	dig.resize(s.size());
	for (size_t i = 0; i < s.size(); ++i)
	dig[i] = s[s.size() - i - 1] - '0';
}

string tostring() {
	string s;
	for (size_t i = dig.size() - 1; ~i; --i) s.push_back(dig[i] + '0');
	return s;
}

void show(char sep = '\n') {
	for (size_t i = dig.size() - 1; ~i; --i) putchar(dig[i] + '0');
    putchar(sep);
}

bool operator =(const bigint &a) {
	dig = a.dig;
}

friend bool operator ==(const bigint &a, const bigint &b) {
	if (a.dig.size() != b.dig.size()) return false;
	for (size_t i = 0; i < a.dig.size(); ++i) if (a.dig[i] != b.dig[i]) return false;
	return true;
}

friend bool operator !=(const bigint &a, const bigint &b) {
	return (a == b) ^ 1;
}

friend bool operator <(const bigint &a, const bigint &b) {
	if (a == b) return 0;
	if (a.dig.size() != b.dig.size()) return a.dig.size() < b.dig.size();
	for (size_t i = a.dig.size() - 1; ~i; --i) if (a.dig[i] != b.dig[i]) return a.dig[i] < b.dig[i];
	return 0;
}

friend bigint operator -(const bigint &a, const bigint &b) {
    size_t maxlen = max(a.dig.size(), b.dig.size());
	size_t minlen = min(a.dig.size(), b.dig.size());
    bigint nw(maxlen); ttp jw = 0;
    for (size_t i = 0; i < minlen; ++i) {
        ttp t = a.dig[i] - b.dig[i] - jw;
        jw = 0; if (t < 0) t += 10, jw = 1;
        nw.dig[i] = t;
    } for (size_t i = minlen; i < a.dig.size(); ++i) {
        ttp t = a.dig[i] - jw;
        jw = 0; if (t < 0) t += 10, jw = 1;
        nw.dig[i] = t;
    } while (nw.dig.back() == 0) nw.dig.pop_back();
	return nw;
}

bigint right() {
    bigint nw(dig.size()); ttp ad = 0;
    for (size_t i = dig.size() - 1; ~i; --i) {
        ttp t = ad * 10 + dig[i];
        if (t >= 2) nw.dig[i] = t / 2, t %= 2;
        ad = t;
    } while (nw.dig.back() == 0) nw.dig.pop_back();
	return nw;
}

bigint left() {
    bigint nw(dig.size()); ttp ad = 0;
    for (size_t i = 0; i < dig.size(); ++i) {
        nw.dig[i] = dig[i] * 2 + ad;
        ad = nw.dig[i] / 10, nw.dig[i] %= 10;
    } if (ad) nw.dig.push_back(ad);
	return nw;
}

bool and1() {
	return dig[0] & 1;
}

};

template<typename tp>
inline tp gcd(tp m, tp n) {
	if (m == n) return m;
	if (m < n) return gcd(n, m);
	if (m.and1()) {
		if (n.and1()) return gcd(n, m - n);
		else return gcd(m, n.right());
	} else {
		if (n.and1()) return gcd(m.right(), n);
		else return gcd(m.right(), n.right()).left();
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	string a, b; cin >> a >> b;
	bigint A(a), B(b);
	gcd(A, B).show();
	return 0;
}
