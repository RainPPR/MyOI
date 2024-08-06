#define NDEBUG 1

#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned int;
using i32 = int;
using u64 = unsigned long long;
using i64 = long long;

#define endl "\n"

unordered_map<char, int> pri = {
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3},
};

struct node {
    int type;
    int pos;
    union {
        int num;
        char op;
    } val;
    node() = delete;
    node(int num, int pos): type(0), pos(pos) { val.num = num; }
    node(char op, int pos): type(1), pos(pos) { val.op = op; }
};

string str;

int tot;

stack<int> op;

vector<node> res;

int spare[510];

void eval() {
    res.emplace_back(str[op.top()], spare[op.top()]);
    op.pop();
}

void init() {
    int n = str.size();
    for (int i = 0; i < n; ++i) {
        if (isalpha(str[i])) res.emplace_back((int)str[i] - 'a', tot++);
        else if (str[i] == '(') op.emplace(i);
        else if (str[i] == ')') {
            while (str[op.top()] != '(') eval();
            op.pop();
        }
        else if (str[i] == '^') op.emplace(i), spare[i] = tot++;
        else {
            while (!op.empty() && pri[str[op.top()]] >= pri[str[i]]) eval();
            op.emplace(i), spare[i] = tot++;
        }
    }
    while (!op.empty()) eval();
}

int dep[510], fa[510];
int son[510][2], maxdep;

void dfs(int l, int r) {
    int c_op = 0, c_num = 0;
    for (int i = r - 1; i >= l; --i) {
        if (res[i].type) ++c_op;
        else ++c_num;
        if (c_num == c_op + 1) {
            fa[i - 1] = fa[r - 1] = r;
            dep[i - 1] = dep[r - 1] = dep[r] + 1;
            maxdep = max(maxdep, dep[r] + 1);
            son[r][0] = i - 1, son[r][1] = r - 1;
            dfs(l, i - 1), dfs(i, r - 1);
            return;
        }
    }
}

string mp[810];

pair<int, int> get_pos(int i) {
    return make_pair(dep[i] * 2, 3 * res[i].pos);
}

void solev() {
    init();
    dfs(0, res.size() - 1);
    string __;
    for (int i = 1; i <= 3 * int(str.size()); ++i) __.push_back(' ');
    for (int i = 0; i <= 2 * maxdep; ++i) mp[i] = __;
    for (int i = 0; i < (int)res.size(); ++i) {
        auto t = get_pos(i);
        int x = t.first, y = t.second;
        if (son[i][0] + son[i][1]) {
            auto tl = get_pos(son[i][0]);
            auto tr = get_pos(son[i][1]);
            int yl = tl.second, yr = tr.second;
            for (int i = yl + 1; i < yr; ++i) mp[x][i] = '-';
            mp[x][yl] = mp[x][yr] = '.';
        }
        if (res[i].type) mp[x][y] = res[i].val.op, mp[x][y - 1] = '[', mp[x][y + 1] = ']';
        else mp[x][y] = char(res[i].val.num + 'a');
        if (x) mp[x - 1][y] = '|';
    }
    for (int i = 0; i <= maxdep * 2; ++i) {
        while (!mp[i].empty() && mp[i].back() == ' ') mp[i].pop_back();
        cout << mp[i] << endl;
    }
}

signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> str, solev();
    return 0;
}
