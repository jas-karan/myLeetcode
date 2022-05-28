class Solution {
public:
    struct TrieNode{
        bool endsHere;
        TrieNode* child[26];
    };
     
    TrieNode* getNode()
    {
        TrieNode* newNode=new TrieNode;
        newNode->endsHere=false;
        for(int i=0;i<26;++i)
        {
            newNode->child[i]=NULL;
        }
        return newNode;
    }
    
    TrieNode* root=getNode();
    
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}}; 
    
    void addWord(string word)
    {
        TrieNode* curr=root;
        for(int i=0;i<word.length();++i)
        {
            int ind=word[i]-'a';
            if(curr->child[ind]==NULL) 
                curr->child[ind]=getNode();
            curr=curr->child[ind];
        }
        curr->endsHere=true;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(auto word:words)
        {
            addWord(word);
        }
        
        
        vector<string> res;
        
        //search the words in the grid
        int rows=board.size();
        int cols=board[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(root->child[board[i][j]-'a']!=NULL){ //if a starting letter of a word exists in trie
                    checkWord(root->child[board[i][j]-'a'],board,i,j,res,"");
                }
            }
        }
        return res;
    }
    
    
    //check if the char exists in the board
    void checkWord(TrieNode* curr,vector<vector<char>>& board,int i,int j,vector<string>& res,string s)
    {
        
        s.push_back(board[i][j]);
        if(curr->endsHere)
        {
            //we have got a word
            res.push_back(s);
            curr->endsHere=false; //since  not to push again the same word from other possibility
        }
        char c=board[i][j];
        board[i][j]='#';
        
        for(int k=0;k<4;k++)
        {
            int x=dir[k][0]+i;
            int y=dir[k][1]+j;
            
            //dont move in these directions
            if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='#' || curr->child[board[x][y]-'a']==NULL)
                continue;
            checkWord(curr->child[board[x][y]-'a'],board,x,y,res,s);
        }
        board[i][j]=c;
        
        
    }
};