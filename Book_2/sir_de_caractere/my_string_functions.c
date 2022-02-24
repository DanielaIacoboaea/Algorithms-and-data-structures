/* here will be all the string functions i have ever used and will use to solve problems,
implemented by myself with the my_(prefix)
*/
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

size_t my_strlen(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

void test_my_strlen()
{
    assert(strlen("") == my_strlen(""));
    assert(strlen("abc") == my_strlen("abc"));
    assert(strlen("abc\nasdf") == my_strlen("abc\nasdf"));
    assert(strlen("abc\0asdf") == my_strlen("abc\0asdf"));
}

char *my_strchr(char *str, char c)
{
    for (int i = 0; i <= my_strlen(str); i++)
    {
        if (str[i] == c)
        {
            return &str[i];
        }
    }
    return NULL;
}

void test_my_strchr()
{
    char a[10] = "asdfr";
    assert(strchr(a, 'd') == my_strchr(a, 'd'));
    assert(strchr(a, 'x') == my_strchr(a, 'x'));
    assert(strchr(a, 'a') == my_strchr(a, 'a'));
    assert(strchr(a, 'r') == my_strchr(a, 'r'));
    assert(strchr(a, '\0') == my_strchr(a, '\0'));

    char b[10] = "";
    assert(strchr(b, 'a') == my_strchr(b, 'a'));
}

int my_strcmp(char *str1, char *str2)
{
    int val = 0;
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 == *str2)
        {
            str1++;
            str2++;
        }else if (*str1 > *str2)
        {
            return 1;
        }else if (*str1 < *str2)
        {
            return -1;
        }
    }
    if (*str1 == '\0' && *str2 != '\0')
    {
        val = -1;
    }else if (*str1 != '\0' && *str2 == '\0')
    {
        val = 1;
    }
    return val;
}

int sign (int x)
{
    int s;
    if (x < 0)
    {
        s = -1;
    }else if (x > 0)
    {
        s = 1;
    }else
    {
        s = 0;
    }
    return s;
}

void test_my_strcmp()
{
    char a[25] = "Alfabet";
    char b[25] = "Alfabet";
    char c[25] = "xyz";
    char d[25] = "abe";
    char e[25] = "AlfabetXYZ";
    char f[25] = "alfabet";
    char g[25] = "2alfabet";
    char h[25] = "Alfa";

    assert(sign(strcmp(a, b)) == sign(my_strcmp(a, b)));
    assert(sign(strcmp(a, c)) == sign(my_strcmp(a, c)));
    assert(sign(strcmp(a, d)) == sign(my_strcmp(a, d)));
    assert(sign(strcmp(a, e)) == sign(my_strcmp(a, e)));
    assert(sign(strcmp(a, f)) == sign(my_strcmp(a, f)));
    assert(sign(strcmp(a, g)) == sign(my_strcmp(a, g)));
    assert(sign(strcmp(a, h)) == sign(my_strcmp(a, h)));
    assert(sign(strcmp(a, "")) == sign(my_strcmp(a, "")));
    assert(sign(strcmp("", a)) == sign(my_strcmp("", a)));
    assert(sign(strcmp("", "")) == sign(my_strcmp("", "")));
}

char *my_strcpy(char *dest, char *src)
{
    int i;
    for (i = 0; i <= strlen(src); i++)
    {
        dest[i] = src[i];
    }
    return dest;
}

void test_my_strcpy()
{
    char a[50] = "abc";
    char b[50] = "3vacanta";
 
    assert(my_strcmp(strcpy(a, "d"), my_strcpy(a, "d")) == 0);
    assert(my_strcmp(strcpy(a, "ABCDEF"), my_strcpy(a, "ABCDEF")) == 0);
    assert(my_strcmp(strcpy(a, b), my_strcpy(a, b)) == 0);
    assert(my_strcmp(strcpy(a, "\0"), my_strcpy(a, "\0")) == 0);
    assert(my_strcmp(strcpy(a, "porto cala"), my_strcpy(a, "porto cala")) == 0);
    assert(my_strcmp(strcpy(a, "port\nocal A\n"), my_strcpy(a, "port\nocal A\n")) == 0);
    assert(my_strcmp(strcpy(a, " portocalA \n"), my_strcpy(a, " portocalA \n")) == 0);
    
}


