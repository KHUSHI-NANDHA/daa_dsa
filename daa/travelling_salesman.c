#include <stdio.h>

int matrix[25][25], 
    visited_cities[10], 
    limit, 
    cost = 0; 

int tsp(int c) {
    int count, nearest_city = 999; 
    int minimum = 999;

    for (count = 0; count < limit; count++) {
        
        if ((matrix[c][count] != 0) && (visited_cities[count] == 0)) {  
            // Find the minimum cost
            if (matrix[c][count] < minimum) {  
                minimum = matrix[c][count];  
                nearest_city = count;        
            }
        }
    }

    // Update the total cost if we found a valid nearest city
    if (nearest_city != 999) {  
        cost += minimum;  
    }
    
    return nearest_city;
}

void minimum_cost(int city) {
    int nearest_city; 
    visited_cities[city] = 1;  
    printf("%d ", city + 1);   
    
    nearest_city = tsp(city);   

    // If no more cities are left to visit, return to the starting city
    if (nearest_city == 999) {  
        nearest_city = 0;  
        printf("%d", nearest_city + 1);  
        cost += matrix[city][nearest_city];  
        return;
    }

    // Recursively find the minimum cost path for the next city
    minimum_cost(nearest_city);
}

int main() {
    int i, j;
    
    printf("Enter Total Number of Cities:\t"); 
    scanf("%d", &limit);
    
    printf("\nEnter Cost Matrix (0 if no direct path):\n"); 
    for (i = 0; i < limit; i++) {
        printf("\nEnter %d Elements in Row[%d]\n", limit, i + 1); 
        for (j = 0; j < limit; j++) {
            scanf("%d", &matrix[i][j]);
        }
        visited_cities[i] = 0;  
    }
    
    printf("\nEntered Cost Matrix:\n"); 
    for (i = 0; i < limit; i++) {
        printf("\n");
        for (j = 0; j < limit; j++) {
            printf("%d ", matrix[i][j]);  
        }
    }
    
    printf("\n\nPath:\t"); 
    minimum_cost(0);  
    
    printf("\n\nMinimum Cost: \t"); 
    printf("%d\n", cost);  
    return 0;
}
