//TC: O(NlogN), N := 10000000
//MC: O(1)

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo = 1, hi = 10000000, speed, minSpeed = -1;

        while(lo <= hi){
            speed = lo + (hi - lo)/2;
            double timeNeed = 0.0, d;

            for(int i = 0; i < dist.size(); i++){
                d = dist[i]*1.0;
                timeNeed += ceil(d/speed);
            }
            timeNeed = timeNeed - ceil(d/speed) + d/speed; //for last train

            if(timeNeed <= hour){
                minSpeed = speed;
                hi = speed - 1;
            }
            else lo = speed + 1;
        }
        return minSpeed;
    }
};
