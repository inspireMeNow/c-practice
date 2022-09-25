#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int b;
    vector<int> a;
    bool is = false;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        a.insert(a.end(), b);
    }
    vector<int>::iterator iter,iter1;
    for (iter = a.begin(); iter < a.end(); iter++)
    {
        if (*iter - 1 <= 0)
        {
            for (iter1 = a.begin(); iter1 < a.end(); iter1++)
            {
                (*iter1)--;
            }
        }
    }
    for (iter = a.begin(); iter < a.end(); iter++)
    {
        if (*iter > 0)
        {
            is = true;
            break;
        }
    }
    if (is)
    {
        cout << "Nevermind, just use the Twisting Nether." << endl;
    }
    else
    {
        cout << "This is a textbook-like blasphemy!" << endl;
    }
    return 0;
}