#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int response_time;
};

void calculateStatistics(vector<Process>& processes, int quantum) {
    queue<Process*> ready_queue;
    int current_time = 0;
    int total_processes = processes.size();
    int completed_processes = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (completed_processes < total_processes) {
        // Add processes to ready queue which have arrived by current time
        for (auto& process : processes) {
            if (process.arrival_time <= current_time && process.remaining_time > 0) {
                ready_queue.push(&process);
            }
        }

        if (ready_queue.empty()) {
            current_time++;
            continue;
        }

        Process* current_process = ready_queue.front();
        ready_queue.pop();

        if (current_process->response_time == -1) {
            current_process->response_time = current_time - current_process->arrival_time;
        }

        int execution_time = min(quantum, current_process->remaining_time);
        current_process->remaining_time -= execution_time;
        current_time += execution_time;

        if (current_process->remaining_time <= 0) {
            current_process->completion_time = current_time;
            current_process->waiting_time = current_process->completion_time - current_process->arrival_time - current_process->burst_time;
            total_waiting_time += current_process->waiting_time;
            total_turnaround_time += current_process->completion_time - current_process->arrival_time;
            completed_processes++;
        } else {
            ready_queue.push(current_process);
        }
    }

    cout << "Process\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n";
    for (const auto& process : processes) {
        cout << process.id << "\t\t" << process.completion_time << "\t\t" << process.completion_time - process.arrival_time << "\t\t" << process.waiting_time << "\t\t" << process.response_time << "\n";
    }

    cout << "Average Turnaround Time: " << (double)total_turnaround_time / total_processes << endl;
    cout << "Average Waiting Time: " << (double)total_waiting_time / total_processes << endl;
}

int main() {
    int n; // number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> processes[i].arrival_time;
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].waiting_time = 0;
        processes[i].response_time = -1;
    }

    int quantum;
    cout << "Enter the quantum number: ";
    cin >> quantum;

    calculateStatistics(processes, quantum);

    return 0;
}
