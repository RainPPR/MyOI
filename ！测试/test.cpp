#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

string a, b;

using t = unsigned long long;

const t xx = 47;
const t vv = 53;

t aa[N], bb[N];

t cc, dd;

t ee[N], ff[N];
t gg[N], hh[N];

pair<t, t> qq(t ww, t ee, t rr, t tt, int yy) {
	t uu, ii;
	uu = ww * aa[yy] + rr;
	ii = ee * bb[yy] + tt;
	return {uu, ii};
}

vector<int> mq;

unsigned long long zhegehanshufanhuizifuchuanhaxidejieguoduijiujiubaersisisanwusanqumozhuyibuyaochuanrulzuobiaoshilingdeqingkuang(int l, int r) {
    return 0; // ...
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	aa[0] = bb[0] = 1;

    for (int i = 1; i < N; ++i) aa[i] = aa[i - 1] * xx, bb[i] = bb[i - 1] * vv;
	cin >> a >> b; for (char c : b) cc = cc * xx + c, dd = dd * vv + c;
	for (int i = 1, j = a.size() - 1; i <= a.size(); ++i, --j) {
		ee[i] = ee[i - 1] * xx + a[i - 1];
		ff[i] = ff[i - 1] * vv + a[i - 1];
		gg[i] = a[j] * aa[i - 1] + gg[i - 1];
		hh[i] = a[j] * bb[i - 1] + hh[i - 1];
	}
    for (int i = 0, j = a.size() - 1; i < a.size(); ++i, --j) {
		pair<t, t> t = qq(ee[i], ff[i], gg[j], hh[j], j);
		if (t.first == cc && t.second == dd) mq.push_back(i + 1);
	}
    printf("%d\n", mq.size());
	for (int i : mq)printf("%d ", i);
	return 0;
}
