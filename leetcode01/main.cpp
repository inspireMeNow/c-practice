#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>
int main()
{
    std::vector<int> nums;
    std::string s_num;
    getline(std::cin, s_num);
    for (int i = 0; i < s_num.length(); i++)
    {

        if (s_num.at(i) >= 48 && s_num.at(i) <= 57)
        {
            nums.push_back(s_num.at(i) - 48);
        }
    }
    sort(nums.begin(), nums.end());
    std::vector<int>::iterator iter = nums.begin();
    int flag_1 = 0, flag_2 = 0;
    for (iter = nums.begin(); iter < nums.end(); iter++)
    {
        if ((*iter) == 1)
        {
            if (flag_1 == 0)
                nums.erase(iter);
            flag_1 = 1;
        }
        if ((*iter) == 2)
        {
            if (flag_2 == 0)
                nums.erase(iter);
            flag_2 = 1;
        }
        if (flag_1 == 1 && flag_2 == 1)
        {
            break;
        }
    }
    if (nums.size() % 2 == 0)
    {
        printf("%.5f",((float)nums.at(nums.size() / 2 - 1) + (float)nums.at(nums.size() / 2)) / 2);
    }
    else
    {
        printf("%.5f",(float)nums.at(nums.size() / 2));
    }
    return 0;
}