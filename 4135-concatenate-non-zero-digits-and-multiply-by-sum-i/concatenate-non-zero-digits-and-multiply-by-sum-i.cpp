class Solution {
public:
    long long sumAndMultiply(int n) {
        long long concatenatedNumber = 0;
        long long digitSum = 0;

        string number = to_string(n);

        for (char digit : number) {
            if (digit != '0') {
                int currentDigit = digit - '0';
                concatenatedNumber = concatenatedNumber * 10 + currentDigit;
                digitSum += currentDigit;
            }
        }

        return concatenatedNumber * digitSum;
    }
};