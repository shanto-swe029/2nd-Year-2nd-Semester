#include<iostream>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

#define max_size 100

struct Process
{
	int id;
	int arrival_time;
	int burst_time;
	int remaining_burst_time;
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
int total_response_time;
int tq; // time quanta

void loadProcesses()
{
	std::cin >> total_process >> tq;
	for( int i = 0; i < total_process; i++ ) {
		std::cin >> p[i].arrival_time >> p[i].burst_time;
		p[i].id = i+1;
		p[i].remaining_burst_time = p[i].burst_time;
		visited[i] = false;
	}
}

bool comparatorAT(Process a,Process b){ return a.arrival_time < b.arrival_time; }

bool comparatorID(Process a,Process b){ return a.id < b.id; }

void roundRobin()
{
	if( total_process < 1 ) return;
	for( int i = 0; i < total_process; ++i ) { visited[i] = false; }
	cpu_idle_time = total_turnaround_time = total_waiting_time = total_response_time = 0;
	bool is_first_process = true;
	int current_time = 0;
	int completed = 0;

	std::queue<int> q;
	q.push(0);
	visited[0] = true;

	while( completed != total_process ) {
		int index = q.front(); q.pop();

		if(p[index].remaining_burst_time == p[index].burst_time) {
			p[index].start_time = max( current_time, p[index].arrival_time );
			cpu_idle_time += (is_first_process == true) ? 0 : (p[index].start_time - current_time);
			current_time = p[index].start_time;
			is_first_process = false;
		}

		if( p[index].remaining_burst_time - tq > 0 ) {
			p[index].remaining_burst_time -= tq;
			current_time += tq;
		}
		else {
			current_time += p[index].remaining_burst_time;
			p[index].remaining_burst_time = 0;
			completed++;

			p[index].completion_time = current_time;
			p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
			p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;
			p[index].response_time = p[index].start_time - p[index].arrival_time;

			total_turnaround_time += p[index].turnaround_time;
			total_waiting_time += p[index].waiting_time;
			total_response_time += p[index].response_time;
		}

		for( int i = 0; i < total_process; ++i ) {
			if( !visited[i] && p[i].arrival_time <= current_time && p[i].remaining_burst_time > 0 ) {
				q.push(i);
				visited[i] = true;
			}
		}

		if( p[index].remaining_burst_time > 0 ) {
			q.push(index);
		}

		if( q.empty() ) {
			for( int i = 0; i < total_process; ++i ) {
				if( p[i].remaining_burst_time > 0 ) {
					q.push(i);
					visited[i] = true;
					break;
				}
			}
		}
	}

	int max_completion_time = INT_MIN;
	for( int i = 0; i < total_process; ++i ) {
		max_completion_time = max( max_completion_time, p[i].completion_time );
	}

	int length_cycle = max_completion_time - p[0].arrival_time;

	std::cout << "average turnaround time: " << (double)total_turnaround_time / (double)total_process << endl;
	std::cout << "average waiting time: " << (double)total_waiting_time / (double)total_process << endl;
	std::cout << "average response time: " << (double)total_response_time / (double)total_process << endl;
}

int main()
{
	loadProcesses();
	sort(p, p+total_process, comparatorAT);
	roundRobin();
	sort(p, p+total_process, comparatorID);
}
/*
input:
4 2
0 5
1 4
2 2
4 1

output:
average turnaround time: 7.75
average waiting time: 4.75
average response time: 1.75
*/
