#include<bits/stdc++.h>
using namespace std;

void combinations(const vector<int>& arr, vector<int>& combination, int ind, int r);
void permutations(vector<int>& arr, vector<int>& permutation, int ind, int r);

void printCombination(const vector<int>& arr, int r)
{
    // A temporary array to store
    // all combinations one by one
    vector<int> combination;

    combinations(arr, combination, 0, r);
}

void printPermutation(vector<int>& arr, int r)
{
    // A temporary array to store
    // all permutations one by one
    vector<int> permutation;

    permutations(arr, permutation, 0, r);
}

void combinations(const vector<int>& arr, vector<int>& combination, int ind, int r)
{
    // Current combination is ready
    // to be printed, print it
    if (combination.size() == r)
    {
        for (int j = 0; j < r; ++j)
            cout << combination[j] << " ";
        cout << endl;
        return;
    }

    for (int i = ind; i < arr.size() &&
        r - combination.size() + 1; ++i)
    {
        combination.push_back(arr[i]);
        combinations(arr, combination, i + 1, r);
        combination.pop_back();
    }
}

void permutations(vector<int>& arr, vector<int>& permutation, int ind, int r)
{
    // Current permutation is ready
    // to be printed, print it
    if (permutation.size() == r)
    {
        for (int j = 0; j < r; ++j)
            cout << permutation[j] << " ";
        cout << endl;
        return;
    }

    for (int i = ind; i < arr.size(); ++i)
    {
        int temp = arr[ind];
        arr[ind] = arr[i];
        arr[i] = temp;
        permutation.push_back(arr[ind]);
        permutations(arr, permutation, ind + 1, r);
        permutation.pop_back();
        temp = arr[i];
        arr[i] = arr[ind];
        arr[ind] = temp;
    }
}

// Driver code
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int r = 3;

    cout << "Combinations:" << endl;
    printCombination(arr, r);

    cout << "Permutations:" << endl;
    printPermutation(arr, r);
}
