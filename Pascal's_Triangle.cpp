#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1); // initialize row of size i+1 with all 1s

            // Fill the inner elements
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};

int main() {
    int numRows;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> numRows;

    Solution sol;
    vector<vector<int>> result = sol.generate(numRows);

    // Print the Pascal's Triangle
    cout << "\nPascal's Triangle with " << numRows << " rows:\n";
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}