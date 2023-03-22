class Solution {
public:
        int uniquePaths(const int& m, const int& n) {
        std::vector<std::vector<int>> vec{{1}};
        int top, left;
        for (int i = 0; i < m; ++i) {
        vec.emplace_back();
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0)
            continue;

            top = i < 1 ? 0 : vec[i - 1][j];
            left = j < 1 ? 0 : vec[i][j - 1];

            vec[i].push_back(top + left);
        }
        }

        return vec[m - 1][n - 1];
    }
};

