/*
Nick Spizzirri
CSC122
10/19/2024
CRT
*/
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool areCoprime(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (gcd(nums[i], nums[j]) != 1) {
                return false;
            }
        }
    }
    return true;
}

int findMsquiggle(int M, int m) {
    for (int x = 1; x < m; x++) {
        if ((M * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

int chineseRemainderTheorem(vector<int> m, vector<int> a) {
    int n = m.size();
    int mProduct = 1;
    int result = 0;
    for (int i = 0; i < n; i++) {
        mProduct *= m[i];
    }
    for (int i = 0; i < n; i++) {
        int M = mProduct / m[i];
        int Msquiggle = findMsquiggle(M, m[i]);
        result += a[i] * M * Msquiggle;
    }
    return (result % mProduct);
}

int main() {
    int n;
    cout << "Enter the number of congruences in the system: ";
    cin >> n;
    vector<int> m(n), a(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter value for a" << i + 1 << ": ";
        cin >> a[i];
        cout << "Enter value for m" << i + 1 << ": ";
        cin >> m[i];
    }
    if (!areCoprime(m)) {
        cout << "m values must be coprime!" << endl;
        return -1;
    }
    int result = chineseRemainderTheorem(m, a);
    cout << "The solution is: " << result << endl;
    return 0;
}