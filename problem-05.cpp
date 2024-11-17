#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BridgeSolver {
private:
    long long calculateDanger(const vector<int>& buildings, int height) {
        long long danger = 0;
        for (int building : buildings) {
            if (building < height) {
                danger += (height - building);
            }
        }
        return danger;
    }
    
    long long calculateCost(const vector<int>& buildings, int height) {
        long long cost = 0;
        for (int building : buildings) {
            if (building > height) {
                cost += (building - height);
            }
        }
        return cost;
    }

public:
    void solve() {
        int T;
        cin >> T;
        
        while (T--) {
            int B, N;
            cin >> B >> N;
            
            vector<int> buildings(N);
            int maxHeight = 0;
            
            for (int i = 0; i < N; i++) {
                cin >> buildings[i];
                maxHeight = max(maxHeight, buildings[i]);
            }

            int bestHeight = 0;
            long long minDanger = 1e18;  
            long long minCost = 1e18;    
            
            for (int h = 1; h <= maxHeight; h++) {
                long long cost = calculateCost(buildings, h);
                
                if (cost <= B) {
                    long long danger = calculateDanger(buildings, h);
                    
                    if (danger < minDanger || (danger == minDanger && cost < minCost)) {
                        minDanger = danger;
                        minCost = cost;
                        bestHeight = h;
                    }
                }
            }
            
            cout << bestHeight << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    BridgeSolver solver;
    solver.solve();
    
    return 0;
}