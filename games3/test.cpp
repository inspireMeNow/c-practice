#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int b;
    vector<int> a;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        a.insert(a.begin(), b);
    }
    vector<int>::iterator iter;
    for (;;)
    {
        flag = 0;
        for (iter = a.begin(); iter < a.end(); iter++)
        {
            (*iter)--;
            if (*iter <= 0)
            {
                flag = 1;
                a.erase(iter);
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    if (a.empty())
    {
        cout << "This is a textbook-like blasphemy!" << endl;
    }
    else
    {
        cout << "Nevermind, just use the Twisting Nether." << endl;
    }
    return 0;
}