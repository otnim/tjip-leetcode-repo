//TC: O(n), where n <= 10000
//MC: O(n)

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string finalQuotient = (numerator * 1LL * denominator) < 0LL ? "-" : "";

        long long _numerator = abs(numerator);
        long long _denominator = abs(denominator);
        long long quotient = _numerator / _denominator;

        finalQuotient += to_string(quotient);

        long long remainder = _numerator % _denominator;

        _numerator = (_numerator % _denominator);

        vector<pair<long long, long long>> dividendQuotient;
        unordered_map<long long, int> rem;
        int resStart, isRecurr = 0, isIntegerQuotient = 1;

        while(_numerator % _denominator){
            isIntegerQuotient = 0;
            long long dividend = _numerator;
            _numerator *= 10;

            quotient = _numerator / _denominator;
            long long remainder = _numerator % _denominator;

            dividendQuotient.push_back({dividend, quotient});
            rem[dividend]++;

            _numerator = _numerator % _denominator;

            if(rem.count(remainder)){
                resStart = remainder;
                isRecurr = 1;
                break;
            }
        }
        if(!isIntegerQuotient) finalQuotient.push_back('.');

        for(auto it : dividendQuotient){
            if(isRecurr && it.first == resStart){
                finalQuotient.push_back('(');
            }
            finalQuotient.push_back(char(it.second + '0'));
        }
        if(isRecurr) finalQuotient.push_back(')');

        return finalQuotient;
    }
};
