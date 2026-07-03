#include <stdio.h>
#include <string.h>
#include "graph.h"

// Initialize the graph - sets all distances to INFINITY
void initGraph(Graph *g) {
    g->locationCount = 0;
    
    // Initialize adjacency matrix with INFINITY
    for(int i = 0; i < MAX_LOCATIONS; i++) {
        for(int j = 0; j < MAX_LOCATIONS; j++) {
            g->adjMatrix[i][j] = INFINITY;
        }
        // Distance from a node to itself is 0
        g->adjMatrix[i][i] = 0;
    }
}

// Add a new location to the graph
int addLocation(Graph *g, char *name) {
    // Check if maximum locations reached
    if(g->locationCount >= MAX_LOCATIONS) {
        printf("Error: Maximum locations reached!\n");
        return -1;
    }
    
    // Check if location already exists
    for(int i = 0; i < g->locationCount; i++) {
        if(strcmp(g->locations[i].name, name) == 0) {
            printf("Error: Location '%s' already exists!\n", name);
            return -1;
        }
    }
    
    // Add the new location
    strcpy(g->locations[g->locationCount].name, name);
    g->locations[g->locationCount].id = g->locationCount;
    g->locationCount++;
    
    printf("✅ Location '%s' added successfully! (ID: %d)\n", name, g->locationCount - 1);
    return g->locationCount - 1;
}

// Add a route between two locations
int addRoute(Graph *g, int from, int to, int distance) {
    // Validate location IDs
    if(from < 0 || from >= g->locationCount) {
        printf("Error: Invalid source location ID!\n");
        return -1;
    }
    if(to < 0 || to >= g->locationCount) {
        printf("Error: Invalid destination location ID!\n");
        return -1;
    }
    
    // Validate distance
    if(distance <= 0) {
        printf("Error: Distance must be positive!\n");
        return -1;
    }
    
    // Check if route already exists
    if(g->adjMatrix[from][to] != INFINITY) {
        printf("Route already exists! Overwriting...\n");
    }
    
    // Add the route (bidirectional for undirected graph)
    g->adjMatrix[from][to] = distance;
    g->adjMatrix[to][from] = distance;
    
    printf("✅ Route added: %s -> %s (%d km)\n", 
           g->locations[from].name, g->locations[to].name, distance);
    return 0;
}

// Display all locations
void displayLocations(Graph *g) {
    if(g->locationCount == 0) {
        printf("⚠️  No locations added yet!\n");
        return;
    }
    
    printf("\n--- 📍 LOCATIONS ---\n");
    printf("ID\tName\n");
    printf("----------------\n");
    for(int i = 0; i < g->locationCount; i++) {
        printf("%d\t%s\n", i, g->locations[i].name);
    }
    printf("----------------\n");
    printf("Total: %d location(s)\n", g->locationCount);
}

// Display all routes
void displayRoutes(Graph *g) {
    if(g->locationCount == 0) {
        printf("⚠️  No locations added yet!\n");
        return;
    }
    
    printf("\n--- 🛣️  ROUTES ---\n");
    printf("From\t\tTo\t\tDistance (km)\n");
    printf("----------------------------------------\n");
    
    int routeFound = 0;
    for(int i = 0; i < g->locationCount; i++) {
        for(int j = i + 1; j < g->locationCount; j++) {
            if(g->adjMatrix[i][j] != INFINITY && g->adjMatrix[i][j] != 0) {
                printf("%s\t\t%s\t\t%d\n", 
                       g->locations[i].name, g->locations[j].name, g->adjMatrix[i][j]);
                routeFound = 1;
            }
        }
    }
    
    if(!routeFound) {
        printf("⚠️  No routes added yet!\n");
    }
}

// Stub for Bellman-Ford (will implement on Day 3)
void bellmanFord(Graph *g, int start, int end) {
    printf("bellmanFord: Will be implemented on Day 3\n");
}