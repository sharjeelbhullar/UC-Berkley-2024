#include <iostream>
#include <iomanip>
using namespace std;

double solveStormProblem(int N, int H, int D, int S, int P) {
    if (H <= P) {
        double timeToRun = (double)D / S;
        
        double totalDamage = timeToRun * P;
        
        if (totalDamage <= N) {
            return timeToRun;
        }
        return -1.0;
    }
    

    double healingTime = (P * (double)D/S - N) / (H - P);
    
    if (healingTime < 0) {
        return (double)D / S;
    }
    
    double totalTime = healingTime + (double)D / S;
    
    double finalHealth = N + (H-P)*healingTime - P*(D/(double)S);
    if (finalHealth < -0.000001) { 
        return -1.0;
    }
    
    return totalTime;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, H, D, S, P;
        cin >> N >> H >> D >> S >> P;
        
        double result = solveStormProblem(N, H, D, S, P);
        
        cout << fixed << setprecision(1) << result << endl;
    }
    
    return 0;
}