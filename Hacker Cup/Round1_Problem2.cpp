#include <bits/stdc++.h>
using namespace std;
// Function to check if array is sorted - O(n)
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;  

}

vector<int> findPrimes(int n) {
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Function to count elements that are difference of any two elements - O(n)
int countDifferenceElements(vector<int>& arr) {
    int n = arr.size();
    unordered_set<int> differences;
    unordered_set<int> numbers(arr.begin(), arr.end());
    
    // Calculate all possible differences
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                differences.insert(abs(arr[i] - arr[j]));
            }
        }
    }
    
    // Count how many elements in array are also differences
    int count = 0;
    for(int num : arr) {
        if(differences.find(num) != differences.end()) {
            count++;
        }
    }
    
    return count;
}

int main() {

    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<int> primeNumbers = findPrimes(n);
        cout << "Case #" << i << ": " << countDifferenceElements(primeNumbers) << endl;

        
    
    // Check if array is sorted
    
    // Count elements that are differences
    // cout << "Count of elements that are differences: "    
    }
    
    return 0;
}