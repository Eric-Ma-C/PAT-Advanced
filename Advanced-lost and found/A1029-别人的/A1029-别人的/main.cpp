
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef struct record{
	int arrive_time;
	int process_time;
}record;


vector<queue<int>> my_ques;
vector<record> arrive_times;
vector<int> finish_times;

bool cmp(const record &a, const record &b) {
	return a.arrive_time < b.arrive_time;
}

int main()
{
	int customer_n, window_n;
	cin >> customer_n >> window_n;
	my_ques.resize(window_n);
	finish_times.resize(customer_n);
	int hour, minute, second, process_t;
	for (int i = 0; i < customer_n; i++) {
		scanf("%d:%d:%d", &hour, &minute, &second);
		cin >> process_t;
		record temp;
		temp.arrive_time = hour * 60 * 60 + minute * 60 + second;
		temp.process_time = process_t;
		arrive_times.push_back(temp);
	}
	sort(arrive_times.begin(), arrive_times.end(), cmp);
	int index = 0;
	int cur_serve = 0;
	int cur_time = 8 * 60 * 60;
	int total_waiting_time = 0;
	int toatl_served_cus = 0;
	while (index < arrive_times.size()){
		if (cur_serve < window_n) {
			for (int i = 0; i < my_ques.size(); i++) {
				if (my_ques[i].empty()) {
					my_ques[i].push(index);
					break;
				}
			}
			if ((cur_time - arrive_times[index].arrive_time) > 0) {
				finish_times[index] = cur_time + arrive_times[index].process_time * 60;
				cout << index << " " << arrive_times[index].arrive_time<<" " << cur_time - arrive_times[index].arrive_time <<endl;
				total_waiting_time += cur_time - arrive_times[index].arrive_time;
			}
			else {
				finish_times[index] = arrive_times[index].arrive_time + arrive_times[index].process_time * 60;
			}
			cur_serve++;
			index++;
			toatl_served_cus++;
		}else {
			cur_time = finish_times[my_ques[0].front()];
			for (int i = 0; i < my_ques.size(); i++) {
				if (finish_times[my_ques[i].front()] < cur_time) {
					cur_time = finish_times[my_ques[i].front()];
				}
			}
			for (int i = 0; i < my_ques.size(); i++) {
				if (finish_times[my_ques[i].front()] == cur_time) {
					my_ques[i].pop();
					cur_serve--;
				}
			}
		}
		if (arrive_times[index].arrive_time > 17 * 60 * 60)
			break;
	}
	cout.setf(ios::fixed);
	cout << setprecision(1) << total_waiting_time * 1.0 / (60 * toatl_served_cus) << endl;

	system("pause");
	return 0;
}