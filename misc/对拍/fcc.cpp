#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(0));

int n, q, mw;

namespace gen {
    bool Main() {
        ofstream fout("dat.in");
        fout << n << " " << q << endl;
        for (int i = 2; i <= n; ++i) {
            int v = rnd() % (i - 1) + 1;
            int w = rnd() % mw;
            fout << i << " " << v << " " << w << endl;
        }
        for (int i = 1; i <= q; ++i) {
            int u = rnd() % n + 1;
            int v = rnd() % n + 1;
            fout << u << " " << v << endl;
        }
        fout.close();
        return true;
    }
}

namespace run {
    bool Main() {
        system("my.exe<dat.in>dat.out");
        system("std.exe<dat.in>dat.ans");
        return system("fc dat.ans dat.out /n");
    }
}

namespace solve {
    bool Main() {
        assert(gen::Main());
        return !run::Main();
    }
}

signed main() {
    ifstream fin("setting.txt");
    fin >> n >> q >> mw;
    fin.close();
    system("del /f /q my.exe");
    system("del /f /q std.exe");
    system("g++ my.cpp -o my.exe -std=c++14 -O2");
    system("g++ std.cpp -o std.exe -std=c++14 -O2");
    while (true)
        if (!solve::Main())
            break;
    puts("WA");
    return 0;
}