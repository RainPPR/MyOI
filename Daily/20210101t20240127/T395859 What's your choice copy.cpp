#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals[i] = make_pair(l, r);
    }

    int maxResult = 0;

    for (int bit = 31; bit >= 0; bit--) {
        int mask = (1 << bit);

        vector<int> possibleValues;
        for (const auto& interval : intervals) {
            if ((interval.first & mask) == (interval.second & mask)) {
                possibleValues.push_back(interval.first & mask);
            }
        }

        if (!possibleValues.empty()) {
            int result = maxResult | mask;

            for (int value : possibleValues) {
                result = max(result, maxResult | value);
            }

            maxResult = result;
        }
    }

    cout << maxResult << endl;

    return 0;
}