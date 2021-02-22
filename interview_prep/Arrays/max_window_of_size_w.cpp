#include <bits/stdc++.h>
using namespace std;

vector<int> find_max_sliding_window(vector<int>& v, int window_size) {
    vector<int> result;
    deque<int> window;
    int i = 0;
    for (int j = 0; j < v.size(); j++) {
        while(!window.empty() and v[j] >= v[window.back()]) {
            window.pop_back();
        }
        window.push_back(j);
        if (j - i + 1 == window_size) {
            result.push_back(v[window.front()]);
            if (v[i] == v[window.front()]) {
                window.pop_front();
            }
            i++;
        }
    }
    return result;
}