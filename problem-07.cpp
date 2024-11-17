#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class IslandSolver {
private:
    int N, M;
    vector<vector<int>> grid;
    
    bool isValid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    
    void dfs(int x, int y, vector<vector<bool>>& visited, int height) {
        if (!isValid(x, y) || visited[x][y] || grid[x][y] < height) {
            return;
        }
        
        visited[x][y] = true;

        dfs(x + 1, y, visited, height);
        dfs(x - 1, y, visited, height);
        dfs(x, y + 1, visited, height);
        dfs(x, y - 1, visited, height);
    }
    
    int countIslands(int height) {
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        int islands = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && grid[i][j] >= height) {
                    bool isValidIsland = false;
                    
                    const int dx[] = {0, 1, 0, -1};
                    const int dy[] = {1, 0, -1, 0};
                    
                    for (int k = 0; k < 4; k++) {
                        int newX = i + dx[k];
                        int newY = j + dy[k];
                        
                        if (isValid(newX, newY) && grid[newX][newY] < height) {
                            isValidIsland = true;
                            break;
                        }
                    }
                    
                    if (isValidIsland) {
                        islands++;
                    }
                    
                    dfs(i, j, visited, height);
                }
            }
        }
        
        return islands;
    }

public:
    void solve() {
        int T;
        cin >> T;
        
        while (T--) {
            cin >> N >> M;
            
            grid = vector<vector<int>>(N, vector<int>(M));
            set<int> heights;
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cin >> grid[i][j];
                    heights.insert(grid[i][j]);
                }
            }
            
            int maxIslands = 0;
            for (int height : heights) {
                int islands = countIslands(height);
                maxIslands = max(maxIslands, islands);
            }
            
            cout << maxIslands << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    IslandSolver solver;
    solver.solve();
    
    return 0;
}