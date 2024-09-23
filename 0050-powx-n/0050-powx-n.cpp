class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) {
            return 1;
        }
        if (n == 0) {
            return 1;
        }

        long long exp = n;

        if (n < 0) {
            x = 1 / x;
            exp = abs(exp);
        }

        double res = 1.0;
        double product = x;

        while (exp > 0) { // odd
            if (exp % 2 == 1) {
                res *= product;
            }

            product *= product;

            exp=exp/2;
        }

        return res;
    }
};