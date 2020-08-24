#include <iostream>
#include <algorithm>
using namespace std;

class Job {
public:
	int job_num;
	int p, d;
	Job() {};
	Job(int, int, int);
	bool operator<(Job);
};

Job::Job(int job_num, int p, int d) {
	this->job_num = job_num;
	this->p = p;
	this->d = d;
}

bool Job::operator<(Job j) {
	return j.p < this->p;
}

int main() {
	int p[] = {35, 30, 25, 20, 15, 12, 5};
	int d[] = {3, 4, 4, 2, 3, 1, 2};
	int n = sizeof(p) / sizeof(p[0]);
	Job jobs[n];
	int max_d = 0;
	for (int i = 0; i < n; ++i) {
		if (max_d < d[i])
			max_d = d[i];
		Job temp(i, p[i], d[i]);
		jobs[i] = temp;
	}
	sort(jobs, jobs + n);
	int profit = 0;
	int slot[max_d] = {0};
	for (int i = 0; i < n; ++i) {
		int x = jobs[i].d;
		while (slot[x - 1] > 0) {
			--x;
			if (x == 0)
				break;
		}
		if (x != 0) {
			slot[x - 1] = jobs[i].job_num + 1;
			profit += jobs[i].p;
		}
	}
	cout << "Job Sequence:\n";
	for (int i = 0; i < max_d; ++i) {
		slot[i] ? cout << slot[i] << "\t" : cout << "" ;
	}
	cout << endl;
	cout << "Profit:\n" << profit << endl;
	return 0;
}