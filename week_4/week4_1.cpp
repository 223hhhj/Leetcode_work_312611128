class Solution {
    public:
        double myPow(double x, int n) {
            // 處理特殊情況
            if (n == 0) return 1.0;
            if (x == 0) return 0.0;
            
            // 處理 INT_MIN 的特殊情況，避免溢出
            if (n == INT_MIN) {
                x = x * x;
                n = n / 2;
            }
            
            // 將負指數轉換為正指數處理
            double result = 1.0;
            long long absN = abs((long long)n);
            
            // 使用快速冪算法
            while (absN > 0) {
                if (absN & 1) {  // 如果當前位是1
                    result *= x;
                }
                x *= x;  // x 自乘
                absN >>= 1;  // 右移一位
            }
            
            // 如果指數是負數，取倒數
            return n < 0 ? 1 / result : result;
        }
    };