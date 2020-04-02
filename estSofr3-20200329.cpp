////
//// Created by 전형진 on 2020-03-29.
////
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//int visit[201];
//int arr[201];
//int n;
//
//bool getCheck(int a,int b,int iter){
//    if(iter == 1){
//        if(a < b){
//            return true;
//        }
//        else if (a == b){
//            return false;
//        }
//        else {
//            return false;
//        }
//    }
//    if(iter == -1){
//        if( a > b)
//            return true;
//        else if(a == b){
//            return false;
//        }
//        else {
//            return false;
//        }
//    }
//    return false;
//}
//bool fcheck(){
//    int iter = 1;
//    for (int j = 0; j < n-1; ++j) {
//        if(getCheck(arr[j],arr[j+1],iter)){
//            iter *= -1;
//        }
//        else{
//            break;
//        }
//        if(j == n-2) {
//           return true;
//        }
//    }
//    iter = -1;
//    for (int j = 0; j < n-1; ++j) {
//
//        if(getCheck(arr[j],arr[j+1],iter)){
//            iter *= -1;
//        }
//        else{
//           break;
//        }
//        if(j == n-2) {
//            return true;
//        }
//    }
//    return false;
//}
//int main(){
//
//    scanf("%d",&n);
//    int ans = 0;
//    for (int i = 0; i < n; ++i) {
//        scanf("%d",&arr[i]);
//    }
//    if(fcheck()){
//        printf("true: %d",0);
//    }
//    else {
//        for (int i = 0; i < n; ++i) {
//            visit[i] = 1;
//            int iter = 1;
//            for (int j = 0; j < n - 1; ++j) {
//                if (visit[j] == 1) {
//                    continue;
//                }
//                int temp = 1;
//                if(visit[j+1] == 1){
//                    temp++;
//                }
//                if (getCheck(arr[j], arr[j + temp], iter)) {
//                    iter *= -1;
//                } else {
//                    break;
//                }
//                if (j == n - 2) {
//                    ans++;
//                }
//            }
//            iter = -1;
//            for (int j = 0; j < n - 1; ++j) {
//                if (visit[j] == 1) {
//                    continue;
//                }
//                int temp = 1;
//                if(visit[j+1] == 1){
//                    temp++;
//                }
//                if (getCheck(arr[j], arr[j + temp], iter)) {
//                    iter *= -1;
//                } else {
//                    break;
//                }
//                if (j == n - 2) {
//                    ans++;
//                }
//            }
//            visit[i] = 0;
//        }
//        printf("%d", ans);
//    }
//}
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int visit[201];
int arr[201];
int n;

bool getCheck(int a,int b,int iter){
    if(iter == 1){
        if(a < b){
            return true;
        }
        else if (a == b){
            return false;
        }
        else {
            return false;
        }
    }
    if(iter == -1){
        if( a > b)
            return true;
        else if(a == b){
            return false;
        }
        else {
            return false;
        }
    }
    return false;
}
bool fcheck(){
    int iter = 1;
    for (int j = 0; j < n-1; ++j) {
        if(getCheck(arr[j],arr[j+1],iter)){
            iter *= -1;
        }
        else{
            break;
        }
        if(j == n-2) {
            return true;
        }
    }
    iter = -1;
    for (int j = 0; j < n-1; ++j) {

        if(getCheck(arr[j],arr[j+1],iter)){
            iter *= -1;
        }
        else{
            break;
        }
        if(j == n-2) {
            return true;
        }
    }
    return false;
}
int solution(vector<int> &A) {
    int ans = 0;
    for (int i = 0; i < (int)A.size(); ++i) {
        arr[i] = A[i];
        n = A.size();
    }
    if(fcheck()){
        return 0;
    }
    else {
        for (int i = 0; i < n; ++i) {
            visit[i] = 1;
            int iter = 1;
            for (int j = 0; j < n - 1; ++j) {
                if (visit[j] == 1) {
                    continue;
                }
                int temp = 1;
                if(visit[j+1] == 1){
                    temp++;
                }
                if (getCheck(arr[j], arr[j + temp], iter)) {
                    iter *= -1;
                } else {
                    break;
                }
                if (j == n - 2 || j + temp == n-1) {
                    ans++;
                    printf("%d \n",i);
                }
            }
            iter = -1;
            for (int j = 0; j < n - 1; ++j) {
                if (visit[j] == 1) {
                    continue;
                }
                int temp = 1;
                if(visit[j+1] == 1){
                    temp++;
                }
                if (getCheck(arr[j], arr[j + temp], iter)) {
                    iter *= -1;
                } else {
                    break;
                }
                if (j == n - 2 || j + temp == n -1) {
                    ans++;
                    printf("%d\n",i);
                }
            }
            visit[i] = 0;
        }
        if(ans != 0){
            return ans;
        }
        else{
            return -1;
        }
    }
}
int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(4);
    A.push_back(2);


    printf("%d",solution(A));
}