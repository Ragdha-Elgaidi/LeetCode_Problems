class Solution
 {
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        int m=mat.size(),n=mat[0].size(),c=0;
        vector<int> rowZ(m,0);
        vector<int> colZ(n,0);

        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if (mat[i][j] == 0)
                 {
                    rowZ[i]++;
                    colZ[j]++;
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
           { 
                   if(mat[i][j]==1 && rowZ[i]==n-1  && colZ[j]==m-1) 
                   {
                       c++;
                       }
            }
        }
        return c;
    }
};
