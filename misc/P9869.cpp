#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

enum Value { T, F, U };

// Function to negate a value
Value negate(Value v) {
	if (v == T)
		return F;
	if (v == F)
		return T;
	return U;
}

// Function to process each test case
int processTestCase(int n, int m, const vector<pair<char, pair<int, int>>> &operations) {
	vector<Value> initial(n + 1, U);
	vector<Value> final(n + 1, U);
	vector<int> indegree(n + 1, 0);
	unordered_map<int, vector<pair<int, bool>>> adj; // adjacency list with negation flag

	// Process operations
	for (const auto &op : operations) {
		char type = op.first;
		int i = op.second.first;
		int j = op.second.second;

		if (type == 'T' || type == 'F' || type == 'U') {
			Value v = (type == 'T') ? T : (type == 'F') ? F : U;
			final[i] = v;
		} else if (type == '+') {
			adj[j].push_back({i, false});
			indegree[i]++;
		} else if (type == '-') {
			adj[j].push_back({i, true});
			indegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
			initial[i] = final[i];
		}
	}

	// Topological sort and propagate values
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (const auto& [v, isNegated] : adj[u]) {
			if (isNegated) {
				final[v] = negate(final[u]);
			} else {
				final[v] = final[u];
			}

			if (--indegree[v] == 0) {
				q.push(v);
				if (initial[v] == U)
					initial[v] = final[v];
			}
		}
	}

	// Count Unknowns
	int unknownCount = 0;
	for (int i = 1; i <= n; ++i) {
		if (initial[i] == U)
			unknownCount++;
	}

	return unknownCount;
}

int main() {
	int c, t;
	cin >> c >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<pair<char, pair<int, int>>> operations(m);
		for (int i = 0; i < m; ++i) {
			char op;
			int a, b = 0;
			cin >> op >> a;
			if (op == '+' || op == '-')
				cin >> b;
			operations[i] = {op, {a, b}};
		}

		cout << processTestCase(n, m, operations) << endl;
	}

	return 0;
}