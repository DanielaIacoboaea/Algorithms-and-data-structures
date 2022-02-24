// operatii matrici (adunare, scadere si inmultire) cu matrici alocate in heap

#include <stdio.h>
#include <stdlib.h>

void read_array(int **arr, int row, int col)
{
    int i, j;
    for (i = 0; i <row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_array(int **arr, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
           printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void add_arrays(int **a, int **b, int **c, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main()
{
    int rows = 2, cols = 3, i, j;
    int **mat = (int**)malloc(sizeof(int*) * rows);
    for (i = 0; i < rows; i++)
    {
        mat[i] = (int*)malloc(sizeof(int) * cols);
    }
    read_array(mat, rows, cols);
    print_array(mat, rows, cols);
    printf("\n");

    int **a = (int**)malloc(sizeof(int*) * rows);
    for (i = 0; i < rows; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * cols);
    }
    read_array(a, rows, cols);
    print_array(a, rows, cols);

    int **arr_sum = (int**)malloc(sizeof(int*) * rows);
    for (i = 0; i < rows; i++)
    {
        arr_sum[i] = (int*)malloc(sizeof(int) * cols);
    }
    add_arrays(mat, a, arr_sum, rows, cols);
    print_array(arr_sum, rows, cols);

    free(mat);
    free(a);
    free(arr_sum);
    /*
    int i, j, n, m;
    int a[50][50], b[50][50], c[50][50];
    int *p_a = &a[0][0];
    int *p_b = &b[0][0];
    int *p_c = &c[0][0];
    printf("n,m: ");
    scanf("%d,%d", &n, &m);

    p_a = (int*)malloc(n * sizeof(int));

    if (p_a == NULL)
    {
        printf("p_a malloc failed\n");
        exit(0);
    }

    for (i = 0; i < n; i++)
    {
        p_a[i] = (int*)malloc(m * sizeof(int));
    }
    read_array(a, n, m);

    for (i = 0; i <n; i++)
    {
        for (j = 0; j < m; j++)
        {
           printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    p_b = (int*)malloc(n * sizeof(int));

    if (p_b == NULL)
    {
        printf("p_b malloc failed\n");
        exit(0);
    }

    for (i = 0; i < n; i++)
    {
        p_b[i] = (int*)malloc(m * sizeof(int));
    }
    read_array(b, n, m);

    p_c = (int*)malloc(n * sizeof(int));

    if (p_c == NULL)
    {
        printf("p_c malloc failed\n");
        exit(0);
    }

    for (i = 0; i < n; i++)
    {
        p_c[i] = (int*)malloc(m * sizeof(int));
    }
    */
    return 0;
}
