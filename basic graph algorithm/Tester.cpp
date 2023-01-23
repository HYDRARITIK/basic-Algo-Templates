#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
// Initial Template for C++
//https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
   int numberOfEnclaves(vector<vector<int>> &grid)
   {
      // Code here
      // Code here
      int r = grid.size();
      int c = grid[0].size();
      vector<vector<bool>> visited(r, vector<bool>(c, false));
      queue<pair<int, int>> q;

      for (int i = 0; i < r; i++)
      {
         for (int j = 0; j < c; j++)
         {
            // add boundary ones
            if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
            {
               if (grid[i][j])
               {

                  visited[i][j] = true;
                  q.push({i, j});
               }
            }
         }
      }

      while (!q.empty())
      {
         // pop mark visited add in queue
         auto top = q.front();
         int i = top.first;
         int j = top.second;
         //   visited[i][j] = true;
         q.pop();

         int row_dir[4] = {-1, 0, 1, 0};
         int col_dir[4] = {0, 1, 0, -1};

         for (int z = 0; z < 4; z++)
         {
            int curr_row = i + row_dir[z];
            int curr_col = j + col_dir[z];

            if (curr_row < 0 || curr_col < 0 || curr_row >= r || curr_col >= c || grid[curr_row][curr_col] == 0 || visited[curr_row][curr_col])
               continue;

            q.push({curr_row, curr_col});
            visited[curr_row][curr_col] = true;
         }
      }
      //
      int count = 0;

      for (int i = 0; i < r; i++)
      {
         for (int j = 0; j < c; j++)
         {
            // add boundary ones
            if (!visited[i][j] && grid[i][j])
            {
               count++;
            }
         }
      }

      return count;
   }
};

//{ Driver Code Starts.

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> grid(n, vector<int>(m));
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            cin >> grid[i][j];
         }
      }
      Solution obj;
      cout << obj.numberOfEnclaves(grid) << endl;
   }
}
// } Driver Code Ends

int main()
{

   return 0;
}