class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        int freeday = 0;
        int prevday = 0;
        sort(meetings.begin(), meetings.end());
        for(auto meeting:meetings){
            int start = meeting[0];
            int end = meeting[1];
            if(start > prevday){
                freeday += start - prevday - 1;
            }
            prevday = max(prevday , end);
       }

       freeday +=  days - prevday ;
       return freeday;
    }
};


//  vector<bool>visited(days+1,false);
//         int n = meetings.size();
//         int m = meetings[0].size();

//         for(int i=0; i<n; i++){
//            for(int j= meetings[i][0]; j<=meetings[i][1]; j++){
//                 visited[j] = true;
//            }
//         }
//         int count = 0;
//         for(int i=1; i<visited.size(); i++){
//             if(visited[i] == false){
//                 count++;
//             }
//         }
//         return count;