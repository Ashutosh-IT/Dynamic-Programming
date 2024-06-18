/*

Geek is going for n day training program. He can perform any one of these three activities 
Running, Fighting, and Learning Practice. Each activity has some point on each day.
As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. 
Help Geek to maximize his merit points as you are given a 2D array of points points, corresponding to each day and activity.


*/



class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        int dpa[n];
        int dpb[n];
        int dpc[n];
        
        dpa[0] = points[0][0];
        dpb[0] = points[0][1];
        dpc[0] = points[0][2];
        
        for(int i=1; i<n; i++){
            dpa[i] = max(dpa[i-1],max(dpb[i-1]+points[i][0],dpc[i-1]+points[i][0]));
            dpb[i] = max(dpb[i-1],max(dpa[i-1]+points[i][1],dpc[i-1]+points[i][1]));
            dpc[i] = max(dpc[i-1],max(dpb[i-1]+points[i][2],dpa[i-1]+points[i][2]));
        }
        
        return max(dpa[n-1],max(dpb[n-1],dpc[n-1]));
    }
};
