#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_set<string> us;

    public:
        // // naive: run nested for loops to check all substrings and store them in a set for uniqueness
        // // max substrings for a string = n(n+1)/2
        // // TC: O(n^3); SC: O(n^2)
        // int distinctSubstring(string s) {
        //     int n = s.size();
        //     for (int i = 0; i < n; i++) {
        //         for (int j = i; j < n; j++) {
        //             us.insert(s.substr(i, j - i + 1));
        //         }
        //     }
        //     return us.size();
        // }

        // using trie
        // TC: O(); SC: O()
        int distinctSubstring(string s) {
            
        }
};

int main() {
    Solution sol;
    string s = "aabbaba";
    cout << sol.distinctSubstring(s) << endl;

    Solution sol2;
    s = "abcdefg";
    cout << sol2.distinctSubstring(s) << endl;

    Solution sol3;
    s = "abdufyejfbcbajqieotghshahsyurtyvbvndjsiwurotpabdufyejfbcbajqieotghshahsyurtyvbvndjsiwurotpabdufyejfbcbajqieotghshahsyurtyvbvndjsiwurotp";
    cout << sol3.distinctSubstring(s) << endl;

    return 0;
}