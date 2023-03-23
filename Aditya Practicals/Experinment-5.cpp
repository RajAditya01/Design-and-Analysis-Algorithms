#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Struct to represent an activity
struct Activity {
    int start, finish;
};

// Function to compare activities based on finish time
bool compareActivities(Activity a1, Activity a2) {
    return (a1.finish < a2.finish);
}

// Function to find maximum number of activities that can be performed
int activitySelection(vector<Activity>& activities) {
    // Sort activities based on finish time
    sort(activities.begin(), activities.end(), compareActivities);
    
    // Select the first activity
    int last_finish_time = activities[0].finish;
    int count = 1;
    cout << "Selected activity: 0\n";
    
    // Select other activities if they don't overlap with the last selected activity
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= last_finish_time) {
            count++;
            cout << "Selected activity: " << i << "\n";
            last_finish_time = activities[i].finish;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    // Input the start and finish time of each activity
    for (int i = 0; i < n; i++) {
        cout << "Enter start time and finish time of activity " << i << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    int max_activities = activitySelection(activities);
    cout << "Maximum number of activities that can be performed: " << max_activities << endl;

    return 0;
}

