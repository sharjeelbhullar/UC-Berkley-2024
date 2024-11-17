#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getRowCounts(const vector<string>& grid) {
    int n = grid.size();
    vector<int> rowCounts(n, 0);
    for (int i = 0; i < n; i++) {
        for (char c : grid[i]) {
            if (c == '#') rowCounts[i]++;
        }
    }
    return rowCounts;
}

pair<int, int> findHashtagRows(const vector<int>& rowCounts) {
    int n = rowCounts.size();
    int firstRow = -1, lastRow = -1;
    for (int i = 0; i < n; i++) {
        if (rowCounts[i] > 0) {
            if (firstRow == -1) firstRow = i;
            lastRow = i;
        }
    }
    return {firstRow, lastRow};
}

bool isRectangle(const vector<string>& grid) {
    vector<int> rowCounts = getRowCounts(grid);
    auto [firstRow, lastRow] = findHashtagRows(rowCounts);
    
    if (firstRow == -1) return false;
    
    int expectedCount = rowCounts[firstRow];
    for (int i = firstRow; i <= lastRow; i++) {
        if (rowCounts[i] != expectedCount) return false;
    }
    
    for (int i = firstRow; i <= lastRow; i++) {
        bool foundFirst = false;
        bool gap = false;
        for (char c : grid[i]) {
            if (c == '#') {
                if (gap) return false;  
                foundFirst = true;
            } else if (foundFirst) {
                gap = true;
            }
        }
    }
    
    return true;
}

bool isTriangle(const vector<string>& grid) {
    vector<int> rowCounts = getRowCounts(grid);
    auto [firstRow, lastRow] = findHashtagRows(rowCounts);
    
    if (firstRow == -1 || firstRow == lastRow) return false;
    
    int height = lastRow - firstRow + 1;
    
    bool isIncreasing = true;
    for (int i = 0; i < height; i++) {
        if (rowCounts[firstRow + i] != i + 1) {
            isIncreasing = false;
            break;
        }
    }
    if (isIncreasing) return true;
    
    bool isDecreasing = true;
    for (int i = 0; i < height; i++) {
        if (rowCounts[firstRow + i] != height - i) {
            isDecreasing = false;
            break;
        }
    }
    
    return isDecreasing;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        
        if (isTriangle(grid)) {
            cout << "phineas\n";
        } else if (isRectangle(grid)) {
            cout << "ferb\n";
        }
    }
    
    return 0;
}