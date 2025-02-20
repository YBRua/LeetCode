class Solution {
   public:
    double myPow(double x, int n) {
        long nn = n;
        bool inverse = false;
        if (n < 0) {
            inverse = true;
            nn = -nn;
        }

        double res = 1;
        double base = x;

        while (nn > 0) {
            if (nn % 2) {
                res *= base;
            }
            base *= base;
            nn /= 2;
        }

        if (inverse) {
            res = 1 / res;
        }

        return res;
    }
};
