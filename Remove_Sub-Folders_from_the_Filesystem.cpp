#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;

        string prev = "";

        for (const string& f : folder) {
            // If 'f' is not a subfolder of 'prev'
            if (prev.empty() || f.compare(0, prev.size(), prev) != 0 || f[prev.size()] != '/') {
                result.push_back(f);
                prev = f;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> folders = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};

    vector<string> res = sol.removeSubfolders(folders);

    cout << "Resulting folders after removing subfolders:" << endl;
    for (const string& folder : res) {
        cout << folder << endl;
    }

    return 0;
}