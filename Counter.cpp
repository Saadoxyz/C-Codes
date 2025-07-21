#include <iostream>
#include <cmath>
using namespace std;

int convertMinutesToSeconds(int minutes) {
    return minutes * 60;
}

double convertGigabytesToGigabits(double gigabytes) {
    return gigabytes * 8;
}

double calculateUploadTime(int durationSeconds, double fileSizeGigabits, double internetSpeedMbps) {
    return fileSizeGigabits / internetSpeedMbps + durationSeconds;
}

int main() {
    
    int videoDurationMinutes;
    double fileSizeGB;
    double internetSpeedMbps;
    cout << "Enter video duration (in minutes): ";
    cin >> videoDurationMinutes;

    cout << "Enter file size (in gigabytes): ";
    cin >> fileSizeGB;
    cout << "Enter internet speed (in megabits per second): ";
    cin >> internetSpeedMbps;

    int durationSeconds = convertMinutesToSeconds(videoDurationMinutes);

    double fileSizeGigabits = convertGigabytesToGigabits(fileSizeGB);
    
    double uploadTimeSeconds = calculateUploadTime(durationSeconds, fileSizeGigabits, internetSpeedMbps);

    cout << "\nEstimated upload time: " << uploadTimeSeconds << " seconds\n";

    return 0;
}