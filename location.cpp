#include <bits/stdc++.h>
using namespace std;

// Define an Edge structure
struct Edge {
    string destination;
    int distance;
};

// Define a Graph class
class Graph {
private:
    map<string, vector<Edge>> adjList;

public:
    // Constructor that adds all edges
Graph() {
    // Add edges to the graph
    addEdge("City Center", "Park", 6);
    addEdge("City Center", "Hotel Plaza", 15);
    addEdge("City Center", "Central Market", 9);
    addEdge("City Center", "Cafe Harmony", 3);
    addEdge("Park", "Hotel Plaza", 18);
    addEdge("Park", "Shopping Mall Deluxe", 12);
    addEdge("Hotel Plaza", "Cricket Stadium", 24);
    addEdge("Hotel Plaza", "Art Gallery Haven", 30);
    addEdge("Hotel Plaza", "Sky Lounge", 9);
    addEdge("Central Market", "Shopping Mall Deluxe", 6);
    addEdge("Central Market", "Cafe Harmony", 12);
    addEdge("Central Market", "Art Gallery Haven", 21);
    addEdge("Central Market", "Bookworm's Cafe", 18);
    addEdge("Cafe Harmony", "Restaurant Elegance", 9);
    addEdge("Cafe Harmony", "Tech Hub Plaza", 24);
    addEdge("Shopping Mall Deluxe", "Restaurant Elegance", 15);
    addEdge("Shopping Mall Deluxe", "Tech Hub Plaza", 9);
    addEdge("Shopping Mall Deluxe", "Cinema Paradiso", 21);
    addEdge("Cricket Stadium", "Restaurant Elegance", 18);
    addEdge("Cricket Stadium", "Fitness Junction", 12);
    addEdge("Restaurant Elegance", "Cinema Paradiso", 6);
    addEdge("Art Gallery Haven", "Hotel Plaza", 30);
    addEdge("Tech Hub Plaza", "Bookworm's Cafe", 12);
    addEdge("Green Oasis Park", "City Center", 12);
    addEdge("Green Oasis Park", "Restaurant Elegance", 21);
    addEdge("Green Oasis Park", "Fitness Junction", 15);
    addEdge("Fitness Junction", "Cricket Stadium", 12);
    addEdge("Fitness Junction", "Sky Lounge", 18);
    addEdge("Sky Lounge", "Hotel Plaza", 9);
    addEdge("Sky Lounge", "Tech Hub Plaza", 6);
    addEdge("Sky Lounge", "Beachfront Resort", 24);
    addEdge("Cinema Paradiso", "Shopping Mall Deluxe", 21);
    addEdge("Cinema Paradiso", "Beachfront Resort", 30);
    addEdge("Bookworm's Cafe", "Central Market", 18);
    addEdge("Bookworm's Cafe", "Tech Hub Plaza", 12);
    addEdge("Beachfront Resort", "Sky Lounge", 24);
    addEdge("Beachfront Resort", "Cinema Paradiso", 30);
}


    // Add edge to the graph
    void addEdge(const string& source, const string& destination, int distance) {
        adjList[source].push_back(Edge{destination, distance});
        // Since it's bidirectional
        adjList[destination].push_back(Edge{source, distance});
    }

    // Method to print all location points
    void printLocations() {
        cout << "Locations:" << endl;
        for (const auto& pair : adjList) {
            cout << "- " << pair.first << endl;
        }
    }

    // Dijkstra's algorithm to find the shortest path
    map<string, pair<int, string>> dijkstra(const string& source) {
        map<string, pair<int, string>> distances;
        set<pair<int, string>> queue;

        // Initialize distances to infinity and set predecessors to empty
        for (auto& vertex : adjList) {
            distances[vertex.first] = {numeric_limits<int>::max(), ""};
        }

        // Set the distance for the source
        distances[source].first = 0;
        queue.insert({0, source});

        while (!queue.empty()) {
            auto front = *queue.begin();
            queue.erase(queue.begin());

            int distance = front.first;
            string current = front.second;

            // Visit all neighbors
            for (auto& edge : adjList[current]) {
                int newDist = distance + edge.distance;
                if (newDist < distances[edge.destination].first) {
                    queue.erase({distances[edge.destination].first, edge.destination});
                    distances[edge.destination] = {newDist, current};
                    queue.insert({newDist, edge.destination});
                }
            }
        }

        return distances;
    }

    // Method to print the shortest path
    int printShortestPath(const string& source, const string& destination) {
        auto distances = dijkstra(source);
        vector<string> path;
        string current = destination;
        int totalDistance = 0;  // Initialize total distance

        while (current != source) {
            path.push_back(current);
            totalDistance += distances[current].first;  // Accumulate distance
            current = distances[current].second;
        }
        path.push_back(source);

        reverse(path.begin(), path.end());

        cout << "Shortest path from " << source << " to " << destination << ":" << endl;
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
        // cout << "Total distance: " << totalDistance << " km" << endl;  // Print total distance
        return totalDistance; // Return total distance
    }

};

// int main() {
//     Graph g; // Graph is now initialized with all edges
//     g.printLocations(); // Print all locations

//     string source, destination;
//     cout << "Enter source location: ";
//     // cin >> source;
//     getline(cin, source);
//     cout << "Enter destination location: ";
//     // cin >> destination;
//     getline(cin, destination);

//     int distance = g.printShortestPath(source, destination); // Print the shortest path and total distance
//     cout<<distance<<" Km"<<endl;

//     return 0;
// }
