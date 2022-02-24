/* program care sa contina evidenta studentilor unei facultati care sa permita alegerea unei dintre optiuni pastrand lista 
studenilor ordonata dupa nume
- adaugarea unui student in grupa
- afisarea informatiilor despre un anumit student la cautarea dupa nume 
- listarea tututor studentilor din grupa

despre fiecare student se cunosc urmatoarele:
- numele studentului
- media la sfarsitul unei sesiuni
- valoarea bursei
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s{
    char n[256];
    float m;
    int b;
} s;

const int OP_ADD = 1;
const int OP_SEARCH = 2;
const int OP_LIST = 3;
const int OP_QUIT = 4;

int read_student_files(s students[256], char *nume, char *medii, char *burse)
{
    FILE *f1, *f2, *f3;
    int i;
    char name[256];

    f1 = fopen("nume.txt", "r");
    f2 = fopen("media.txt", "r");
    f3 = fopen("bursa.txt", "r");

    i = 0;
    while (!feof(f1) && !feof(f2) && !feof(f3))
    {
        fgets(name, sizeof(name), f1);
        name[strlen(name) - 1] = '\0';
        strcpy(students[i].n, name);
        fscanf(f2, "%f", &students[i].m);
        fscanf(f3, "%d", &students[i].b);
        i++;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    
    return i;
}

void read_student(s *student)
{
    char nume_temp[256], prenume_temp[256];

    printf("Enter student's name & l_name:\n");
    scanf("%s%s", nume_temp, prenume_temp);
    strcpy(student->n, nume_temp);
    strcat(student->n, " ");
    strcat(student->n, prenume_temp); 

    printf("enter m,b:\n");
    scanf("%f,%d", &(student->m), &(student->b));

}

//TODO: fix and test
void add_student(s *to_add, s students[256], int *count)
{
    int i, x, line = 0, j;
    for (i = 0; i < *count; i++)
    {
       // printf("i: %d\n", i);
        x = strcmp(students[i].n, to_add->n);
       // printf("x: %d\n", x);
        if (x >= 0)
        {
            line = i;
           // printf("line: %d\n", line);
            break;
        }
    } 
    for (j = (*count)-1; j >= line; j--)
    {
       // printf("j: %d\n", j);
        students[j+1] = students[j];
       // printf("students[j+1]: %s, students[j]: %s\n", students[j+1].n, students[j].n);
    }
    strcpy(students[line].n, to_add->n);
    //printf("students[line].n: %s\n", students[line].n);
    students[line].m = to_add->m;
    students[line].b = to_add->b;
    count++;
   // printf("count: %d\n", *count);
}

void test_add_student(s list[256], int n)
{
    s elev; 
    int i;
    for (i = 0; i < n; i++)
    {
        read_student(&list[i]);
    }
    read_student(&elev);
    add_student(&elev, list, &n);
    
    //testare inserare intr-un exemplu (fara fisier)
}


void read_student_name(char *name)
{
    char nume_temp[256], prenume_temp[256];
    printf("Enter student's name,l_n:\n");
    /* fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0'; */
    scanf("%s%s", nume_temp, prenume_temp);
    strcpy(name, nume_temp);
    //printf("name strcpy %s\n", name);
    strcat(name, " ");
    // printf("name strcat ""%s\n", name);
    strcat(name, prenume_temp); 
    // printf("name strcat pren "" %s\n", name);
}

//TODO
int search_student(char name[256], s students[256], int count)
{
    int i, idx = -1;
    bool ok = 0;
    for (i = 0; i < count; i++)
    {
        if (strcmp(students[i].n, name) == 0)
        {
            idx = i;
            break;
        }
    }
    return idx;
}
void print_student(int student, s students[256])
{
    printf("%s\n", students[student].n);
    printf("%.2f\n", students[student].m);
    printf("%d\n", students[student].b);
   //TODO
}


int main()
{

    s students[256];
    int i, menu, bursa, line, j, x, count;
    char name[256];
    bool ok = 0;
    float media;
    char nume_temp[256], prenume_temp[256];
    s to_add;

    count = read_student_files(students, "nume.txt", "media.txt", "bursa.txt");

    printf("strlen name: %lu\n", strlen(students[0].n));
    printf("Enter your option, see menu below: \n");
    printf("Add student: 1\n");
    printf("Search student: 2\n");
    printf("List all students: 3\n");
    printf("Exit program: 4\n");
    scanf("%d", &menu);

    while(1)
    {
        switch(menu){
            case OP_ADD:
                read_student(&to_add);
                add_student(&to_add, students, &count);
                for (i = 0; i < count; i++)
                {
                    printf("%s\n", students[i].n);
                }
                break;
            case OP_SEARCH:
                read_student_name(name);
                int index = search_student(name, students, count);
                if (index == -1)
                {
                    printf("Studentul nu este in lista\n");
                }else 
                {
                    print_student(index, students);
                }
                break;
            case OP_LIST:
                for (i = 0; i < count; i++)
                {
                    printf("%s\n", students[i].n);
                }
                break;
            case OP_QUIT:
                exit(0);
                break;
            default:
                printf("The option selected does not exist. Try again!\n");
                break;
        }
    }
    return 0;
}
