#include<bits/stdc++.h>
using namespace std;

struct Task {
    int deadline, profit, index;
};

bool compareTasks(Task t1, Task t2) {
    return t1.profit > t2.profit;
}

int taskScheduling(Task tasks[], int n) {
    sort(tasks, tasks+n, compareTasks);

    int maxDeadline = tasks[0].deadline;
    for(int i=1; i<n; i++)
        maxDeadline = max(maxDeadline, tasks[i].deadline);

    int profit = 0;
    bool slots[maxDeadline+1] = {false};
    vector<int> sequence;
    for(int i=0; i<n; i++) {
        for(int j=min(maxDeadline, tasks[i].deadline); j>=1; j--) {
            if(!slots[j]) {
                slots[j] = true;
                profit += tasks[i].profit;
                sequence.push_back(tasks[i].index);
                break;
            }
        }
    }
    cout << "Sequence of tasks performed: ";
    for(int i=0; i<sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;
    return profit;
}

int main() {
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;
    Task tasks[n];
    for(int i=0; i<n; i++) {
        cout << "Enter the deadline and profit of task " << i+1 << ": ";
        cin >> tasks[i].deadline >> tasks[i].profit;
        tasks[i].index = i+1;
    }
    cout << "Maximum profit: " << taskScheduling(tasks, n) << endl;
    return 0;
}