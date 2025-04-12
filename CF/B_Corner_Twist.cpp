#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

bool canTransform(vector<vector<int>> &gridA, vector<vector<int>> &gridB, int rows, int cols)
{
    for (int row = rows - 1; row >= 1; --row)
    {
        for (int col = cols - 1; col >= 1; --col)
        {
            if (gridA[row][col] != gridB[row][col])
            {
                int diff = (gridB[row][col] - gridA[row][col] + 3) % 3; //ading +3 to handle -ve diff
                gridA[row][col] = gridB[row][col];
                gridA[row - 1][col] = (gridA[row - 1][col] + 2 * diff) % 3;
                gridA[row][col - 1] = (gridA[row][col - 1] + 2 * diff) % 3;
                gridA[row - 1][col - 1] = (gridA[row - 1][col - 1] + diff) % 3;
            }
        }
    }
    for (int row = 0; row < rows; ++row)
    {
        if (gridA[row][0] != gridB[row][0])
            return false;
    }
    for (int col = 0; col < cols; ++col)
    {
        if (gridA[0][col] != gridB[0][col])
            return false;
    }
    return true;
}

void solve()
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> gridA(r, vector<int>(c));
    vector<vector<int>> gridB(r, vector<int>(c));

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            char x;
            cin >> x;
            gridA[i][j] = x - '0';
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            char x;
            cin >> x;
            gridB[i][j] = x - '0';
        }
    }

    if (canTransform(gridA, gridB, r, c))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}