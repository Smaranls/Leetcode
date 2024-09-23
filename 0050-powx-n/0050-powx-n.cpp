class Solution {
public:
    double myPow(double x, int n) {
        // Handle the case when n is 0
        if (n == 0) return 1.0;

        // Use long long to handle the edge case of INT_MIN
        long long exp = n; 
        if (n < 0) {
            x = 1.0 / x; // Take reciprocal of x
            exp = -exp; // Make exp positive
        }

        double result = 1.0;
        double current_product = x;

        while (exp > 0) {
            // If exp is odd, multiply the result by the current product
            if (exp % 2 == 1) {
                result *= current_product;
            }
            // Square the current product
            current_product *= current_product;
            // Divide exp by 2
            exp /= 2;
        }

        return result;
    }
};
