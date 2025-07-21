#include <iostream>
using namespace std;

const int NUM_STUDENTS = 4;
const int NUM_SUBJECTS = 5;

int main() {
    int scores[NUM_STUDENTS][NUM_SUBJECTS];
    int studentTotals[NUM_STUDENTS] = {0};
    int subjectTotals[NUM_SUBJECTS] = {0};
    int highestTotal = 0, highestStudentIndex = 0;

    cout << "Enter scores for each student:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> scores[i][j];
            studentTotals[i] += scores[i][j];
            subjectTotals[j] += scores[i][j];
        }
    }


    cout << "\nAverage scores for each subject:\n";
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        cout << "Subject " << j + 1 << ": " << double(subjectTotals[j]) / NUM_STUDENTS << endl;
    }
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (studentTotals[i] > highestTotal) {
            highestTotal = studentTotals[i];
            highestStudentIndex = i;
        }
    }
    cout << "\nStudent with highest total score: Student " << highestStudentIndex + 1 << " with " << highestTotal << endl;

    return 0;
}
