class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hfinger = (hour*30)%360;
        double mfinger = minutes*6;
        hfinger += (minutes*0.5);
        double res = 0;
        res = abs(hfinger-mfinger);
        if(res >= 180) res = 360-res;
        return res;
    }
};
