#include<bits/stdc++.h>

using namespace std;

int solution(int n) {
    for (int i = 1; (i * i) <= n; ++i) {
        if (i * i == n) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n);
}

