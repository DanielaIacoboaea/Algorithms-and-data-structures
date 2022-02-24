#include <stdio.h>
#include <cs50.h>
//stiind ca toate sirurile de caractere se termina cu \0 scrieti o functie care calculeaza lungimea unui sir

int string_length(string word)
{
    int length = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        length = length + 1;
    }
    return length;
}
void reversed_word(string word)
{
    int n = string_length(word); 
    for (int i = n-1; i >= 0; i--)
    {
        printf("%c",word[i]);
    }
    printf("\n");
}
int max(int number[], int n)
{
    int max_val = number[0];
    for (int i = 0; i < n; i++)
    {
        if (max_val < number[i])
        {
            max_val = number[i];
        }
    }
    return max_val;
}

int sum(int number[], int n)
{
    int sum_val = 0;
    for (int i = 0; i < n; i++)
    {
        sum_val = sum_val + number[i];
    }
    return sum_val;
}

int large(int a, int b)
{ 
    if (a > b )
    {
        return a;
    }
    else 
    {
        return b;
    }
}

int large3(int a, int b, int c)
{
    return large(large(a,b), c);
}

int second_largest(int number[], int n)
{
    int max_val = number[0];
    int second_val = 0;
    int i;
    for (i = 0; i <= n - 2; i++)
    {
        if (max_val < number[i])
        {
            max_val = number[i];
        }
    }
    if ((i >= n - 2 ) && (i < n))
    {
        if (max_val < number[i])
        {
            second_val = max_val;
        }
        else
        {
            second_val = number[i];
        }
    }
    return second_val;
}

int main(void)
{
    //string word = get_string("Enter word: \n");
    //reversed_word (word);
    int array[1000]; 
    int n = get_int("n = \n");
    for (int i = 0; i < n; i++)
    {
        array[i] = get_int("");
    }
    //int suma = sum(array, n);
    //printf("sum: %i", suma);
    int second_max = second_largest(array, n);
    printf("second to largest is: %i\n", second_max);
}
//string reversed_word(string word);
