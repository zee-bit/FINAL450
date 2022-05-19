struct Node {
    Node *link[2];
};

Node *root = new Node();

bool insert(int M[MAX][MAX], int r, int col) {
    bool diff = false;
    Node *dummy = root;
    for(int i = 0; i < col; i++) {
        if(dummy -> link[M[r][i]] == NULL) {
            dummy -> link[M[r][i]] = new Node();
            diff = true;
        }
        dummy = dummy -> link[M[r][i]];
    }
    return diff;
}

/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    vector<vector<int>> res;
    
    for(int i = 0; i < row; i++) {
        if(insert(M, i, col)) {
            vector<int> temp(M[i], M[i]+col);
            res.push_back(temp);
        }
    }
    return res;
}