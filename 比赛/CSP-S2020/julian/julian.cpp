#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

#define int ll

constexpr int check(int year) {
    if (year < 0)
        ++year;
    if (year <= 1582)
        return year % 4 == 0;
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

constexpr int days[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

constexpr int getdays(int year, int month) {
    return days[month] + (month == 2 && check(year));
}

constexpr int yeardays(int year) {
    if (year == 1582)
        return 355;
    return 365 + check(year);
}

struct datemeow {
    int y, m, d;
    datemeow(): y(-4713), m(1), d(1) {}
    datemeow(int a, int b, int c): y(a), m(b), d(c) {}
    friend bool operator ==(const datemeow &a, const datemeow &b) {
        return a.y == b.y && a.m == b.m && a.d == b.d;
    }
    friend datemeow next(datemeow a) {
        if (a == datemeow(1582, 10, 4))
            a = datemeow(1582, 10, 15);
        else if (a == datemeow(-1, 12, 31))
            a = datemeow(1, 1, 1);
        else if (a.d < getdays(a.y, a.m))
            ++a.d;
        else if (a.m < 12)
            a.d = 1, ++a.m;
        else
            a = datemeow(a.y + 1, 1, 1);
        return a;
    }
    friend datemeow nextyear(datemeow a) {
        if (a.y == -1)
            a.y = 1;
        else
            ++a.y;
        return a;
    }
    friend ostream& operator <<(ostream &out, datemeow a) {
        out << a.d << " " << a.m << " " << abs(a.y);
        if (a.y < 0)
            out << " BC";
        return out;
    }
};

map<int, datemeow> jump{
    {0, datemeow()},
    {50000, datemeow(-4577, 11, 22)},
    {100000, datemeow(-4440, 10, 14)},
    {150000, datemeow(-4303, 9, 5)},
    {200000, datemeow(-4166, 7, 28)},
    {250000, datemeow(-4029, 6, 18)},
    {300000, datemeow(-3892, 5, 10)},
    {350000, datemeow(-3755, 4, 1)},
    {400000, datemeow(-3618, 2, 21)},
    {450000, datemeow(-3481, 1, 13)},
    {500000, datemeow(-3345, 12, 4)},
    {550000, datemeow(-3208, 10, 26)},
    {600000, datemeow(-3071, 9, 17)},
    {650000, datemeow(-2934, 8, 9)},
    {700000, datemeow(-2797, 6, 30)},
    {750000, datemeow(-2660, 5, 22)},
    {800000, datemeow(-2523, 4, 13)},
    {850000, datemeow(-2386, 3, 5)},
    {900000, datemeow(-2249, 1, 25)},
    {950000, datemeow(-2113, 12, 16)},
    {1000000, datemeow(-1976, 11, 7)},
    {1050000, datemeow(-1839, 9, 29)},
    {1100000, datemeow(-1702, 8, 21)},
    {1150000, datemeow(-1565, 7, 12)},
    {1200000, datemeow(-1428, 6, 3)},
    {1250000, datemeow(-1291, 4, 25)},
    {1300000, datemeow(-1154, 3, 17)},
    {1350000, datemeow(-1017, 2, 6)},
    {1400000, datemeow(-881, 12, 28)},
    {1450000, datemeow(-744, 11, 19)},
    {1500000, datemeow(-607, 10, 11)},
    {1550000, datemeow(-470, 9, 2)},
    {1600000, datemeow(-333, 7, 24)},
    {1650000, datemeow(-196, 6, 15)},
    {1700000, datemeow(-59, 5, 7)},
    {1750000, datemeow(79, 3, 29)},
    {1800000, datemeow(216, 2, 18)},
    {1850000, datemeow(353, 1, 9)},
    {1900000, datemeow(489, 12, 1)},
    {1950000, datemeow(626, 10, 23)},
    {2000000, datemeow(763, 9, 14)},
    {2050000, datemeow(900, 8, 5)},
    {2100000, datemeow(1037, 6, 27)},
    {2150000, datemeow(1174, 5, 19)},
    {2200000, datemeow(1311, 4, 10)},
    {2250000, datemeow(1448, 3, 1)},
    {2300000, datemeow(1585, 1, 31)}
};

void Main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t < 2305448) {
            auto it = prev(jump.upper_bound(t));
            t -= it->first;
            datemeow a = it->second;
            while ((a.m != 1 || a.d != 1) && t)
                a = next(a), --t;
            while (t >= yeardays(a.y))
                t -= yeardays(a.y), a = nextyear(a);
            while (t)
                a = next(a), --t;
            cout << a << endl;
        }
        else {
            t -= 2305448;
            int meow = t / 146097;
            t %= 146097;
            datemeow a = datemeow(meow * 400 + 1600, 1, 1);
            while (t >= yeardays(a.y))
                t -= yeardays(a.y), a = nextyear(a);
            while (t)
                a = next(a), --t;
            cout << a << endl;
        }
    }
    return;
}

signed main() {
    // freopen("juian.in", "r", stdin);
    // freopen("juian.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}
