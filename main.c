#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

// Global graph variable
Graph routeGraph;

// Function to display the main menu
void displayMenu() {
    printf("\n========================================\n");
    printf("  🗺️  GRAPH-BASED ROUTE NAVIGATION SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Location\n");
    printf("2. Add Route\n");
    printf("3. View All Locations\n");
    printf("4. View All Routes\n");
    printf("5. Find Shortest Path (Bellman-Ford)\n");
    printf("6. Save Data\n");
    printf("7. Load Data\n");
    printf("8. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int from, to, distance;
    
    // Initialize the graph
    initGraph(&routeGraph);
    
    printf("\n=== ROUTE NAVIGATION SYSTEM ===\n");
    printf("Graph-Based Route Navigation System\n");
    printf("===================================\n\n");
    
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear input buffer
        
        switch(choice) {
            case 1: // Add Location
                printf("Enter location name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                addLocation(&routeGraph, name);
                break;
                
            case 2: // Add Route
                if(routeGraph.locationCount < 2) {
                    printf("⚠️  Need at least 2 locations to add a route!\n");
                    break;
                }
                displayLocations(&routeGraph);
                printf("\nEnter source location ID: ");
                scanf("%d", &from);
                printf("Enter destination location ID: ");
                scanf("%d", &to);
                printf("Enter distance (in km): ");
                scanf("%d", &distance);
                addRoute(&routeGraph, from, to, distance);
                break;
                
            case 3: // View Locations
                displayLocations(&routeGraph);
                break;
                
            case 4: // View Routes
                displayRoutes(&routeGraph);
                break;
                
            case 5: // Find Shortest Path (Bellman-Ford)
                if(routeGraph.locationCount < 2) {
                    printf("⚠️  Need at least 2 locations to find a path!\n");
                    break;
                }
                displayLocations(&routeGraph);
                printf("\nEnter source location ID: ");
                scanf("%d", &from);
                printf("Enter destination location ID: ");
                scanf("%d", &to);
                bellmanFord(&routeGraph, from, to);
                break;
                
            case 6: // Save Data
                printf("Save Data feature (coming soon)\n");
                break;
                
            case 7: // Load Data
                printf("Load Data feature (coming soon)\n");
                break;
                
            case 8: // Exit
                printf("\n========================================\n");
                printf("  Thank you for using Route Navigator! 🗺️\n");
                printf("========================================\n");
                break;
                
            default:
                printf("❌ Invalid choice! Please enter 1-8.\n");
        }
    } while(choice != 8);
    
    return 0;
}