#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Process structure
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

// Function to compare processes based on arrival time
bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

// Function to compare processes based on burst time
bool compareBurstTime(const Process& p1, const Process& p2) {
    return p1.burstTime < p2.burstTime;
}

// Function to implement FCFS scheduling
void FCFS(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (const auto& process : processes) {
        currentTime = max(currentTime, process.arrivalTime);
        cout << "Process " << process.id << " starts at time " << currentTime << endl;
        totalWaitingTime += currentTime - process.arrivalTime;
        currentTime += process.burstTime;
        totalTurnaroundTime += currentTime - process.arrivalTime;
        cout << "Process " << process.id << " finishes at time " << currentTime << endl;
    }

    double avgWaitingTime = static_cast<double>(totalWaitingTime) / processes.size();
    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / processes.size();

    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}

// Function to implement SJF scheduling
void SJF(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    while (!processes.empty()) {
        auto shortestJob = min_element(processes.begin(), processes.end(), compareBurstTime);
        currentTime = max(currentTime, shortestJob->arrivalTime);
        cout << "Process " << shortestJob->id << " starts at time " << currentTime << endl;
        totalWaitingTime += currentTime - shortestJob->arrivalTime;
        currentTime += shortestJob->burstTime;
        totalTurnaroundTime += currentTime - shortestJob->arrivalTime;
        cout << "Process " << shortestJob->id << " finishes at time " << currentTime << endl;
        processes.erase(shortestJob);
    }

    double avgWaitingTime = static_cast<double>(totalWaitingTime) / processes.size();
    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / processes.size();

    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}


int main() {
    // Example usage
    vector<Process> processes = {{1, 3, 4}, {2, 5, 3}, {3, 0, 2}, {4, 5, 1}, {5,4,3}};

    cout << "FCFS Scheduling:\n";
    FCFS(processes);

    cout << "\nSJF Scheduling:\n";
    SJF(processes);

    return 0;
}
