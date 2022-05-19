class Solution {
    struct Node {
        Node *links[26];
        bool isWord = false;

        bool containsKey(char ch) {
            return links[ch-'a'] != NULL;
        }

        void put(char ch, Node *ref) {
            links[ch-'a'] = ref;
        }

        Node *get(char ch) {
            return links[ch-'a'];
        }

        void endWord() {
            isWord = true;
        }
    };
    
    Node *root = new Node();
    
    void insert(string word) {
        Node *dummy = root;
        for(char ch : word) {
            if(!dummy -> containsKey(ch)) {
                dummy -> put(ch, new Node());
            }
            dummy = dummy -> get(ch);
        }
        dummy -> endWord();
    }
    
    bool search(string word) {
        Node *dummy = root;
        for(char ch : word) {
            if(!dummy -> containsKey(ch))
                return false;
            dummy = dummy -> get(ch);
        }
        return dummy -> isWord;
    }
    
public:
    bool wordBreak(string s, vector<string>& words) {
        int n = s.length();
        vector<bool> dp(n + 1);
        for(string word : words) {
            insert(word);
        }
        
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j]) {
                    string word = s.substr(j, i - j);
                    if(search(word)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};