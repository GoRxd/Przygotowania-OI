#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> s;
    stack<int> wynik;
    int liczbaSpTablic = 0;

    for(int i = 0; i < n; i++)
    {
        int a;

        cin >> a;

        if (i == 0)
        {
            s.push(a);
            continue;
        }
        if (!wynik.empty() && a < wynik.top())
        {
            wynik = stack<int>();
            s = stack<int>();
            liczbaSpTablic++;
        }
        else if (!s.empty() && a > s.top())
        {
            wynik.push(s.top());
            s.pop();
        }

        s.push(a);

    }
    cout << liczbaSpTablic + 1;

}
