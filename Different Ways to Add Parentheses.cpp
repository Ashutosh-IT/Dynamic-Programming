/*

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. 
You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2

*/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> numbers;
        unordered_map<int,char> mp;
        int n = expression.size();

        int count = 0;

        int i=0;
        while(i<n){
            int num = expression[i]-'0';
            if((i+1)<n && expression[i+1] >= '0' && expression[i+1] <= '9'){
                num = num*10 + (expression[i+1] - '0');
                i += 2;
            }
            else{
                i++;
            }
            numbers.push_back(num);
            if(i<n){
                mp[count] = expression[i];
                count++;
            }
            i++;
        }

        int m = numbers.size();
        vector<int> dp[m][m];

        // size 1
        for(int i=0; i<m; i++)
        dp[i][i] = {numbers[i]};

        // size 2
        for(int i=0; i<m-1; i++){
            char ch = mp[i];
            if(ch == '+')
            dp[i][i+1] = {numbers[i] + numbers[i+1]};

            else if(ch == '-')
            dp[i][i+1] = {numbers[i] - numbers[i+1]};

            else dp[i][i+1] = {numbers[i] * numbers[i+1]};
        }

        // size >= 3
        int length = 3;

        while(length <= m){
            for(int i=0; i<=m-length; i++){
                int end = i+length-1;
                vector<int> ans;
                for(int j=i; j<=end-1; j++){
                    vector<int> left = dp[i][j];
                    vector<int> right = dp[j+1][end];

                    char ch = mp[j];
                    for(int x=0; x<left.size(); x++){
                        for(int y=0; y<right.size(); y++){
                            if(ch == '+')
                            ans.push_back(left[x] + right[y]);
                            else if(ch == '-')
                            ans.push_back(left[x] - right[y]);
                            else ans.push_back(left[x] * right[y]);
                        }
                    }

                    dp[i][end] = ans;
                }
            }

            length++;
        }
    

        return dp[0][m-1];
    }
};
