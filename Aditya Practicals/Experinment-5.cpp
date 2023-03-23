#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start_time;
    int end_time;
};

bool cmp(Activity a, Activity b) {
    return a.end_time < b.end_time;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter start time and end time of activity " << i+1 << ": ";
        cin >> activities[i].start_time >> activities[i].end_time;
    }

    sort(activities.begin(), activities.end(), cmp);

    int last_end_time = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i].start_time >= last_end_time) {
            count++;
            last_end_time = activities[i].end_time;
        }
    }

    cout << "Maximum number of activities that can be performed: " << count << endl;

    return 0;
}
