#include<iostream>
#include<algorithm>
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
	}
}

bool comparatorAT(Process a,Process b){ return a.arrival_time < b.arrival_time; }

bool comparatorID(Process a,Process b){ return a.id < b.id; }

bool firstComeFirstServe()
{
	cpu_idle_time = 0;
	total_turnaround_time = 0;
	total_waiting_time = 0;
	for( int i = 0; i < total_process; ++i ) {
		p[i].start_time = (i==0) ? p[i].arrival_time : max(p[i-1].completion_time, p[i].arrival_time);
		p[i].completion_time = p[i].start_time + p[i].burst_time;
		p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
		p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
		p[i].response_time = p[i].waiting_time;

		total_turnaround_time += p[i].turnaround_time;
		total_waiting_time += p[i].waiting_time;
		cpu_idle_time += (i==0) ? 0 : p[i].start_time - p[i-1].completion_time;
	}
}

void printDetails()
{
	double total_waiting_time_d = (double) total_waiting_time;
	double total_turnaround_time_d = (double) total_turnaround_time;
	double n = total_process;

	std::cout << "average waiting time: " << total_waiting_time_d / n << endl;
	std::cout << "average turnaround time: " << total_turnaround_time_d / n << endl;
}

int main()
{
	loadProcesses();
	sort(p, p+total_process, comparatorAT);
	firstComeFirstServe();
	sort(p, p+total_process, comparatorID);
	printDetails();
}
