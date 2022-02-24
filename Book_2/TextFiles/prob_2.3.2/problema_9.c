/* in fisierul text.txt se afla mai multe parole formate din caractere de tip majuscula, scrise fiecare pe cate o linie
fiecareia i se asociaza un numar obtinut ca produs al numerelor de ordine ale literelor in alfabet
de ex pt cuvantul "BAC" numarul asociat este 2*1*3 = 6
sa se creeze fisierul out.txt in care pe cate o linie se afla parolele care au numarul asociat cel mai mare
*/

#include <stdio.h>

int num_order(int a[27][3], int y)
{
    int i, j, order_num;
    for (i = 1; i < 27; i++)
    {
        if (a[i][1] == y)
        {
            order_num = a[i][2];
        }
    }
    return order_num;
}

int main()
{
    FILE *in;
    FILE *out;
    FILE *sorted;
    char x;
    int order[27][3];
    int i, j = 1, a_code = 65, prod = 1, aux, temp_number, max = 0;
    int number[50];
    in = fopen("txt.txt", "r");
    out = fopen("out.txt", "w");
    sorted = fopen("sorted.txt", "w");
    for (i = 1; i <= 26; i++)
    {
        order[i][1] = a_code;
        order[i][2] = j;
        a_code++;
        j++;
    }
    while (!feof(in))
    {
        fscanf(in, "%c", &x);
        if (x != '\n')
        {
            prod = prod * num_order(order, (int)(x));
            
        }else
        {
            fprintf(out, "%d ", prod);
            if (prod > max)
            {
                max = prod;
            }
            fprintf(out, "\n");
            prod = 1;
        }
    }
    i = 0;
    int size = 1;
    while (!feof(out))
    {
        fscanf(out, "%d", &temp_number);
        if ((char)(temp_number) != '\n')
        {
            size++;
            number[i] = temp_number;
            i++;
        }
    }
    for (i = 0; i < size; i++)
    {
        for (j = size - 1; j > i; j--)
        {
            if (number[j] < number[j-1])
            {
                aux = number[j];
                number[j] = number[j-1];
                number[j-1] = aux;
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d\n", number[i]);
    }

    fclose(in);
    fclose(out);
    fclose(sorted);

    return 0;
}
