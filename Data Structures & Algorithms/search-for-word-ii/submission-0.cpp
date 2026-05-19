class Solution {
public:
    struct TrieNode{
        TrieNode* children[26];
        string word = ""; // "TRICK" - bool isTerminal ki jaroorat nhi ..If this node marks the end of a word, we store the full string here.
        // This eliminates the need to pass a string builder around in DFS!
        
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
        }
    };
    int rows , cols;
    vector<string> res;

    void insertWord(TrieNode* root , string& word){
        TrieNode* curr = root;
        for(auto ch:word){
            int idx = ch-'a';

            if(!curr->children[idx]){// agar idx nhi mila
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word; // Mark the end of the word by storing the string itself
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* currNode){

        if (r < 0 || r >= rows || c < 0 || c >= cols|| board[r][c]=='#') return; // boundry check + '#' is vis marker

        char ch = board[r][c];
        int idx = ch-'a';

        if(!currNode->children[idx]) return; // If the current character doesn't exist as a branch in the Trie, stop exploring

        currNode = currNode->children[idx]; // Move the Trie pointer down to the child node

        if(!currNode->word.empty()){
            res.push_back(currNode->word);
            currNode->word = ""; // De-duplicate: Ensure we don't pick the same word again from a different grid path
        }

        // 4. Mark the current cell as visited using a lightweight placeholder
        board[r][c] = '#';

        // 5. Explore all 4 cardinal directions (Up, Down, Left, Right)
        dfs(board, r + 1, c, currNode); // Down
        dfs(board, r - 1, c, currNode); // Up
        dfs(board, r, c + 1, currNode); // Right
        dfs(board, r, c - 1, currNode); // Left

        // 6. Backtrack: Restore the original character so other paths can reuse it
        board[r][c] = ch;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){

        rows = board.size();
        cols = board[0].size(); 
        //"IMP" Variable Shadowing Fix: Do NOT re-declare with 'int' here. 
        // Directly modify class-level variables 'rows' and 'cols' so that the dfs() function can access the correct grid boundaries instead of reading uninitialized garbage values (which causes immediate return/empty output).
        
        res.clear(); // as res is class var so to remove last stings.safe side

        TrieNode* root = new TrieNode();

        for(string& word:words){
            insertWord(root, word); // init trie and insert all target words
        }

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                dfs(board , r,c,root);
            }
        }
        return res;
    }
};
