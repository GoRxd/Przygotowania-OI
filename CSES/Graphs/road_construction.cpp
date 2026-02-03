#include <bits/stdc++.h>

using namespace std;

class DisjointSets
{
private:
    vector<int> parents;
    vector<int> sizes;

public:
    int components = 0;
    int largest = 1;

    DisjointSets(int n)
    {
        parents.resize(n + 1);
        sizes.resize(n + 1, 1);

        for(int i = 1; i <= n; i++)
        {
            parents[i] = i;
        }

        components = n;
    }

    int FindRoot(int a)
    {
        return (parents[a] == a) ? a : a = FindRoot(parents[a]);
    }

    bool Unite(int a, int b)
    {
        int a_root = FindRoot(a);
        int b_root = FindRoot(b);

        if (a_root == b_root)
            return false;

        if (sizes[a_root] <= sizes[b_root])
        {
            swap(a_root, b_root);
        }

        parents[b_root] = a_root;
        sizes[a_root] += sizes[b_root];
        sizes[b_root] = 0;

        components--;
        largest = max(largest, sizes[a_root]);

        return true;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;

    cin >> n >> m;

    DisjointSets ds(n);

    for(int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        ds.Unite(a, b);
        cout << ds.components << " " << ds.largest << "\n";

    }

}
