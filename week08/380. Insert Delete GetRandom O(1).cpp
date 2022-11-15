//TC: O(query)
//MC: O(query)

class RandomizedSet {
    unordered_map<long long, long long> mp, index;
    long long MIN = -100000000000;
    long long k = 0;
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        k = fmax(0, k);
        long long curVal = val*1LL;
        if(!mp.count(curVal) || mp[curVal] == MIN) {
            mp[curVal] = ++k;
            index[k] = curVal;
            return true;
        }
        else return false;
    }

    bool remove(int val) {
        long long curVal = val*1LL;
        if(!mp.count(curVal) || mp[curVal] == MIN) return false;
        else {
            long long removeIdx = mp[curVal]; // kon index e ache
            mp[curVal] = MIN;
            long long lastValue = index[k];
            index[removeIdx] = lastValue;
            if(k != removeIdx) mp[lastValue] = removeIdx;
            --k;
            k = fmax(0, k);
            return true;
        }
    }

    int getRandom() {
        k = fmax(1, k);
        long long ret = 1 + rand()%k;
        return index[ret];
    }
};
