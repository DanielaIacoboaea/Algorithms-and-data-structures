/* se citeste un sir de n (n < 500) numere naturale
care este numarul maxim si de cate ori apare in cadrul sirului?
ex: n = 5 si vectorul (8, 9, 6, 9, 9) se va afisa 9 apare de 3 ori
*/

#include <stdio.h>

int main()
{
    int nums[500];
    int i, max, count = 0, n;
    printf("n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("nums[%d]: ", i);
        scanf("%d", &nums[i]);
    }
    max = nums[0];
    for (i = 1; i < n; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (nums[i] == max)
        {
            count++;
        }
    }
    printf("numarul maxim este: %d si apare de %d ori\n", max, count);
    return 0;
}
