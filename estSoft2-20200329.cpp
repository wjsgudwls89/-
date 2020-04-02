////
//// Created by 전형진 on 2020-03-29.
////
//#include <stdio.h>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//vector<int> set[82];
//vector<int> v;
//
//int getAns(){
//    int ans = -1;
//    for (int i = 81; i > 0 ; i--) {
//        if(set[i].size() <= 1){
//            continue;
//        }
//        else{
//            sort(set[i].begin(),set[i].end());
//            int a = set[i].back();
//            set[i].pop_back();
//            int b = set[i].back();
//            ans = max(ans,a+b);
//
//        }
//    }
//    return ans;
//}
//int getSum(int num){
//
//    int sum = 0;
//
//    while(num != 0){
//        sum+=(num%10);
//        num/=10;
//    }
//
//    return sum;
//}
//
//int main(){
//    int n;
//    scanf("%d",&n);
//
//    for (int i = 0; i < n; ++i) {
//        int a;
//        scanf("%d",&a);
//        v.push_back(a);
//    }
//    for (int i = 0; i < v.size(); ++i) {
//        int temp = getSum(v[i]);
//        set[temp].push_back(v[i]);
//    }
//
//    printf("%d",getAns());
//}