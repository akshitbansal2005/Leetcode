class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> rows;
        for(auto seat : reservedSeats) {
            rows[seat[0]].push_back(seat[1]);
        }
        int families = (n -rows.size())*2;
        for(auto row:rows) {
            bool seatTaken[11] = {false};
            for(int seat :row.second) {
                seatTaken[seat] = true;
            }
            bool leftSide =true;
            bool middle =true;
            bool rightSide =true;
            for(int i = 2;i<=5; i++) {
                if(seatTaken[i]) {
                    leftSide = false;
                }
            }
            for(int i = 4; i <=   7; i++) {
                if(seatTaken[i]) {
                    middle = false;
                }
            }
            for(int i  =6; i  <=9; i++) {
                if(seatTaken[i]) {
                    rightSide = false;
                }
            }
            if(leftSide &&rightSide) {
                families += 2;
            }
            else if(leftSide||middle||rightSide) {
                families++;
            }
        }
        return families;
    }
};