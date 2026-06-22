#ifndef GRAPH_H
#define GRAPH_H

#define MAX_LOCATIONS 100
#define MAX_NAME_LENGTH 50
#define INFINITY 99999


typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} Location;

typedef struct {
    Location locations[MAX_LOCATIONS];
    int adjMatrix[MAX_LOCATIONS][MAX_LOCATIONS];
    int locationCount;
} Graph;


void initGraph(Graph *g);
int addLocation(Graph *g, char *name);
int addRoute(Graph *g, int from, int to, int distance);
void displayLocations(Graph *g);
void displayRoutes(Graph *g);
void bellmanFord(Graph *g, int start, int end);

#endif