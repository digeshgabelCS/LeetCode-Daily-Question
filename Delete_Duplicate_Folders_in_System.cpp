#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

/**
 * Deletes duplicate folders and their subfolders in a virtual file system.
 * Duplicate folders have the same subfolder structure.
 */
class Solution {
public:
    struct TrieNode {
        string name;
        map<string, TrieNode*> children;
        string serial;
        bool toDelete = false;
    };

    TrieNode* root = new TrieNode();

    /**
     * Inserts a path into the Trie representing the folder structure.
     */
    void insert(vector<string>& path) {
        TrieNode* node = root;
        for (const string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new TrieNode();
                node->children[folder]->name = folder;
            }
            node = node->children[folder];
        }
    }

    /**
     * Serializes each node's subtree to detect identical structures using post-order traversal.
     */
    string serialize(TrieNode* node, unordered_map<string, vector<TrieNode*>>& lookup) {
        if (node->children.empty()) return "";

        string serial;
        for (auto& [name, child] : node->children) {
            serial += "(" + name + serialize(child, lookup) + ")";
        }

        node->serial = serial;
        lookup[serial].push_back(node);
        return serial;
    }

    /**
     * Marks all duplicate subtrees for deletion.
     */
    void markDuplicates(unordered_map<string, vector<TrieNode*>>& lookup) {
        for (auto& [key, nodes] : lookup) {
            if (nodes.size() > 1) {
                for (TrieNode* node : nodes) {
                    node->toDelete = true;
                }
            }
        }
    }

    /**
     * Recursively collects remaining valid paths from the Trie.
     */
    void collectPaths(TrieNode* node, vector<string>& currentPath, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (child->toDelete) continue;
            currentPath.push_back(name);
            result.push_back(currentPath);
            collectPaths(child, currentPath, result);
            currentPath.pop_back();
        }
    }

    /**
     * Deletes duplicate folders and returns remaining paths.
     */
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path : paths) {
            insert(path);
        }

        unordered_map<string, vector<TrieNode*>> lookup;
        serialize(root, lookup);
        markDuplicates(lookup);

        vector<vector<string>> result;
        vector<string> currentPath;
        collectPaths(root, currentPath, result);
        return result;
    }
};

/**
 * Example usage with sample input.
 */
int main() {
    Solution solution;

    vector<vector<string>> paths = {
        {"a"},
        {"a", "x"},
        {"a", "x", "y"},
        {"a", "z"},
        {"b"},
        {"b", "x"},
        {"b", "x", "y"},
        {"b", "z"}
    };

    vector<vector<string>> result = solution.deleteDuplicateFolder(paths);

    cout << "Remaining folders:\n";
    for (const auto& path : result) {
        cout << "/";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << "/";
        }
        cout << "\n";
    }

    return 0;
}
