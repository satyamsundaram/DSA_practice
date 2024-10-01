#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *links[26];
    bool flag = false;

    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, TrieNode *node) {
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }
};

class Solution {
    private:
        TrieNode *root;
        string ans = "", path = "";

        void dfs(TrieNode *node) {
            for(int i=0; i<26; i++) {
                if(!node->contains('a' + i) || !node->get('a' + i)->flag) continue;
                path += 'a' + i;
                if(path.size() > ans.size()) ans = path;
                dfs(node->get('a' + i));
                path.pop_back();
            }
        }

        void insert(string word) {
            TrieNode *node = root;
            for(char ch : word) {
                if(!node->contains(ch))
                    node->put(ch, new TrieNode());
                node = node->get(ch);
            }
            node->flag = true;
        }
    
    public:
        Solution() {
            root = new TrieNode();
        }
        
        // print the longest word whose all prefixes are present in the array
        // if two such words have same length, print the word which comes first in lexicographical order
        // if no such word exists, return an empty string

        // TC: O(length of vector * length of longest word) + O(length of longest word)
        // SC: O(length of vector * length of longest word)
        string longestWord(vector<string> &A) {
            for(string s : A)
                insert(s);
            
            dfs(root);
            return ans;
        }
};

int main() {
    Solution sol;
    vector<string> v = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << sol.longestWord(v) << endl;

    Solution sol2;
    v = {"w", "wo", "wor", "worl", "world"};
    cout << sol2.longestWord(v) << endl;

    Solution sol3;
    v = {"abc", "bc", "ab", "xyz"};
    cout << sol3.longestWord(v) << endl;
    return 0;
}