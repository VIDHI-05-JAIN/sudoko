#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to check if num can be placed at grid[row][col]
bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

// Function to solve Sudoku
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool emptySpot = false;
    
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                emptySpot = true;
                break;
            }
        }
        if (emptySpot)
            break;
    }
    
    if (!emptySpot)
        return true;
    
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

// Function to print Sudoku grid
void printGrid(int grid[N][N]) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[N][N];
    
    // Asking user for input
    printf("Enter 81 integers separated by spaces for the Sudoku grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        printf("No solution\n");
    }
    
    return 0;
}
