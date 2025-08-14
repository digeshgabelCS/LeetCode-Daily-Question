#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        
        for (int i = 0; i + 2 < (int)num.size(); ++i) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string curr = num.substr(i, 3);
                if (curr > ans) {
                    ans = curr;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    string num;
    
    cout << "Enter the number string: ";
    cin >> num;
    
    string result = sol.largestGoodInteger(num);
    if (result.empty()) {
        cout << "No good integer found." << endl;
    } else {
        cout << "Largest good integer: " << result << endl;
    }
    
    return 0;
}