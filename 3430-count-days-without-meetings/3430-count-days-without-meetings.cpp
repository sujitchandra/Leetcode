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


