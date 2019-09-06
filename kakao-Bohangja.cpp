//
// Created by 전형진 on 2019-09-06.
//
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int MOD = 20170805;

int r[501][501];
int d[501][501];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(r,0, sizeof(r));
    memset(d,0, sizeof(d));

    r[1][1] = d[1][1] = 1;

    for (int i = 1; i <=m  ; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (city_map[i - 1][j - 1] == 0) {
                r[i][j] = (r[i][j] + r[i][j - 1] + d[i - 1][j]) % MOD;
                d[i][j] = (d[i][j] + r[i][j - 1] + d[i - 1][j]) % MOD;
            } else if (city_map[i - 1][j - 1] == 1) {
                r[i][j] = 0;
                d[i][j] = 0;
            } else {
                r[i][j] = r[i][j - 1];
                d[i][j] = d[i - 1][j];
            }
        }
    }
    return (r[m][n-1]+d[m-1][n])%MOD;
}