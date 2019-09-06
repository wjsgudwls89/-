//
// Created by 전형진 on 2019-09-06.
//
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int m,n;
int ans = 0;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int picture[101][101];
int visit[101][101];


void bfs(int y,int x){

    int k = picture[y][x];
    int cnt = 1;
    queue<int> xq;
    queue<int> yq;

    visit[y][x] = 1;

    xq.push(x);
    yq.push(y);

    while (!xq.empty()){
        int x = xq.front();
        int y = yq.front();
        xq.pop();yq.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && picture[ny][nx] == k
            &&visit[ny][nx] == 0){
                xq.push(nx);
                yq.push(ny);
                visit[ny][nx] = 1;
                cnt++;
            }
        }
    }
    ans = max(ans,cnt);
    //printf("%d\n",cnt);
}

int main(){
    scanf("%d %d",&m,&n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&picture[i][j]);
        }
    }
    int k = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(picture[i][j] != 0 && visit[i][j] == 0){
                bfs(i,j);
                k++;
            }
        }
    }
    memset(visit,0, sizeof(visit));
    printf("%d %d",k,ans);
}