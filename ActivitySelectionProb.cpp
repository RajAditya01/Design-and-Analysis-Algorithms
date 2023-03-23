#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, end;
};

bool compareActivities(Activity a1, Activity a2) {
    return a1.end < a2.end;
}

int activitySelection(vector<Activity>& activities) {
    // Sort the activities by their end times
    sort(activities.begin(), activities.end(), compareActivities);

    int n = activities.size();
    int count = 1;
    int lastEnd = activities[0].end;

    // Loop through the sorted activities and count the number of compatible activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }

    return count;
}

int main() {
    vector<Activity> activities = {
        {1, 3},
        {2, 5},
        {3, 8},
        {4, 10},
        {5, 12},
        {6, 14},
        {8, 15},
        {9, 16}
    };

    int maxActivities = activitySelection(activities);

    cout << "Maximum number of activities that can be performed: " << maxActivities << endl;

    return 0;
}
