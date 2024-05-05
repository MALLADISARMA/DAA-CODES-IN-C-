#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_JOBS = 100;

char jobId[MAX_JOBS];
int jobDeadline[MAX_JOBS];
int jobProfit[MAX_JOBS];

bool compare(int a, int b) {
    return (jobProfit[a] > jobProfit[b]);
}

void jobSequencing(int n) {
    // Sort job indexes based on their profits in descending order
    int jobIndexes[MAX_JOBS];
    for (int i = 0; i < n; ++i) {
        jobIndexes[i] = i;
    }
    sort(jobIndexes, jobIndexes + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; ++i) {
        maxDeadline = max(maxDeadline, jobDeadline[i]);
    }

    // Array to store the sequence of jobs scheduled
    char result[MAX_JOBS];
    bool slots[MAX_JOBS];

    // Initialize slots to be empty
    for (int i = 0; i < maxDeadline; ++i) {
        slots[i] = false;
    }

    // Variables to store total profit and number of jobs scheduled
    int totalProfit = 0;
    int scheduledJobs = 0;

    // Iterate through each job
    for (int i = 0; i < n; ++i) {
        // Find a suitable slot for the current job
        for (int j = min(maxDeadline - 1, jobDeadline[jobIndexes[i]] - 1); j >= 0; --j) {
            if (!slots[j]) {
                result[j] = jobId[jobIndexes[i]];
                slots[j] = true;
                totalProfit += jobProfit[jobIndexes[i]];
                scheduledJobs++;
                break;
            }
        }
    }

    // Print the sequence of jobs scheduled
    cout << "Sequence of jobs: ";
    for (int i = 0; i < maxDeadline; ++i) {
        if (slots[i]) {
            cout << result[i] << " ";
        }
    }
    cout << endl;

    // Print the total profit obtained
    cout << "Total profit: " << totalProfit << endl;
    cout << "Number of jobs scheduled: " << scheduledJobs << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    cout << "Enter job details (id, deadline, profit) for each job:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobId[i] >> jobDeadline[i] >> jobProfit[i];
    }

    jobSequencing(n);

    return 0;
}
