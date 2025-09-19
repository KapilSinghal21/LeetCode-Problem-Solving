class Spreadsheet {
    vector<vector<int>> grid; // rows × 26
public:
    Spreadsheet(int rows) {
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        // formula format is always "=X+Y"
        string x, y;
        size_t plus = formula.find('+');
        x = formula.substr(1, plus - 1);
        y = formula.substr(plus + 1);
        return getTerm(x) + getTerm(y);
    }

private:
    int getTerm(const string &term) {
        if (isalpha(term[0])) {
            int col = term[0] - 'A';
            int row = stoi(term.substr(1)) - 1;
            return grid[row][col];
        }
        return stoi(term);
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */