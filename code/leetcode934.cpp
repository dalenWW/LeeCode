//
// Created on 2019/4/13.
//

#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<numeric>
#include<iostream>
#include<vector>
#include<set>
#include<math.h>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

typedef pair<int,int> point;

void dfs(queue<point> &q,int row,int col,vector<vector<int> > &A,int m,int n) {
    if(row<0 || col<0 || row>= m || col >=n || A[row][col] != 1) {
        return;
    }
    q.push(point(row,col));
    A[row][col] = 2;
    dfs(q,row-1,col,A,m,n);
    dfs(q,row+1,col,A,m,n);
    dfs(q,row,col-1,A,m,n);
    dfs(q,row,col+1,A,m,n);
}

int shortestBridge(vector<vector<int>>& A) {
    if(A.empty())
        return -1;
    int m = A.size();
    int n = A[0].size();
    queue<point> q;
    int flag = false;
    for(int i=0;i<m && !flag;i++) {
        for(int j=0;j<n && !flag;j++) {
            if(A[i][j] == 1)
            {
                dfs(q,i,j,A,m,n);
                flag = true;
            }
        }
    }
    // bfs
    int steps = 0;
    point d[4] = {point(-1,0),point(1,0),point(0,-1),point(0,1)};
    while(!q.empty()) {
        int size = q.size();
        while(size -- > 0) {
            point p = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int curRow = p.first + d[i].first;
                int curCol = p.second + d[i].second;
                if(curRow>=0 && curRow < m && curCol>=0 && curCol < n && A[curRow][curCol] != 2) {
                    if(A[curRow][curCol] == 1)
                        return steps;
                    A[curRow][curCol] = 2;
                    q.push(point(curRow,curCol));
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    vector<vector<int> > a = {{0,1,0,0,0},{0,1,0,1,1},{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0}};
    int m = shortestBridge(a);
    cout << m;
    return 0;
}