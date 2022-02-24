/* n elevi
fiecarui elev i se cunoaste numele si prenumele, media notelor de la oral la discip informatia si nota din teza
realizati un program care afiseaza pt fiecare litera a alfabetului numele si prenumele elevului care a obtinut cea mai mare medie
dintre cei ai caror nume de familie incepe cu acea litera 
*/

#include <stdio.h>
#include <string.h>

typedef struct elev{
    char name[256];
    float avg_grade;
} elev;

int main()
{
    int n, i, teza, j, s[256];
    elev students[256];
    elev aux;
    char nume[256], prenume[256];
    float nota_o, medie;
    printf("n:\n");
    scanf("%d", &n);
    for (i = 0; i < 127; i++)
    {
        s[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        printf("Nume,prenume student %d:\n", i);
        scanf("%s%s", nume, prenume);
        strcat(students[i].name, nume);
        strcat(students[i].name, " ");
        strcat(students[i].name, prenume);
        printf("Nota proba orala:\n");
        scanf("%f", &nota_o);
        printf("Nota teza:\n");
        scanf("%d", &teza);
        students[i].avg_grade = (nota_o * 3.0 + teza)/4.0;
    }
    for (i = 0; i < n; i++)
    {
        printf("%s\n", students[i].name);
        printf("%.2f\n", students[i].avg_grade);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if(students[i].avg_grade < students[j].avg_grade)
            {
                aux = students[i];
                students[i] = students[j];
                students[j] = aux;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (!s[(int)students[i].name[0]])
        {
            printf("%s\n", students[i].name);
            s[(int)students[i].name[0]] = 1;
        }
    }

    return 0;
}
