// so this sounds like maximum profit job scheduling

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Job {
public:
  int _start;
  int _end;
  long _profit;

  Job(int start, int end, int profit) {
    _start = start;
    _end = end;
    _profit = profit;
  }
};

vector<long long> dp(2 * 1e5, 0);

long long getMaximumProfit(vector<Job> &jobs, int idx) {
  if (idx == jobs.size()) {
    return 0;
  }
  if (dp[idx] > 0)
    return dp[idx];

  auto it = lower_bound(jobs.begin(), jobs.end(), jobs[idx]._end,
                        [](const Job &a, int val) { return a._start <= val; });
  int nextIdx = it - jobs.begin();
  dp[idx] = max(getMaximumProfit(jobs, nextIdx) + jobs[idx]._profit,
                getMaximumProfit(jobs, idx + 1));
  return dp[idx];
}

int main(void) {
  // 1. Sort by starting day.
  // 2. max profit = max(take current, don't take current and use next project);
  // If we take the current, then we need to find the next job using binary
  // search.
  int n;
  cin >> n;
  vector<Job> jobs;
  for (int i = 0; i < n; i++) {
    int a, b, p;
    cin >> a >> b >> p;
    jobs.push_back(Job(a, b, p));
  }
  sort(jobs.begin(), jobs.end(),
       [](const Job &a, const Job &b) { return a._start < b._start; });
  cout << getMaximumProfit(jobs, 0) << endl;
}
