class Solution{
public:
    long long reversedNumber(long long n){
        long long revNum = 0;
        while(n){
            int D = n%10;
            if(D == 6) D = 9;
            else if(D == 9) D = 6;
            n /= 10;
            revNum *= 10;
            revNum += D;
        }
        return revNum;
    }

    void generateNumbers(int pos, long long& num, int& len, int& confusingNumber, int& n, vector<int>& digit){
        if(num > n) return;
        if(pos >= len){
            if(num != reversedNumber(num)) confusingNumber++;
            return;
        }

        for(int i = 0; i < 5; i++){
            long long tempNum = num;
            num = num*10 + digit[i];
            generateNumbers(pos+1, num, len, confusingNumber, n, digit);
            num = tempNum;
        }
    }

    int confusingNumberII(int n){
        vector<int> digit{0, 1, 6, 8, 9};
        int confusingNumber = 0, len = log10(n) + 1;
        long long num = 0;
        generateNumbers(0, num, len, confusingNumber, n, digit);
        return confusingNumber;
    }
};
