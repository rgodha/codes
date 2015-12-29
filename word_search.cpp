/* Solution  works:
 * If char's can be repeated in the given board.
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        map <char, vector<char> > m;
        vector <char> v;
        int arr[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int vlen = board.size(), hlen = board[0].size();
        int wlen = word.size();
        int i,j,k, New_i, New_j;

        for(i=0; i < vlen; i++) {
            for(j=0; j < hlen; j++) {
                /* Calculate the vector for each element in board */
                    for(k=0; k<4; k++) {
                        New_i = i + arr[k][0];
                        New_j = j + arr[k][1];
                        if(New_i>=0 && New_j>=0 && New_i < vlen && New_j < hlen) {
                            v.push_back(board[New_i][New_j]);

                            //cout << board[New_i][New_j];
                        }
                    }
                    //cout << endl;
                    if(m[board[i][j]].size() == 0) {
                        m[board[i][j]] = v;
                    } else {
                        m[board[i][j]].insert(m[board[i][j]].end(), v.begin(), v.end());
                    }
                    v.clear();
            }
        }

        /* If there is only 1 char in search word. */
        if(vlen == 1 && hlen == 1 && wlen == 1) {
            if((char)word[0] == (char)board[0][0]) {
                return true;
            }
        }

        if(m[word[0]].size() == 0) {
            return false;
        }

        /* Iterate over the created Vectors and get the path to given search string */
        map <char, vector<char> >::iterator itr;

        for(k=1; k < wlen; k++) {
            vector<char> r = m[word[k-1]];
            if(find(r.begin(), r.end(), word[k]) == r.end()) {
                return false;
            }
        }
        return true;
    }
};
