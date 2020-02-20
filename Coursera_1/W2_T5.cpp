#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // solution of the problem with daily tasks movement from month to month
    int n;
    cin >> n;

    int month_index = 0;
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> daily_tasks(months[month_index] + 1);

    for (int i = 0; i < n; i++)
    {
        string operation;
        cin >> operation;
        
        if (operation == "DUMP")
        {
            int index;
            cin >> index;
            cout << daily_tasks[index].size();
            for (auto task: daily_tasks[index])
            {
                cout  << " " << task;
            }
            cout << endl;
        }
        else if (operation == "ADD")
        {
            int index;
            string task;
            cin >> index >> task;
            daily_tasks[index].push_back(task);
        }
        else
        {
            ++month_index %= 12;
            int i = months[month_index];

            if (i < months[month_index - 1])
            {
                for (int j = i + 1; j <= months[(month_index - 1) % 12]; j++)
                {
                    daily_tasks[i].insert(end(daily_tasks[i]), begin(daily_tasks[j]), end(daily_tasks[j]));
                    daily_tasks[j].clear();
                }
            }       
        }
    }

    return 0;
}