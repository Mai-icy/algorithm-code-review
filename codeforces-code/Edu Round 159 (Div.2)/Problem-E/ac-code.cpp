#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    int count;
    TrieNode *next[26];
    TrieNode() : count(0){
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        } 
    }
    ~TrieNode() {
        for (auto& ptr : next) {
            delete ptr;
        }
    }
};

class Trie {
public:
    TrieNode * root;
    long long result;

    
    Trie() {
        root = new TrieNode();
        result = 0; 
    }

    ~Trie() {
        delete root;
    }

    void insert(const string::iterator & begin, const string::iterator & end) {
        TrieNode *now = root;
        for (auto it = begin; it != end; it++) {
            int pos = *it - 'a';
            if (!now->next[pos]) 
                now->next[pos] = new TrieNode();

            now->next[pos] -> count++;
            now = now->next[pos];
        }
    }

    void calculate(const string::reverse_iterator & begin, const string::reverse_iterator & end){
        TrieNode *now = root;
        for (auto it = begin; it != end; it++) {
            int pos = *it - 'a';
            if (!now->next[pos]) 
                return;
            result += (now -> next[pos] -> count) * 2;
            now = now->next[pos];
        }
    }

};

int main() {
    int stringNum;
    cin >> stringNum;
    long long result = 0;
    Trie TrieTree;
    
    vector<string> strs(stringNum);
    for(int i = 0; i < stringNum; i++){
        cin >> strs[i];
        result += strs[i].size();
        TrieTree.insert(strs[i].begin(), strs[i].end());
    }

    result *= 2 * stringNum;

    for(int i = 0; i < stringNum; i++){
        TrieTree.calculate(strs[i].rbegin(), strs[i].rend());
    }
    
    result -= TrieTree.result;

    cout << result << endl;
}


