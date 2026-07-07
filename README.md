# Mapify – Shortest Route Finder

Mapify is a console-based route-finding application developed in **C**. It uses **Dijkstra’s shortest-path algorithm** to calculate the shortest route and total distance between selected Indian states and regions.

The project represents locations as vertices in a weighted graph, while the distances between connected locations are stored as edge weights.

## Features

- Supports 30 Indian states and regions
- Allows users to select a source and destination
- Calculates the shortest route using Dijkstra’s algorithm
- Displays the complete path from source to destination
- Displays the total distance of the shortest route
- Uses an adjacency matrix to represent the weighted graph
- Includes validation for invalid menu choices

## Technologies Used

- C Programming
- Data Structures
- Graphs
- Dijkstra’s Algorithm
- Adjacency Matrix
- Arrays and Functions

## How It Works

1. Each state or region is represented as a vertex in the graph.
2. The distance between two connected locations is represented as a weighted edge.
3. The user selects a source and destination.
4. Dijkstra’s algorithm calculates the minimum distance from the source to all reachable vertices.
5. A parent array stores the previous vertex for each location.
6. The program reconstructs and displays the shortest route.

## Supported Locations

1. Andhra Pradesh
2. Arunachal Pradesh
3. Assam
4. Bihar
5. Chhattisgarh
6. Goa
7. Gujarat
8. Delhi
9. Himachal Pradesh
10. Telangana
11. Jharkhand
12. Karnataka
13. Kerala
14. Madhya Pradesh
15. Maharashtra
16. Manipur
17. Meghalaya
18. Mizoram
19. Nagaland
20. Odisha
21. Punjab
22. Rajasthan
23. Sikkim
24. Tamil Nadu
25. Tripura
26. Uttar Pradesh
27. Uttarakhand
28. West Bengal
29. Jammu and Kashmir
30. Ladakh

## Graph Representation

The following hand-drawn weighted graph represents the states and regions used in Mapify. Each numbered point is a location, and each connecting line shows an edge with its corresponding distance.

<p align="center">
  <img src="assets/mapify-graph.png" alt="Mapify weighted graph of Indian states and regions" width="700">
</p>

## Project Structure

```text
Mapify/
├── assets/
│   └── mapify-graph.png
├── mapify.c
└── README.md
```

## Requirements

To compile and run the project, you need:

- GCC compiler, or
- Any C-compatible IDE such as Code::Blocks, Dev-C++, Visual Studio Code, or CLion

## Compilation and Execution

### Using GCC

Compile the program:

```bash
gcc mapify.c -o mapify
```

Run it on Linux or macOS:

```bash
./mapify
```

Run it on Windows:

```bash
mapify.exe
```

## Sample Usage

```text
Welcome To Mapify

Please Enter Source:
15

Please Enter Destination:
6

Shortest path from Maharashtra to Goa:

Maharashtra -> Karnataka -> Goa
Total Distance: 923 km
```

The actual route and distance depend on the values stored in the graph.

## Dijkstra’s Algorithm

Dijkstra’s algorithm finds the shortest path from one source vertex to other vertices in a graph containing non-negative edge weights.

The main steps are:

1. Set the source distance to `0`.
2. Set all other distances to infinity.
3. Select the unvisited vertex with the smallest known distance.
4. Update the distances of its neighbouring vertices.
5. Repeat until all required vertices are processed.
6. Reconstruct the route using the parent array.

## Time Complexity

The current implementation uses an adjacency matrix.

```text
Time Complexity: O(V²)
Space Complexity: O(V²)
```

Here, `V` represents the number of locations.

## Learning Outcomes

This project demonstrates:

- Graph representation using an adjacency matrix
- Implementation of Dijkstra’s algorithm
- Shortest-path reconstruction
- Array and string handling in C
- Modular programming using functions
- Menu-driven console application development
- Algorithmic problem-solving

## Current Limitations

- Distances are manually stored in the adjacency matrix.
- The project does not display a graphical map.
- Only predefined locations can be selected.
- The route data may not match current real-world road distances.
- The adjacency matrix uses more memory than an adjacency-list representation.

## Future Improvements

- Add a graphical user interface
- Display routes on an interactive map
- Use real road-distance data through a map API
- Replace the adjacency matrix with an adjacency list
- Allow users to search locations by name
- Add estimated travel time and transportation cost
- Add more cities and districts
- Develop a web or mobile version
- Validate unreachable destinations
- Store location data in a separate file or database

## Author

**Ishwari Nandargi**

## License

This project is intended for educational purposes. You may modify and use it for learning and academic work.
