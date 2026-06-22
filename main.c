#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void displayMenu() {
    printf("\n========================================\n");
    printf("  GRAPH-BASED ROUTE NAVIGATION SYSTEM\n");
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
    
    printf("\n=== ROUTE NAVIGATION SYSTEM ===\n");
    printf("Initializing system...\n");
    
    
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 
        
        switch(choice) {
            case 1:
                printf("Add Location feature (coming soon)\n");
                break;
            case 2:
                printf("Add Route feature (coming soon)\n");
                break;
            case 3:
                printf("View Locations feature (coming soon)\n");
                break;
            case 4:
                printf("View Routes feature (coming soon)\n");
                break;
            case 5:
                printf("Find Shortest Path feature (coming soon)\n");
                break;
            case 6:
                printf("Save Data feature (coming soon)\n");
                break;
            case 7:
                printf("Load Data feature (coming soon)\n");
                break;
            case 8:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 8);
    
    return 0;
}