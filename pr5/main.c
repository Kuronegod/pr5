#include <stdio.h>

#define MOD 12345

int main() {
    int n;
    printf("Enter the length of sequences (n): ");
    scanf("%d", &n);

    if (n < 2 || n >= 10000) {
        printf("Invalid input. n must be between 2 and 9999.\n");
        return 1;
    }

    // Масиви для зберігання кількості послідовностей
    long long dp0[n+1], dp1[n+1], dp11[n+1];

    // Початкові умови
    dp0[1] = 1;
    dp1[1] = 1;
    dp11[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp0[i] = (dp0[i-1] + dp1[i-1] + dp11[i-1]) % MOD;
        dp1[i] = dp0[i-1] % MOD;
        dp11[i] = dp1[i-1] % MOD;
    }

    long long result = (dp0[n] + dp1[n] + dp11[n]) % MOD;

    printf("Number of valid sequences of length %d: %lld\n", n, result);

    return 0;
}
