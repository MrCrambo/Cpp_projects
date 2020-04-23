#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <string>

#include "profile.h"

using namespace std;

class ReadingManager {
private:
    static const int MAX_USER_COUNT_ = 100'000;
    static const int MAX_PAGES_ = 1000;

    vector<int> users_to_pages;
    vector<int> pages_to_users;
    vector<double> pages_rating;
    int total_users = 0;

    void updateRating(int page_number) {
        int user_count = 0;
        for (size_t i = 0; i < page_number; ++i) {
            user_count += pages_to_users[i];
        }
        pages_rating[page_number] = user_count * 1.0 / (total_users - 1);
    }

public:
    ReadingManager()
    : users_to_pages(MAX_USER_COUNT_ + 1, 0)
    , pages_to_users(MAX_PAGES_ + 1, 0)
    , pages_rating(MAX_PAGES_ + 1, 0.0)
    {}

    void Read(int user_id, int page_number) {
        if (users_to_pages[user_id] == 0) {
            ++total_users;
        } else {
            --pages_to_users[users_to_pages[user_id]];
        }

        users_to_pages[user_id] = page_number;
        ++pages_to_users[page_number];
    }

    double Cheer(int user_id) {
        if (users_to_pages[user_id] == 0) {
            return 0;
        }
        if (total_users == 1) {
            return 1;
        }
        updateRating(users_to_pages[user_id]);
            return pages_rating[users_to_pages[user_id]];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}