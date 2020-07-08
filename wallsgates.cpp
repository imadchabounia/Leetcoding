#include<bits/stdc++.h>

const int oo = 1e9+7; 

using namespace std;

bool visited[101][101];

void solve(vector<vector<int>>& grid){
	//we already know that distance to a gate from itself is 0
	queue<pair<int, int>> q;
	int n = grid.size();
	if(n == 0) return;
	int m = grid[0].size();
	if(m == 0) return;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 0){
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}
	int d = oo;
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	while(!q.empty()){
		int s = q.size();
		while(s){
			pair<int, int> top = q.front();
			q.pop();
			int x = top.first;
			int y = top.second;
			d = (grid[x][y] == 0 ? 0 : d);
			for(int k = 0; k < 4; k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
				if(grid[nx][ny] == -1) continue;
				visited[nx][ny] = 1;
				grid[nx][ny] = d+1;
				q.push(make_pair(nx, ny));
			}
			s--;
		}
		d++;
	}
}

int main(){
	int n, m;
	//input reading
	scanf("%d%d", &n, &m);
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &grid[i][j]);
		}
	}
	memset(visited, false, sizeof(visited));
	solve(grid);
	//printing result
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
