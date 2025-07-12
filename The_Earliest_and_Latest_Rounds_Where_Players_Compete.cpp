#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
private:
    template <typename A, typename B, typename C>
    struct TupleHash {
        size_t operator()(const tuple<A, B, C>& p) const {
            size_t seed = 0;
            A a; B b; C c;
            tie(a, b, c) = p;
            seed ^= hash<A>{}(a) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= hash<B>{}(b) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= hash<C>{}(c) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

    using Lookup = unordered_map<tuple<int, int, int>, vector<int>, TupleHash<int, int, int>>;

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        Lookup lookup;
        return memoization(n, firstPlayer - 1, n - secondPlayer, &lookup);
    }

private:
    vector<int> memoization(int t, int l, int r, Lookup *lookup) {
        if (lookup->count({t, l, r})) {
            return (*lookup)[{t, l, r}];
        }

        if (l == r) {
            return {1, 1};
        }

        if (l > r) {
            swap(l, r);
        }

        vector<int> result = {numeric_limits<int>::max(), 0};

        for (int i = 0; i <= l; ++i) {
            int nt = (t + 1) / 2;           
            int pair_cnt = t / 2;           
            int l_lose_cnt = l - i;
            int l_win_cnt = i + 1;

            int min_j = max(l_lose_cnt, r - (pair_cnt - l_lose_cnt));
            int max_j = min(r - l_win_cnt, (nt - l_win_cnt) - 1);

            if (min_j > max_j) continue;

            for (int j = min_j; j <= max_j; ++j) {
                const auto& tmp = memoization(nt, i, j, lookup);
                result[0] = min(result[0], tmp[0] + 1);
                result[1] = max(result[1], tmp[1] + 1);
            }
        }

        (*lookup)[{t, l, r}] = result;
        return result;
    }
};

int main() {
    Solution sol;
    int n = 11, firstPlayer = 2, secondPlayer = 4;
    vector<int> result = sol.earliestAndLatest(n, firstPlayer, secondPlayer);

    cout << "Earliest: " << result[0] << ", Latest: " << result[1] << endl;
    return 0;
}