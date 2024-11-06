#include <iostream>
#include <vector>
using namespace std;

int leftMostOneRow(vector<vector<int>> &q)
{
    int leftMostOne = -1;
    int maxNoRows = -1;

    for (int j = q[0].size()-1; j >= 0; j--)
    {
        if (q[0][j] == 1) {
            leftMostOne = j;
            maxNoRows = 0;
        }
        else {
            break;
        }
    }

    for (int i = 1; i < q.size(); i++) {
        for (int j = q[i].size(); j >= 0; j--) {
            if (q[i][j] == 1) {
                leftMostOne = j;
                maxNoRows = i;
            }
            else {
                break;
            }
        }
    }

    return maxNoRows;
}

int maximumOnesRows(vector<vector<int>> &v)
{
    int maxOnes = INT16_MIN;
    int maxNoRows = -1;
    int column = v[0].size();
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 1)
            {
                int noOfOnes = column - j;
                if (maxOnes < noOfOnes)
                {
                    maxOnes = noOfOnes;
                    maxNoRows = i;
                }
                break;
            }
        }
    }
    return maxNoRows;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout <<leftMostOneRow(mat)<< endl;

    return 0;
}