class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int indx=-1;
        int maxi=INT_MAX;
        int dx=target[0], dy=target[1];
        for(int i=0;i<drones.size();i++){
            int x=drones[i][0], y=drones[i][1], z=drones[i][2];
            int dis=abs(dx-x)+abs(dy-y);
            if(dis<=z&& dis<maxi){
                maxi=dis;
                indx=i;
            }
        }
        return indx;
    }
};