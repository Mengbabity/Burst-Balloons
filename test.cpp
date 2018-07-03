class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int nn=nums.size();
            
        vector<int> array(nn+2,0);
        for(int i=1;i<=nn;i++)
        {
            array[i]=nums[i-1];
        }
        
        array[0]=1;
        array[nn+1]=1;
        
        int n=nn+2;
        int right=0;
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        for(int i=2;i<n;i++)
        {
            for(int left=0;left<n-i;left++)
            {
                right=left+i;
                for(int j=left+1;j<right;j++)
                {
                    dp[left][right]=max(dp[left][right],array[left]*array[j]*array[right]+dp[left][j]+dp[j][right]);
                }
            }
        }
        
        return dp[0][n-1];
	}
};
