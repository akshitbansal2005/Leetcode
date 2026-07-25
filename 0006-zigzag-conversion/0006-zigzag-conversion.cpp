class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;
        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;

            if (currRow == 0)
                goingDown = true;
            else if (currRow == numRows - 1)
                goingDown = false;

            if (goingDown)
                currRow++;
            else
                currRow--;
        }
        string result = "";
        for (int i = 0; i < numRows; i++) {
            result += rows[i];
        }
        return result;
    }
};
