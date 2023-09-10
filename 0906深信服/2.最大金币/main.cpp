#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int i,int j,int &res);

int func(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<pair<int,int>> inaccessible;//存储-1的位置
    for(int i = 0;i < m;++i){
        for(int j = 0;j < n;++j){
            if(grid[i][j] == -1){
                inaccessible.push_back(make_pair(i,j));
            }
        }
    }
    int res = 0;
    int max_res = 0;
    for(auto item:inaccessible){
        res = 0;
        grid[item.first][item.second] = 0;

        vector<vector<int>> tmp_grid(grid);
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        dfs(tmp_grid,visited,0,0,res);
        max_res = max(max_res,res);

        grid[item.first][item.second] = -1;
    }


    return max_res;
}

//void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int& res) {
//    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] == -1) {
//        return;
//    }
//
//    res += grid[i][j];
//    visited[i][j] = true;
//
//    dfs(grid, visited, i, j + 1, res);
//    dfs(grid, visited, i - 1, j, res);
//    dfs(grid, visited, i, j - 1, res);
//    dfs(grid, visited, i + 1, j, res);
//
//    visited[i][j] = false;
//}
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int& res){

    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] == -1){
        return;
    }
    res += grid[i][j];
    visited[i][j] = true;

    dfs(grid,visited,i,j+1,res);
    dfs(grid,visited,i-1,j,res);
    dfs(grid,visited,i,j-1,res);
    dfs(grid,visited,i+1,j,res);

    visited[i][j] = false;

}


int main() {
    vector<vector<int>> grid = {{1, -1}, {-1, 1}};
    cout << func(grid) << endl;
    return 0;
}