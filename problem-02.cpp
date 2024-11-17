#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double minimum_time_to_exit(int N, int H, int D, int S, int P) {
    double run_time = (double)D / S;
    double health_after_run = N - run_time * P;

    if (health_after_run >= 0) {
        return run_time;
    }

    double min_time = -1.0; 
    double healing_time = 0.0;  

    while (healing_time <= (double)D / S) {
        double health_after_heal = N + healing_time * (H - P);

        if (health_after_heal <= 0) {
            break; 
        }

        double run_time_after_healing = (double)D / S;
        double total_time = healing_time + run_time_after_healing;

        if (health_after_heal - run_time_after_healing * P >= 0) {
            min_time = (min_time == -1.0) ? total_time : min(min_time, total_time);
        }

        healing_time += 0.01;
    }

    return min_time;
}

int main() {
    int T;
    cin >> T;  

    // Process each test case
    while (T--) {
        int N, H, D, S, P;
        cin >> N >> H >> D >> S >> P;  // Input N, H, D, S, P for each test case

       
        double result = minimum_time_to_exit(N, H, D, S, P);

        // Output the result for this test case
        if (result == -1.0) {
            cout << -1.0 << endl;
        } else {
            printf("%.1f\n", result);  // Output the result rounded to 1 decimal place
        }
    }

    return 0;
}
