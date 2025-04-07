/*
Problem: Minimize Max Distance to Gas Station

You are given a sorted array 'stations' of length 'n', where each element denotes
the position of a gas station on the X-axis. You are also given an integer 'k', 
representing the number of new gas stations you can add.

Your task is to find the minimum possible value of the maximum distance between 
any two adjacent gas stations after adding 'k' new stations optimally. The new 
gas stations can be placed at any position (even non-integer).

Input:
- First line contains two integers 'n' and 'k'
- Second line contains 'n' sorted integers representing gas station positions

Output:
- A floating-point value representing the minimized maximum distance. 
- Accuracy of 1e-6 is required.

Example:
Input:
5 4
1 2 3 4 5

Output:
0.5
*/

#include <bits/stdc++.h>
using namespace std;

// Function to calculate how many new gas stations are needed if we want no distance
// between two adjacent stations to be more than 'maxDist'
int calculateRequiredStations(const vector<int> &stations, long double maxDist) {
    int required = 0;
    for (int i = 0; i < stations.size() - 1; ++i) {
        long double gap = stations[i + 1] - stations[i];
        int stationsInGap = floor(gap / maxDist);
        if (gap == stationsInGap*maxDist) {
            stationsInGap--;  // Avoid placing one extra if it divides perfectly
        }
        required += stationsInGap;
    }
    return required;
}

// Function to find the minimized maximum distance using Binary Search
double minimizeMaxDistance(vector<int> &stations, int k) {
    int n = stations.size();
    long double low = 0, high = 0;

    // Calculate the maximum initial gap between adjacent stations
    for (int i = 0; i < n - 1; ++i) {
        high = max(high, (long double)(stations[i + 1] - stations[i]));
    }

    long double precision = 1e-6;

    // Binary Search to find the optimal value of the maximum allowed distance
    while ((high - low) > precision) {
        long double mid = (low + high) / 2.0;
        int requiredStations = calculateRequiredStations(stations, mid);

        if (requiredStations > k) {
            low = mid;  // Need to increase distance
        } else {
            high = mid;  // Can try smaller distance
        }
    }

    return high;
}

int main() {
    
    int n, k;
    cout << "Enter number of gas stations (n) and number of new stations (k): ";
    cin >> n >> k;

    vector<int> stations(n);
    cout << "Enter the positions of " << n << " existing gas stations in sorted order:\n";
    for (int i = 0; i < n; ++i) {
        cin >> stations[i];
    }

    double result = minimizeMaxDistance(stations, k);

    // Output result with fixed precision
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}
