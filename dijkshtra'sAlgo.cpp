#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define V 30
#define MAX_STR_LENGTH 100
#define NUM_STRINGS 30

char strings[NUM_STRINGS][MAX_STR_LENGTH];

char s[100];
char d[100];

int minDistance(int distance[], bool setPath[]) {
  int minDistance = INT_MAX;
  int minIndex;
  int v;

  for (v = 0; v < V; v++) {
    if (!setPath[v] && distance[v] <= minDistance) {
      minDistance = distance[v];
      minIndex = v;
    }
  }
  return minIndex;
}

void printSmallestPath(int src, int destination, int Path[], int distance[]) {
  // Create a temporary array to store the path
  int node,i;
  int path[V];
  int pathLength = 0;
  int currentVertex = destination;

  // Trace the path backward from the destination to the source
  while (currentVertex != -1) {
    path[pathLength++] = currentVertex;
    currentVertex = Path[currentVertex];
  }

  // Print the path in reverse order (from source to destination)
  printf("\n\nShortest path from %s to %s: \n\n", s, d);
  printf("Destination \t Distance from Source \t Path\n");
  printf("%d \t\t %d \t\t\t ", destination + 1, distance[destination]);
  for ( i = pathLength - 1; i >= 0; i--) {
      node=path[i]+1;
      switch (node) {
  case 1:
    strcpy(strings[i], "Andra Pradesh");
    break;
  case 2:
    strcpy(strings[i], "Arunachal Pradesh");
    break;
  case 3:
    strcpy(strings[i], "Assam");
    break;
  case 4:
    strcpy(strings[i], "Bihar");
    break;
  case 5:
    strcpy(strings[i], "Chhattisgarh");
    break;
  case 6:
    strcpy(strings[i], "Goa");
    break;
  case 7:
    strcpy(strings[i], "Gujarat");
    break;
  case 8:
    strcpy(strings[i], "Delhi");
    break;
  case 9:
    strcpy(strings[i], "Himachal Pradesh");
    break;
  case 10:
    strcpy(strings[i], "Telangana");
    break;
  case 11:
    strcpy(strings[i], "Jarkhand");
    break;
  case 12:
    strcpy(strings[i], "Karnataka");
    break;
  case 13:
    strcpy(strings[i], "Kerala");
    break;
  case 14:
    strcpy(strings[i], "Madhya Pradesh");
    break;
  case 15:
    strcpy(strings[i], "Maharashtra");
    break;
  case 16:
    strcpy(strings[i], "Manipur");
    break;
  case 17:
    strcpy(strings[i], "Meghalaya");
    break;
  case 18:
    strcpy(strings[i], "Mizoram");
    break;
  case 19:
    strcpy(strings[i], "Nagaland");
    break;
  case 20:
    strcpy(strings[i], "Odisha");
    break;
  case 21:
    strcpy(strings[i], "Punjab");
    break;
  case 22:
    strcpy(strings[i], "Rajasthan");
    break;
  case 23:
    strcpy(strings[i], "Sikkim");
    break;
  case 24:
    strcpy(strings[i], "Tamil Nadu");
    break;
  case 25:
    strcpy(strings[i], "Tripura");
    break;
  case 26:
    strcpy(strings[i], "Uttar Pradesh");
    break;
  case 27:
    strcpy(strings[i], "Uttarakhand");
    break;
  case 28:
    strcpy(strings[i], "West Bengal");
    break;

  case 29:
    strcpy(strings[i], "Jammu and Kashmir");
    break;
  case 30:
    strcpy(strings[i], "Ladakh");
    break;

  }
    printf("%s", strings[i]);
    if (i > 0) {
      printf(" -> ");
    }
  }
  printf("\n");
}

