#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

bool nameIsYourFavourite(string friend_name, string fav_name) {
    return friend_name == fav_name;
}

void BFS(unordered_map <string, vector<string>> graph, string fav_name) {

    int level = 0;
    vector<string> checked;
    deque<string> search_queque;

    // queque initialization with 1st level graph nodes
    for (auto i : graph["Me"]) {
        search_queque.push_back(i);
    }

    while (search_queque.size() != 0) {

        bool is_checked = false;
        string curr_item = search_queque[0];
        search_queque.pop_front();
        level += 1;

        // check whether the node value has been checked previously...
        for (auto item : checked) {
            if (curr_item == item) {
                is_checked = true;
            }
            else {
                is_checked = false;
            }
        }

        if (!is_checked) {
            if (nameIsYourFavourite(curr_item, fav_name)) {
                cout << "Your favorite name is on the list of friends!" << endl;
                cout << "Level: " << level << endl;
                return;
            }
            else {
                checked.push_back(curr_item);
                for (auto item : graph[curr_item]) {
                    search_queque.push_back(item);
                }
            }
        }

        cout << "This name is not on the list of your friends :(" << endl;

        return;
    }
}

int main()
{
    unordered_map <string, vector<string>> graph;

    graph["Me"] = { "Kate", "Alex", "Max" };
    graph["Kate"] = { "John", "Steve" };
    graph["Alex"] = { "John", "Julia" };
    graph["Max"] = {};
    graph["John"] = {};
    graph["Julia"] = {};

    string fav_name = "";

    cout << "What's your favouite name?" << endl;
    cin >> fav_name;
    cout << endl;

    BFS(graph, fav_name);
}

