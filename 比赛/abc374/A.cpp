#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void Main() {
    string str;
    cin >> str;
    if (str.size() < 3 || str.substr(str.size() - 3) != "san")
        puts("No");
    else
        puts("Yes");
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}

