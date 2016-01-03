class Solution {
public:
    int min(int c1, int c2, int c3, int c4) {
        int min_no = c1;

        if(c2 < min_no)
            min_no = c2;

        if(c3 < min_no)
            min_no = c3;

        if(c4 < min_no)
            min_no = c4;

        return min_no;

    }

    int minDistUtil(string word1, int i1, int j1, string word2, int i2, int j2) {
        int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX,c4=INT_MAX;

        if(j1 < 0) {
            return j2+1;
        } else if(j2 < 0) {
            return j1+1;
        } else {
            if(word1[j1] == word2[j2]) {
                c4 = minDistUtil(word1, i1, j1-1, word2, i2, j2-1); // Last Chars are equal.

            } else {
                c1 = 1 + minDistUtil(word1, i1, j1-1, word2, i2, j2);   // j1 deleted.
                c2 = 1 + minDistUtil(word1, i1, j1, word2, i2, j2-1);   // j2 deleted.
                c3 = 1 + minDistUtil(word1, i1, j1-1, word2, i2, j2-1); // Replace last chars.
            }  
            return min(c1, c2, c3, c4);
        }
    }

    int minDistance(string word1, string word2) {
        int w1len = word1.size()-1, w2len = word2.size()-1;

        if(w2len == 0) {
            return w1len;
        }

        if(w1len == 0)
            return w2len;
        
        return minDistUtil(word1, 0, w1len, word2, 0, w2len);
    }
};
