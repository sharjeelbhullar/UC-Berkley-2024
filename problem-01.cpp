#include <iostream>
using namespace std;

void solve(string S) {
    for (size_t i = 0; i < S.length(); ++i) {
        // Check for "O"
        if (S[i] == 'O') {
            cout << "[###OREO###]" << endl;
        }
        // Check for "RE"
        else if (i + 1 < S.length() && S.substr(i, 2) == "RE") {
            cout << " [--------]" << endl;
            i++; // Skip the next character since "RE" takes two
        }
        // Check for "&"
        else if (S[i] == '&') {
            cout << endl;
        }
    }
}
    
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string S;
        cin >> S;
        solve(S);
        cout << endl;
    }
}

