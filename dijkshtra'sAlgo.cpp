#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Mapify
{
private:
  static const int V = 30;

  vector<string> locations = {
      "Andra Pradesh",
      "Arunachal Pradesh",
      "Assam",
      "Bihar",
      "Chhattisgarh",
      "Goa",
      "Gujarat",
      "Delhi",
      "Himachal Pradesh",
      "Telangana",
      "Jarkhand",
      "Karnataka",
      "Kerala",
      "Madhya Pradesh",
      "Maharashtra",
      "Manipur",
      "Meghalaya",
      "Mizoram",
      "Nagaland",
      "Odisha",
      "Punjab",
      "Rajasthan",
      "Sikkim",
      "Tamil Nadu",
      "Tripura",
      "Uttar Pradesh",
      "Uttarakhand",
      "West Bengal",
      "Jammu and Kashmir",
      "Ladakh"};

  vector<vector<int>> graph = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 585, 0, 0, 0, 0, 0, 0, 0, 904, 0, 0, 0, 678, 0, 0, 0, 0, 0, 0},

      {0, 0, 538, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 538, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 337, 322, 559, 353, 0, 0, 0, 0, 0, 547, 0, 0, 1076, 0, 0},

      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 346, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 718, 0, 561, 0, 0},

      {0, 0, 0, 0, 0, 634, 632, 0, 0, 504, 732, 0, 0, 410, 0, 0, 0, 0, 0, 0, 1083, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 233, 0, 0, 690, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 891, 790, 0, 0, 0, 0, 0, 0, 652, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 0, 0, 0, 0, 0, 0, 380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 390, 402, 0, 0, 0, 417, 371, 0, 0, 0},

      {0, 0, 0, 0, 0, 0, 0, 380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 235, 0, 0, 0, 0, 0, 265, 0, 245, 236},

      {336, 0, 0, 0, 634, 0, 0, 0, 0, 0, 0, 595, 0, 0, 504, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 0, 346, 632, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 592, 0, 0, 0, 0, 0, 884, 0, 340, 0, 0},

      {585, 0, 0, 0, 0, 233, 0, 0, 0, 595, 0, 0, 866, 0, 592, 0, 0, 0, 0, 0, 0, 0, 0, 735, 0, 0, 0, 0, 0, 0},

      {0, 0, 0, 0, 0, 0, 0, 0, 0, 866, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 363, 0, 0, 0, 0, 0},

      {0, 0, 0, 0, 504, 0, 891, 0, 0, 0, 0, 0, 0, 0, 747, 0, 0, 0, 0, 0, 0, 827, 0, 0, 0, 717, 0, 0, 0, 0},

      {0, 0, 0, 0, 732, 690, 790, 0, 0, 504, 0, 592, 0, 747, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 337, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 322, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 559, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 353, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {904, 0, 0, 0, 410, 0, 0, 0, 0, 0, 592, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 665, 0},

      {0, 0, 0, 0, 0, 0, 0, 390, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 587, 0, 0, 0, 0, 0, 0, 368, 0},

      {0, 0, 652, 0, 0, 0, 0, 402, 0, 0, 0, 0, 0, 827, 0, 0, 0, 0, 0, 0, 587, 0, 0, 0, 0, 733, 0, 0, 0, 0},

      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 637, 0},

      {678, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 735, 363, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 0, 718, 1083, 0, 0, 417, 0, 0, 884, 0, 0, 717, 0, 0, 0, 0, 0, 0, 0, 733, 0, 0, 0, 0, 0, 455, 0, 0},

      {0, 0, 0, 0, 0, 0, 0, 371, 265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 455, 0, 0, 0, 0},

      {0, 0, 1076, 561, 0, 0, 0, 0, 0, 0, 340, 0, 0, 0, 0, 0, 0, 0, 0, 665, 0, 0, 637, 0, 0, 0, 0, 0, 0, 0},

      {0, 0, 0, 0, 0, 0, 0, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 368, 0, 0, 0, 0, 0, 0, 0, 553},

      {0, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 553, 0}};

  // Find the vertex with minimum distance
  int minDistance(const vector<int> &distance,
                  const vector<bool> &visited) const
  {

    int minimum = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++)
    {

      if (!visited[v] &&
          distance[v] <= minimum)
      {

        minimum = distance[v];
        minIndex = v;
      }
    }

    return minIndex;
  }

  // Display the shortest path
  void printShortestPath(
      int source,
      int destination,
      const vector<int> &parent,
      const vector<int> &distance) const
  {

    if (distance[destination] == INT_MAX)
    {
      cout << "\nNo path exists between "
           << locations[source] << " and "
           << locations[destination] << ".\n";

      return;
    }

    vector<int> path;

    int currentVertex = destination;

    // Trace path backwards
    while (currentVertex != -1)
    {

      path.push_back(currentVertex);

      currentVertex = parent[currentVertex];
    }

    // Reverse path so it becomes source -> destination
    reverse(path.begin(), path.end());

    cout << "\n\nShortest path from "
         << locations[source]
         << " to "
         << locations[destination]
         << ":\n\n";

    cout << "Destination\tDistance from Source\tPath\n";

    cout << destination + 1
         << "\t\t"
         << distance[destination]
         << "\t\t\t";

    for (size_t i = 0; i < path.size(); i++)
    {

      cout << locations[path[i]];

      if (i + 1 < path.size())
      {
        cout << " -> ";
      }
    }

    cout << "\n";
  }

  // Dijkstra's shortest path algorithm
  void dijkstra(int source, int destination)
  {

    vector<int> distance(V, INT_MAX);

    vector<bool> visited(V, false);

    vector<int> parent(V, -1);

    distance[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {

      int u = minDistance(distance, visited);

      if (u == -1)
      {
        break;
      }

      visited[u] = true;

      for (int v = 0; v < V; v++)
      {

        if (!visited[v] &&
            graph[u][v] != 0 &&
            distance[u] != INT_MAX &&
            distance[u] + graph[u][v] < distance[v])
        {

          distance[v] =
              distance[u] + graph[u][v];

          parent[v] = u;
        }
      }
    }

    printShortestPath(
        source,
        destination,
        parent,
        distance);
  }

  // Display all locations
  void displayLocations(const string &title) const
  {

    cout << "\n\t" << title << ":\n";
    cout << "\t------------------------\n";

    for (int i = 0; i < V; i++)
    {

      cout << "\t"
           << i + 1
           << "."
           << locations[i]
           << "\n";
    }
  }

public:
  Mapify() = default;

  void run()
  {

    cout << "\t ====================================================\n";
    cout << "\t\t Welcome To Mapify\n";
    cout << "\t ====================================================\n\n";

    displayLocations("Source Locations");

    int sourceChoice;

    cout << "\n\tPlease Enter Source from where you have to travel from above: ";
    cin >> sourceChoice;

    if (sourceChoice < 1 || sourceChoice > V)
    {

      cout << "Invalid Choice. Please Try Again.\n";

      return;
    }

    int source = sourceChoice - 1;

    displayLocations("Destination Locations");

    int destinationChoice;

    cout << "\n\tPlease Enter Destination to where you have to travel from above: ";
    cin >> destinationChoice;

    if (destinationChoice < 1 ||
        destinationChoice > V)
    {

      cout << "Invalid Choice. Please Try Again.\n";

      return;
    }

    int destination = destinationChoice - 1;

    dijkstra(source, destination);
  }
};

int main()
{

  Mapify mapify;

  mapify.run();

  return 0;
}