//// you can use includes, for example:
//// #include <algorithm>
//
//// you can write to stdout for debugging purposes, e.g.
//// cout << "this is a debug message" << endl;
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int tmax;
//int arr[100001];
//vector <int> a;
//int solution(vector<int> &A) {
//
//    for (int i = 0; i < (int)A.size(); ++i) {
//        int a = A[i];
//        arr[a]++;
//        tmax = max(a,tmax);
//    }
//    for (int i = 1; i <= tmax; ++i) {
//        if(arr[i] == i) {
//            a.push_back(i);
//        }
//    }
//    if(a.size()>0) {
//        sort(a.begin(), a.end());
//        return a.back();
//    }
//    else{
//        return 0;
//    }
//}
