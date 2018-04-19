#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0)
            return 0;

        int m=matrix[0].size();



        int dp[n][m][4];
        int scale;


        dp[0][0][0]=0;
        dp[0][0][1]=0;
        dp[0][0][2]=0;
        dp[0][0][3]=0;

        if(matrix[0][0]=='1'){
            dp[0][0][0]=1;
            dp[0][0][1]=1;
            dp[0][0][2]=1;
            dp[0][0][3]=1;
        }


        scale=dp[0][0][0]*dp[0][0][1];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    continue;
                }

                if(matrix[i][j]=='0'){
                    dp[i][j][0]=0;
                    dp[i][j][1]=0;
                    dp[i][j][2]=0;
                    dp[i][j][3]=0;
                }
                else{
                    if(i==0 && j!=0){
                        dp[i][j][0]=dp[i][j-1][0]+1;
                        dp[i][j][1]=1;
                        dp[i][j][2]=dp[i][j-1][2]+1;
                        dp[i][j][3]=1;
                    }
                    else if(j==0){
                        dp[i][j][0]=1;
                        dp[i][j][1]=dp[i-1][j][1]+1;
                        dp[i][j][2]=1;
                        dp[i][j][3]=dp[i-1][j][3]+1;
                    }
                    else{
                        dp[i][j][0]=dp[i][j-1][0]+1;
                        dp[i][j][1]=min(dp[i][j-1][1],dp[i-1][j][1]+1);
                        dp[i][j][2]=min(dp[i][j-1][2]+1,dp[i-1][j][2]);
                        dp[i][j][3]=dp[i-1][j][3]+1;

                        dp[i][j][1]=dp[i][j][1]==0? dp[i][j][3]:dp[i][j][1];
                        dp[i][j][2]=dp[i][j][2]==0?dp[i][j][1]:dp[i][j][2];

                    }


                }
                scale=max(scale,dp[i][j][0]*dp[i][j][1]);
                scale=max(scale,dp[i][j][2]*dp[i][j][3]);
                cout<<" :"<<dp[i][j][0]<<" :"<<dp[i][j][1]<<" :"<<dp[i][j][2]<<" :"<<dp[i][j][3]<<endl;

            }
       }

       return scale;
    }
};

int main(){
        vector<vector<char>> ma;
        int n=4;
        int m=5;

        char x;
        for(int i=0;i<n;i++){
                vector<char> mm;
                for(int j=0;j<m;j++){
                        cin>>x;
                        mm.push_back(x);
                }
                ma.push_back(mm);
        }

        Solution xxxx;
        cout<<xxxx.maximalRectangle(ma);

        return 0;
}