size_t my_strcspn(char *str1, char *str2)
{
    int i, j;
    for (i = 0; i < strlen(str1); i++)
    {
        for (j = 0; j < strlen(str2); j++)
        {
            if(str1[i] == str2[j])
            {
                return i;
            }
        }
    }
    return strlen(str1);
}

void test_my_strcspn()
{

    char a[25] = "ABd23iotft tyrh";
    char b[25] = "taryh";
    
    printf("%lu\n", strcspn(a, " taryh"));
    printf("%lu\n", my_strcspn(a, " taryh"));
    
    assert(strcspn(a, b) == my_strcspn(a, b));
    assert(strcspn(a, "\0") == my_strcspn(a, "\0"));
    assert(strcspn(a, "x") == my_strcspn(a, "x"));
    assert(strcspn(a, " taryh") == my_strcspn(a, " taryh"));
    assert(strcspn(b, "h") == my_strcspn(b, "h"));
    assert(strcspn(a, "A") == my_strcspn(a, "A"));
}

char *my_strcat(char *dest, char *src)
{
    int i = strlen(dest), j;
    for (j = 0; j < strlen(src); j++)
    {
        dest[i] = src[j];
        i++;
    }
    return dest;
}

void test_my_strcat()
{
    //pt ca folosesc acelasi array adauga in continuarea lui la fiecare apelare a functiei pt fiecare exemplu
    char a[100] = "curcubeu multicolor";
    char b[100] = "apare";
    
    assert(my_strcmp(strcat(a, b), my_strcat(a, b)) == 0);
    assert(my_strcmp(strcat(a, " apare dupa ploaie"), my_strcat(a, " apare dupa ploaie")) == 0);
    assert(my_strcmp(strcat(a, "\n"), my_strcat(a, "\n")) == 0);
    assert(my_strcmp(strcat(b, a), my_strcat(b, a)) == 0);
    assert(my_strcmp(strcat(a, "234"), my_strcat(a, "234")) == 0);
}

int is_prefix(char *h, char *n)
{
    int j = 0;
    while (*n != '\0')
    {
        if(h[j] != *n)
        {
            return 0;
        }else
        {
            j++;
            n++;
        }
    }
    return 1;
}

char *my_strstr(char *haystack, char *needle)
{
    int i;
    char *p;
    char v;
    v = needle[0];
    for (i = 0; i < strlen(haystack); i++)
    {
        if (haystack[i] == v)
        {
            p = &haystack[i];
            if (is_prefix(p, needle))
            {
                return p;
            }
        }
    }
    return NULL;
}

void test_my_strstr()
{
    char a[25] = "albnegrugri";
    
    printf("%s\n", strstr(a, "negru"));
    printf("%s\n", my_strstr(a, "negru"));
    printf("%s\n", strstr(a, "albastru"));
    printf("%s\n", my_strstr(a, "albastru"));
    printf("%s\n", strstr(a, "ri"));
    printf("%s\n", my_strstr(a, "ri")); 
    
    assert(strcmp(strstr(a, "negru"), my_strstr(a, "negru")) == 0);
    
    assert(strstr(a, "albastru") == NULL && my_strstr(a, "albastru") == NULL);
    assert(strcmp(strstr(a, "ri"), my_strstr(a, "ri")) == 0);
    assert(strstr(a, "x") == NULL && my_strstr(a, "x") == NULL);
    assert(strstr(a, "gri\n") == NULL && my_strstr(a, "gri\n") == NULL);
    assert(strstr(a, " alb") == NULL && my_strstr(a, " alb") == NULL);
    assert(strcmp(strstr("alb negrugri", "b negru"), my_strstr("alb negrugri", "b negru")) == 0);

}

int main()
{
    test_my_strlen();
    test_my_strchr();
    test_my_strcmp();
    test_my_strcpy();
    test_my_strcspn();
    test_my_strcat();
    test_my_strstr();
}
