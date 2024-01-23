/* =============================================================================
   MAIN NOTES about Dijkstra's algorithm:

    1. Dijkstra's algorithm calculates the shortest path in a weighted graph;
    2. Dijkstra's algorithm only works if all weights are positive;
================================================================================ */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string findLowestCostNode(unordered_map<string, int>* p_costs, vector<string>* processed)
{
    int lowest_cost = INT_MAX;
    string lowest_cost_node;

    // Loop through all nodes in the costs table
    for (auto node : *p_costs) {

        bool is_processed = false;

        // Check if the current node has been processed...
        for (auto processed_item : *processed) {
            if (node.first == processed_item) {
                is_processed = true;
                break;
            }
        }
        
        //...if no and node cost is less than current lowest_cost value...
        if (node.second < lowest_cost and is_processed == false) {
            //...designate the current node as the node with the lowest cost
            lowest_cost = node.second;
            lowest_cost_node = node.first;
        }
    }

    return lowest_cost_node;
}

int dijkstrasAlgorithm(unordered_map<string, unordered_map<string, int>> graph, 
                                            unordered_map<string, int>* p_costs, 
                                                unordered_map<string, string>* p_parents) 
{
    unordered_map<string, int> neighbors = {};
    vector<string> processed = {};
    string node = "";
    int cost = 0;

    // Find the node with the lowest cost among the not prosecced
    node = findLowestCostNode(p_costs, &processed);


    // As long as not prosecced nodes exist
    while (!node.empty()) {
        cost = p_costs->at(node);
        neighbors = graph[node];
        // Loop through all neighbors of the current node
        for (auto neighbor_node : neighbors) {
            int new_cost = cost + neighbor_node.second;
            // If a node can be reached faster through a neighbor, 
            //                          then update the cost and parent of this node
            if (new_cost < p_costs->at(neighbor_node.first)) {
                p_costs->at(neighbor_node.first) = new_cost;
                p_parents->at(neighbor_node.first) = node;
            }
        }
        //Mark a node as processed and find a new node with the lowest cost
        processed.push_back(node);
        node = findLowestCostNode(p_costs, &processed);
    }

    return p_costs->at("Finish");
}

int main()
{
    unordered_map<string, int> costs;
    unordered_map<string, string> parents;
    unordered_map<string, unordered_map<string, int>> graph;

    costs["A"] = 4;
    costs["B"] = 6;
    costs["Finish"] = INT_MAX;

    parents["A"] = "Start";
    parents["B"] = "Start";
    parents["Finish"] = {};

    graph["Start"]["A"] = 4;
    graph["Start"]["B"] = 6;
    graph["A"]["Finish"] = 3;
    graph["B"]["A"] = 1;
    graph["B"]["Finish"] = 2;
    graph["Finish"] = {};

    cout << dijkstrasAlgorithm(graph, &costs, &parents) << endl;
}
