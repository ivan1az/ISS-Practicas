
#include <stdio.h>
#include <stdlib.h> // Para rand() y srand()
#include <time.h>   // Para time()

#define MAX 10 // Tamaño máximo definido en la práctica

// Prototipos de funciones
void llenarMatriz(int matriz[MAX][MAX], int n);
void mostrarMatriz(int matriz[MAX][MAX], int n);
void mostrarEstadisticas(int matriz[MAX][MAX], int n);
void transponerYMostrar(int matriz[MAX][MAX], int n);

int main() {
    // Semilla para números aleatorios basada en el tiempo actual
    srand(time(0)); 

    int matriz[MAX][MAX];
    int n;

    printf("--- PRACTICA 1: ARREGLOS BIDIMENSIONALES ---\n");
    
    // Validación del tamaño (No mayor de 10 según instrucciones)
    do {
        printf("Ingrese el tamano de la matriz (filas/columnas, max 10): ");
        scanf("%d", &n);
        
        // Limpieza de buffer para macOS/Linux para evitar saltos de línea residuales
        while ((getchar()) != '\n'); 

        if (n < 1 || n > 10) {
            printf("Error: El tamano debe estar entre 1 y 10.\n");
        }
    } while (n < 1 || n > 10);

    // 1. Llenar con random 1-100
    llenarMatriz(matriz, n);

    // 2. Mostrar arreglo completo
    printf("\n[ Matriz Original ]\n");
    mostrarMatriz(matriz, n);

    // 3. Suma, pares, impares, divisibles entre 7
    mostrarEstadisticas(matriz, n);

    // 4. Obtener y mostrar Transpuesta
    printf("\n[ Matriz Transpuesta ]\n");
    transponerYMostrar(matriz, n);

    printf("\nPresione Enter para salir...\n");
    getchar(); // Pausa para ver resultado
    return 0;
}

// Función para llenar la matriz con valores aleatorios entre 1 y 100
void llenarMatriz(int matriz[MAX][MAX], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1; 
        }
    }
}

// Función para mostrar la matriz con formato alineado
void mostrarMatriz(int matriz[MAX][MAX], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            // %4d imprime el entero ocupando 4 espacios para alineación visual
            printf("%4d", matriz[i][j]); 
        }
        printf("\n");
    }
}

// Función para cálculos estadísticos (Suma, Pares, Impares, Divisibles)
void mostrarEstadisticas(int matriz[MAX][MAX], int n) {
    int suma = 0, pares = 0, impares = 0, div7 = 0;
    int i, j, valor;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            valor = matriz[i][j];
            suma += valor;
            
            if (valor % 2 == 0) pares++;
            else impares++;

            if (valor % 7 == 0) div7++;
        }
    }

    printf("\n--- Estadisticas ---\n");
    printf("Suma total: %d\n", suma);
    printf("Elementos pares: %d\n", pares);
    printf("Elementos impares: %d\n", impares);
    printf("Divisibles entre 7: %d\n", div7);
}

// Función para generar y mostrar la transpuesta
void transponerYMostrar(int matriz[MAX][MAX], int n) {
    int transpuesta[MAX][MAX];
    int i, j;

    // Lógica de transposición: fila pasa a ser columna
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
    mostrarMatriz(transpuesta, n);
}