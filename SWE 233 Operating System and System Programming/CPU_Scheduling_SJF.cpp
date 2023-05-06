#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

#define max_size 100

struct Process
{
	int id;
	int arrival_time;
	int burst_time;
	int start_time;
	int completion_time;
	int turnaround_time;
	int waiting_time;
	int response_time;
};

Process p[max_size];
bool visited[max_size];
int total_process;
int cpu_idle_time;
int total_turnaround_time;
int total_waiting_time;

void loadProcesses()
{
	std::cin >> total_process;
	for( int i = 0; i < total_process; i++ ) {
		std::cin >> p[i].arrival_time >> p[i].burst_time;
		p[i].id = i+1;
		visited[i] = false;
	}
}

bool comparatorAT(Process a,Process b){ return a.arrival_time < b.arrival_time; }

bool comparatorID(Process a,Process b){ return a.id < b.id; }

void shortestJobFirst()
{
	if( total_process < 1 ) return;
	for( int i = 0; i < total_process; ++i ) { visited[i] = false; }
	cpu_idle_time = total_turnaround_time = total_waiting_time = 0;
	bool is_first_process = true;
	int current_time = 0;
	int completed = 0;
	int prev = 0;

	while( completed != total_process ) {
		int min_index = -1;
		int minimum = INT_MAX;
		for( int i = 0; i < total_process; ++i ) {
			if( !visited[i] && p[i].arrival_time <= current_time ) {
				if( p[i].burst_time < minimum ) {
					minimum = p[i].burst_time;
					min_index = i;
				}
				else if( p[i].burst_time == minimum ) {
					if( p[i].arrival_time < p[min_index].arrival_time ) {
						minimum = p[i].burst_time;
						min_index = i;
					}
				}
			}
		}
		if( min_index == -1 ) {
			current_time++;
			continue;
		}
		p[min_index].start_time = current_time;
		p[min_index].completion_time = current_time + p[min_index].burst_time;
		p[min_index].turnaround_time = p[min_index].completion_time - p[min_index].arrival_time;
		p[min_index].waiting_time = p[min_index].turnaround_time - p[min_index].burst_time;
		p[min_index].response_time = p[min_index].waiting_time;

		total_turnaround_time += p[min_index].turnaround_time;
		total_waiting_time += p[min_index].waiting_time;
		cpu_idle_time += (is_first_process == true) ? 0 : (p[min_index].start_time - prev);

		completed++;
		visited[min_index] = true;
		current_time = p[min_index].completion_time;
		prev = current_time;
		is_first_process = false;
	}

	int max_completion_time = INT_MIN;
	int min_arrival_time = INT_MAX;
	for( int i = 0; i < total_process; ++i ) {
		max_completion_time = max( max_completion_time, p[i].completion_time );
		min_arrival_time = min( min_arrival_time, p[i].arrival_time);
	}

	int length_cycle = max_completion_time - min_arrival_time;

	std::cout << "average turnaround time: " << (double)total_turnaround_time / (double)total_process << endl;
	std::cout << "average waiting time: " << (double)total_waiting_time / (double)total_process << endl;
}

int main()
{
	loadProcesses();
	sort(p, p+total_process, comparatorAT);
	shortestJobFirst();
	sort(p, p+total_process, comparatorID);
}
