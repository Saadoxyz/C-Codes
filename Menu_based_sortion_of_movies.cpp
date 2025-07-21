#include <iostream>
using namespace std;

void GetHighestInRow(int lab[3][3]) {
    int i;
    int highest;
    for (i = 0; i < 3; i++) {
        highest = lab[i][0];
        for (int j = 0; j < 3; j++) {
            if (lab[i][j] > highest)
                highest = lab[i][j];
        }
        cout << "The highest element in row " << i << ": " << highest << endl;
    }
}

void GetLowestInRow(int lab[3][3]) {
    int i;
    int lowest;
    for (i = 0; i < 3; i++) {
        lowest = lab[i][0];
        for (int j = 0; j < 3; j++) {
            if (lab[i][j] < lowest)
                lowest = lab[i][j];
        }
        cout << "The lowest element in row " << i << ": " << lowest << endl;
    }
}

void GetHighestInColumn(int lab[3][3]) {
    int j;
    int highest;
    for (int i = 0; i < 3; i++) {
        highest = lab[0][i];
        for (j = 0; j < 3; j++) {
            if (lab[j][i] > highest)
                highest = lab[j][i];
        }
        cout << "The highest element in column " << i << ": " << highest << endl;
    }
}

void GetLowestInColumn(int lab[3][3]) {
    int i;
    int lowest;
    for (int j = 0; j < 3; j++) {
        lowest = lab[0][j];
        for (i = 0; i < 3; i++) {
            if (lab[i][j] < lowest)
                lowest = lab[i][j];
        }
        cout << "The lowest element in column " << j << ": " << lowest << endl;
    }
}

int LeftDiagonalTotal(int lab[3][3]) {
    int total = 0;
    for (int i = 0; i < 3; i++) {
        total += lab[i][i];
    }
    cout << "Left Diagonal Total: " << total << endl;
    return total;
}

int RightDiagonalTotal(int lab[3][3]) {
    int total = 0;
    for (int i = 0; i < 3; i++) {
        total += lab[i][2 - i];
    }
    cout << "Right Diagonal Total: " << total << endl;
    return total;
}

int RowSum(int lab[3][3], int row) {
    int sum = 0;
    for (int j = 0; j < 3; j++) {
        sum += lab[row][j];
    }
    cout << "Sum of elements in row " << row << ": " << sum << endl;
    return sum;
}

int ColumnSum(int lab[3][3], int col) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += lab[i][col];
    }
    cout << "Sum of elements in column " << col << ": " << sum << endl;
    return sum;
}

int main() {
    int lab[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << lab[i][j] << "\t";
        }
        cout << endl;
    }

    int choice;
    cout << "Enter your choice "<<endl;
	cout<<" 1:Highest element in row"<<endl;
	cout<<" 2: Lowest element in row"<<endl;
	cout<<" 3: Highest element in column"<<endl;
	cout<<" 4: Lowest element in column"<<endl;
	cout<<" 5: sum of Left diagonal "<<endl;
	cout<<" 6: sum of Right diagonal"<<endl;
	cout<<" 7: sum of row"<<endl;
	cout<<" 8: sum of column "<<endl;
	cout<<" 9:exit"<<endl;
    cin >> choice;

    switch (choice) {
        case 1:
            GetHighestInRow(lab);
            break;
        case 2:
            GetLowestInRow(lab);
            break;
        case 3:
            GetHighestInColumn(lab);
            break;
        case 4:
            GetLowestInColumn(lab);
            break;
        case 5:
            LeftDiagonalTotal(lab);
            break;
        case 6:
            RightDiagonalTotal(lab);
            break;
        case 7:
            int row;
            cout << "Enter the row for sum calculation: ";
            cin >> row;
            RowSum(lab, row);
            break;
        case 8:
            int col;
            cout << "Enter the column for sum calculation: ";
            cin >> col;
            ColumnSum(lab, col);
            break;
        case 9:
        break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}