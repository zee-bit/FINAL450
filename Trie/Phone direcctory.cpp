class Solution{
public:
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
    
    void dfs(Node *node, string &curr, vector<string> &res) {
        if(node -> isWord) {
            res.push_back(curr);
            // return;
        }
        
        for(int i = 0; i < 26; i++) {
            if(node -> links[i]) {
                curr += char(i + 97);
                dfs(node -> links[i], curr, res);
                curr.pop_back();
            }
        }
    }
    
    vector<string> startsWith(string prefix) {
        Node *dummy = root;
        for(char ch : prefix) {
            if(!dummy -> containsKey(ch))
                return {"0"};
            dummy = dummy -> get(ch);
        }
        vector<string> res;
        dfs(dummy, prefix, res);
        return res;
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        for(int i = 0; i < n; i++) {
            insert(contact[i]);
        }
        
        string str = "";
        vector<vector<string>> res;
        for(char ch : s) {
            str += ch;
            auto ret = startsWith(str);
            res.push_back(ret);
        }
        
        return res;
    }
};