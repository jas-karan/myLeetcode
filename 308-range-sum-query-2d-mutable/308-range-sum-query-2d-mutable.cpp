class NumMatrix {
public:
    int r,c;
    vector<vector<int>>bit;
    
    int lsb(int v){
        return v & -v;
    }
    
    void updateBIT(int cr,int cc,int val){
        for(int i=cr;i<=r;i+=lsb(i)){
            for(int j=cc;j<=c;j+=lsb(j)){
                bit[i][j]+=val;
            }
        }
    }
    
    int queryBIT(int row,int col){
        int sum=0;
        
        for(int i=row;i>0;i-=lsb(i)){
            for(int j=col;j>0;j-=lsb(j)){
                sum+=bit[i][j];
            }
        }
        
        return sum;
    }
    
    void buildBIT(vector<vector<int>>&matrix){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                updateBIT(i,j,matrix[i-1][j-1]);
            }
        }
    }
    
    NumMatrix(vector<vector<int>>& matrix) {
        r=matrix.size();
        c=matrix[0].size();
        bit=vector<vector<int>>(r+1,vector<int>(c+1,0));
        
        buildBIT(matrix);
    }
    
    void update(int row, int col, int val) {
        int old = sumRegion(row,col,row,col);
        row++;col++; //1-indexing
        updateBIT(row,col,val-old);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;col1++;row2++;col2++;
        
        int a=queryBIT(row2,col2);
        int b=queryBIT(row1-1,col1-1);
        int c=queryBIT(row2,col1-1);
        int d=queryBIT(row1-1,col2);
        
        return (a+b)-(c+d);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */