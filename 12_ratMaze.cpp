#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool isSafe(int x, int y, vector<vector<int>> visited, vector<vector<int>> &m, int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y]==1){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited, string path, vector<string> &ans){
        // base case
        if((x == n-1) && (y == n-1)){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // 4 choices T, R, D, L.
        
        //down
        int newx = x + 1;
        int newy = y;
        if(isSafe(newx, newy, visited, m, n)){
            path.push_back('D');
            solve(m, n, newx, newy, visited, path, ans);
            path.pop_back();
        }
        //right
        newx = x;
        newy = y + 1;
        if(isSafe(newx, newy, visited, m, n)){
            path.push_back('R');
            solve(m, n, newx, newy, visited, path, ans);
            path.pop_back();
        }
        //top
        newx = x - 1;
        newy = y;
        if(isSafe(newx, newy, visited, m, n)){
            path.push_back('U');
            solve(m, n, newx, newy, visited, path, ans);
            path.pop_back();
        }
        //left
        newx = x;
        newy = y - 1;
        if(isSafe(newx, newy, visited, m, n)){
            path.push_back('L');
            solve(m, n, newx, newy, visited, path, ans);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m[0][0] == 0){
            return ans;
        }
        
        int srcx=0, srcy=0;
        
        vector<vector<int>> visited(n, vector<int> (n, 0));
        
        string path = "";
        
        solve(m, n, srcx, srcy, visited, path, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

int main() {
    int t;
    cout << "Enter test Cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter n for the matrix: ";
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "M["<<i<<"]["<<j<<"] = ";
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
