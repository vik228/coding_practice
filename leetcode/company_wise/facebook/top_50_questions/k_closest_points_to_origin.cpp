#include <bits/stdc++.h>
using namespace std;

int dist(vector<int>& v1) {
    return ((v1[0]*v1[0]) + (v1[1]*v1[1]));
}
int findPivot(vector<vector<int>>& points, int lo, int hi) {
    int pivot = dist(points[hi]);
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (dist(points[j]) <= pivot) {
            swap(points[i++], points[j]);
        }
    }
    swap(points[i], points[hi]);
    return i;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    int lo = 0;
    int hi = points.size() - 1;
    int numPoints = K;
    while(lo <= hi) {
        int randInt = lo + rand()%(hi - lo + 1);
        swap(points[randInt], points[hi]);
        int pivot = findPivot(points, lo, hi);
        int numEles = pivot - lo + 1;
        if (numEles == K) {
            break;
        } 
        if (K < numEles) {
            hi = pivot - 1;
        } else {
            lo = pivot + 1;
            K -= numEles;
        }
    }
    vector<vector<int>> ans;
    for (int i = 0; i < numPoints; i++) {
        ans.push_back(points[i]);
    }
    return ans;
}