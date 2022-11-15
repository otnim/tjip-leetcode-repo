//TC: O(n)
//MC: O(n)

class Solution {
public:
    int calMatching(string word, string text){
        int matched = 0;
        for(int i = 0; word[i]; i++){
            matched += (word[i] == text[i]);
        }
        return matched;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        while(wordlist.size() > 1){
            int index = rand() % wordlist.size();
            int matched = master.guess(wordlist[index]);

            vector<string> matchedWords;
            for(string word : wordlist){
                if(calMatching(word, wordlist[index]) == matched){
                    matchedWords.push_back(word);
                }
            }
            wordlist = matchedWords;
        }
        master.guess(wordlist[0]);
    }
};


/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