void dijkstra(int src, int destination, int graph[V][V]) {
  int distance[V];
  bool setPath[V];
  int Path[V];
  int i, count, v;

  for (i = 0; i < V; i++) {
    distance[i] = INT_MAX;
    setPath[i] = false;
    Path[i] = -1;
  }
  distance[src] = 0;

  for (count = 0; count < V - 1; count++) {
    int u = minDistance(distance, setPath);
    setPath[u] = true;

    for (v = 0; v < V; v++) {
      if (!setPath[v] && graph[u][v] && distance[u] != INT_MAX &&
          distance[u] + graph[u][v] < distance[v]) {
        distance[v] = distance[u] + graph[u][v];
        Path[v] = u;
      }
    }
  }
  printSmallestPath(src, destination, Path, distance);
}

int main() {

  int graph[V][V] = {{0, 0, 0, 0, 0,   0, 0, 0, 0,   336, 0, 585, 0, 0, 0,
                      0, 0, 0, 0, 904, 0, 0, 0, 678, 0,   0, 0,   0, 0, 0},
                     {0, 0, 538, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0,   538, 0,   0,   0, 0, 0, 0, 0, 0,   0, 0, 0,    0, 0,
                      337, 322, 559, 353, 0, 0, 0, 0, 0, 547, 0, 0, 1076, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 346, 0, 0,   0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 718, 0, 561, 0, 0},
                     {0, 0, 0, 0, 0,   0, 0, 0, 0, 634, 632,  0, 0, 504, 732,
                      0, 0, 0, 0, 410, 0, 0, 0, 0, 0,   1083, 0, 0, 0,   0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 233, 0, 0, 690,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 891, 790,
                      0, 0, 0, 0, 0, 0, 652, 0, 0, 0, 0, 0, 0, 0,   0},
                     {0, 0, 0, 0, 0, 0,   0,   0, 380, 0, 0,   0,   0, 0, 0,
                      0, 0, 0, 0, 0, 390, 402, 0, 0,   0, 417, 371, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0,   0, 380, 0, 0, 0, 0,   0, 0,   0,
                      0, 0, 0, 0, 0, 235, 0, 0,   0, 0, 0, 265, 0, 245, 236},
                     {336, 0, 0, 0, 634, 0, 0, 0, 0, 0, 0, 595, 0, 0, 504,
                      0,   0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0,   0, 0, 0},
                     {0, 0, 0, 346, 632, 0, 0, 0, 0, 0, 0,   0, 0,   0, 0,
                      0, 0, 0, 0,   592, 0, 0, 0, 0, 0, 884, 0, 340, 0, 0},
                     {585, 0, 0, 0, 0, 233, 0, 0, 0,   595, 0, 0, 866, 0, 592,
                      0,   0, 0, 0, 0, 0,   0, 0, 735, 0,   0, 0, 0,   0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 866, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 363, 0, 0, 0,   0, 0, 0},
                     {0, 0, 0, 0, 504, 0, 891, 0, 0, 0, 0,   0, 0, 0, 747,
                      0, 0, 0, 0, 0,   0, 827, 0, 0, 0, 717, 0, 0, 0, 0},
                     {0, 0, 0, 0, 732, 690, 790, 0, 0, 504, 0, 592, 0, 747, 0,
                      0, 0, 0, 0, 0,   0,   0,   0, 0, 0,   0, 0,   0, 0,   0},
                     {0, 0, 337, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 322, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 559, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 353, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {904, 0, 0, 0, 410, 0, 0, 0, 0, 0, 592, 0, 0,   0, 0,
                      0,   0, 0, 0, 0,   0, 0, 0, 0, 0, 0,   0, 665, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0,   390, 235, 0, 0, 0, 0, 0,   0,
                      0, 0, 0, 0, 0, 0, 587, 0,   0,   0, 0, 0, 0, 368, 0},
                     {0, 0, 0, 0, 0, 0,   652, 402, 0, 0, 0,   0, 0, 827, 0,
                      0, 0, 0, 0, 0, 587, 0,   0,   0, 0, 733, 0, 0, 0,   0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 637, 0, 0},
                     {678, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 735, 363, 0, 0,
                      0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0, 0},
                     {0, 0, 547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0,   0,   0, 718, 1083, 0, 0,   417, 0, 0,
                      884, 0,   0, 717, 0,    0, 0,   0,   0, 0,
                      0,   733, 0, 0,   0,    0, 455, 0,   0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 371, 265, 0, 0,   0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0,   0,   0, 455, 0, 0, 0, 0},
                     {0, 0, 1076, 561, 0,   0, 0, 0,   0, 0, 340, 0, 0, 0, 0,
                      0, 0, 0,    0,   665, 0, 0, 637, 0, 0, 0,   0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0,   0, 0, 245, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 368, 0, 0, 0,   0, 0, 0, 0, 0, 553},
                     {0, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0, 0, 0, 0,   0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 553, 0}};

  int src, destination;
  int n, k = 0;

  printf("\t ====================================================");

  printf("\n \t\t             Welcome To Mapify \n");
  printf("\t ====================================================\n\n");

  k = 0;
  printf("\n\tSource Locations:\n");
  printf("\t-----------------\n");
  printf("\t1.Andra Pradesh\n");
  printf("\t2.Arunachal Pradesh\n");
  printf("\t3.Assam\n");
  printf("\t4.Bihar\n");
  printf("\t5.Chhattisgarh\n");
  printf("\t6.Goa\n");
  printf("\t7.Gujarat\n");
  printf("\t8.Delhi\n");
  printf("\t9.Himachal Pradesh\n");
  printf("\t10.Telangana\n");
  printf("\t11.Jarkhand\n");
  printf("\t12.Karnataka\n");
  printf("\t13.Kerala\n");
  printf("\t14.Madhya Pradesh\n");
  printf("\t15.Maharashtra\n");
  printf("\t16.Manipur\n");
  printf("\t17.Meghalaya\n");
  printf("\t18.Mizoram\n");
  printf("\t19.Nagaland\n");
  printf("\t20.Odisha\n");
  printf("\t21.Punjab\n");
  printf("\t22.Rajasthan\n");
  printf("\t23.Sikkim\n");
  printf("\t24.Tamil Nadu\n");
  printf("\t25.Tripura\n");
  printf("\t26.Uttar Pradesh\n");
  printf("\t27.Uttarakhand\n");
  printf("\t28.West Bengal\n");
  printf("\t29.Jammu and Kashmir\n");
  printf("\t30.Ladakh\n");

  printf("   \n\tPlease Enter Source from where you have to travel from above: ");
  scanf("%d", &n);
  src = n - 1;

  switch (n) {
  case 1:
    strcpy(s, "Andra Pradesh");
    break;
  case 2:
    strcpy(s, "Arunachal Pradesh");
    break;
  case 3:
    strcpy(s, "Assam");
    break;
  case 4:
    strcpy(s, "Bihar");
    break;
  case 5:
    strcpy(s, "Chhattisgarh");
    break;
  case 6:
    strcpy(s, "Goa");
    break;
  case 7:
    strcpy(s, "Gujarat");
    break;
  case 8:
    strcpy(s, "Delhi");
    break;
  case 9:
    strcpy(s, "Himachal Pradesh");
    break;
  case 10:
    strcpy(s, "Telangana");
    break;
  case 11:
    strcpy(s, "Jarkhand");
    break;
  case 12:
    strcpy(s, "Karnataka");
    break;
  case 13:
    strcpy(s, "Kerala");
    break;
  case 14:
    strcpy(s, "Madhya Pradesh");
    break;
  case 15:
    strcpy(s, "Maharashtra");
    break;
  case 16:
    strcpy(s, "Manipur");
    break;
  case 17:
    strcpy(s, "Meghalaya");
    break;
  case 18:
    strcpy(s, "Mizoram");
    break;
  case 19:
    strcpy(s, "Nagaland");
    break;
  case 20:
    strcpy(s, "Odisha");
    break;
  case 21:
    strcpy(s, "Punjab");
    break;
  case 22:
    strcpy(s, "Rajasthan");
    break;
  case 23:
    strcpy(s, "Sikkim");
    break;
  case 24:
    strcpy(s, "Tamil Nadu");
    break;
  case 25:
    strcpy(s, "Tripura");
    break;
  case 26:
    strcpy(s, "Uttar Pradesh");
    break;
  case 27:
    strcpy(s, "Uttarakhand");
    break;
  case 28:
    strcpy(s, "West Bengal");
    break;

  case 29:
    strcpy(s, "Jammu and Kashmir");
    break;
  case 30:
    strcpy(s, "Ladakh");
    break;

  default:
    printf("Invalid Choice . Please Try Again.\n");
    k++;
  }

  if (k == 0) {
    printf("\n\tDestination Locations:\n");
    printf("\t------------------------\n");
    printf("\t1.Andra Pradesh\n");
    printf("\t2.Arunachal Pradesh\n");
    printf("\t3.Assam\n");
    printf("\t4.Bihar\n");
    printf("\t5.Chhattisgarh\n");
    printf("\t6.Goa\n");
    printf("\t7.Gujarat\n");
    printf("\t8.Delhi\n");
    printf("\t9.Himachal Pradesh\n");
    printf("\t10.Telangana\n");
    printf("\t11.Jarkhand\n");
    printf("\t12.Karnataka\n");
    printf("\t13.Kerala\n");
    printf("\t14.Madhya Pradesh\n");
    printf("\t15.Maharashtra\n");
    printf("\t16.Manipur\n");
    printf("\t17.Meghalaya\n");
    printf("\t18.Mizoram\n");
    printf("\t19.Nagaland\n");
    printf("\t20.Odisha\n");
    printf("\t21.Punjab\n");
    printf("\t22.Rajasthan\n");
    printf("\t23.Sikkim\n");
    printf("\t24.Tamil Nadu\n");
    printf("\t25.Tripura\n");
    printf("\t26.Uttar Pradesh\n");
    printf("\t27.Uttarakhand\n");
    printf("\t28.West Bengal\n");
    printf("\t29.Jammu and Kashmir\n");
    printf("\t30.Ladakh\n");

    printf("   \n\tPlease Enter Destination to where you have to travel from "
           "above: ");
    scanf("%d", &n);
    destination = n - 1;

    switch (n) {
    case 1:
      strcpy(d, "Andra Pradesh");
      break;
    case 2:
      strcpy(d, "Arunachal Pradesh");
      break;
    case 3:
      strcpy(d, "Assam");
      break;
    case 4:
      strcpy(d, "Bihar");
      break;
    case 5:
      strcpy(d, "Chhattisgarh");
      break;
    case 6:
      strcpy(d, "Goa");
      break;
    case 7:
      strcpy(d, "Gujarat");
      break;
    case 8:
      strcpy(d, "Delhi");
      break;
    case 9:
      strcpy(d, "Himachal Pradesh");
      break;
    case 10:
      strcpy(d, "Telangana");
      break;
    case 11:
      strcpy(d, "Jarkhand");
      break;
    case 12:
      strcpy(d, "Karnataka");
      break;
    case 13:
      strcpy(d, "Kerala");
      break;
    case 14:
      strcpy(d, "Madhya Pradesh");
      break;
    case 15:
      strcpy(d, "Maharashtra");
      break;
    case 16:
      strcpy(d, "Manipur");
      break;
    case 17:
      strcpy(d, "Meghalaya");
      break;
    case 18:
      strcpy(d, "Mizoram");
      break;
    case 19:
      strcpy(d, "Nagaland");
      break;
    case 20:
      strcpy(d, "Odisha");
      break;
    case 21:
      strcpy(d, "Punjab");
      break;
    case 22:
      strcpy(d, "Rajasthan");
      break;
    case 23:
      strcpy(d, "Sikkim");
      break;
    case 24:
      strcpy(d, "Tamil Nadu");
      break;
    case 25:
      strcpy(d, "Tripura");
      break;
    case 26:
      strcpy(d, "Uttar Pradesh");
      break;
    case 27:
      strcpy(d, "Uttarakhand");
      break;
    case 28:
      strcpy(d, "West Bengal");
      break;
    case 29:
      strcpy(s, "Jammu and Kashmir");
      break;
    case 30:
      strcpy(s, "Ladakh");
      break;

    default:
      printf("Invalid Choice . Please Try Again.\n");
      k++;
    }

    if (k == 0) {
      dijkstra(src, destination, graph);
    }

    return 0;
  }
}
