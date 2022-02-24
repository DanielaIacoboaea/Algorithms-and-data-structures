/* se considera doua fisiere i1.txt si i2.txt
unul contine pe fiecare linie cate doua numere reprezentand notele la matematica ale unor elevi, iar liniile
corespunzatoare din celalalt fisier numele acestora codificat printr-o majuscula
i3 - care sa contina majusculele si media la matematica a celor 2 note 

i1: 
10 8 
7 8 
5 9 
10 10 
6 8 
5 6 

i2: 
I
M
V
M
U
D

i3: 
I 9.00
M 7.00
V 7.00
M 10.00
U 7.00
D 5.50
*/

#include <stdio.h>

typedef struct student
{
    float grades;
    char name;
} student;

int main()
{
    FILE *f1, *f2, *f3;
    char n;
    float med;
    int grade_1, grade_2, count = 0;
    student student[10];
    f1 = fopen("i1.txt", "r");
    f2 = fopen("i2.txt", "r");
    f3 = fopen("i3.txt", "w");
    while (!feof(f1) && !feof(f2))
    {
        fscanf(f2, "%c", &n);
        fscanf(f1, "%d%d", &grade_1, &grade_2);
        med = (grade_1 + grade_2)/2.00;
        if (n != '\n' && n != ' ')
        {
            student[count].name = n;
        }else
        {
            fscanf(f2, "%c", &n);
            student[count].name = n;
        }
        student[count].grades = med;
        fprintf(f3, "%c %.2f\n", student[count].name, student[count].grades);
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%c %.2f\n", student[i].name, student[i].grades);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
