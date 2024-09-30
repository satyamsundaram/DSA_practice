#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool flag = false;

    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
    private:
        Node *root;

    public:
        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* node = root;
            for(int i=0; i<word.size(); i++) {
                if(!node->contains(word[i]))
                    node->put(word[i], new Node());
                node = node->get(word[i]);
            }
            node->flag = true;
        }

        bool search(string word) {
            Node *node = root;
            for(int i=0; i<word.size(); i++) {
                if(!node->contains(word[i]))
                    return false;
                node = node->get(word[i]);
            }
            return node->flag;
        }

        bool startsWith(string prefix) {
            Node *node = root;
            for(int i=0; i<prefix.size(); i++) {
                if(!node->contains(prefix[i]))
                    return false;
                node = node->get(prefix[i]);
            }
            return true;
        }
};

int main() {
    Trie trie;
    cout << "Inserting words: apple, apps, application, apparel, appa" << endl;
    trie.insert("apple");
    trie.insert("apps");
    trie.insert("application");
    trie.insert("apparel");
    trie.insert("appa");

    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.search("appa") << endl;
    
    cout << trie.startsWith("app") << endl;
    cout << trie.startsWith("appa") << endl;
    cout << trie.startsWith("apa") << endl;
    
    return 0;
}