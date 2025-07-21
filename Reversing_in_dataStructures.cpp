#include <iostream>
using namespace std;
int main() {
    int N, M;
    cout << "Enter the value of N : ";
    cin >> N;
     cout << "Enter the value of M: ";
    cin >> M;
    int sumN = 0;
    for (int i = 1; i <= N; i++) {
        sumN += i;
    }
    cout << "Sum of first " << N << " positive integers: " << sumN << endl;
    int sumM = 0;
    for (int i = 1; i <= M; i++) {
        sumM += 2 * i;
    }
    cout << "Sum of first " << M << " even integers: " << sumM << endl;

    return 0;
}
