/* se citeste de la tastatura varsta lui Gigel in secunde 
sa se afiseze varsta in ani, luni si zile stiind ca ne aflam pe 15 iunie 2002.
anii bisecti sunt divizibili cu 4, dar nedivizibili cu 100 sau divizibili cu 400.
de ex 1992 si 2000 ani bisecti, 1900 nu este an bisect.
anii bisecti au 366 zile, spre deosebire de ceilalti 365
*/

#include <stdio.h>

int main()
{
    int age_sec, years = 0, months = 0, days = 0, i;
    printf("Gigel's age in sec: ");
    scanf("%d", &age_sec);

    //1 min = 60 sec, 1 h = 60 min = 3600 sec; 1 zi = 24 h = 86.400 sec; 
    //1 an bisect = 366 zile = 31.622.400 sec
    //1 an normal = 365 zile = 31.536.000 sec
    i = 2001;
    do
    {
        if (i % 4 == 0 && i % 100 != 0)
        {
            age_sec = age_sec - 31622400;
            years += 1;
        }else if ((i % 4 == 0 && i % 100 == 0) || (i % 4 != 0))
        {
            age_sec = age_sec - 31536000;
            years += 1;
        }
        if (age_sec <= 31536000 || age_sec <= 31622400)
        {
            age_sec = age_sec - 86400;
            days += 1;
            if (days == 31)
            {
                months++;
                days = 0;
            }
        }
        i--;
    }while (age_sec > 0);

    printf("Gigel are %d ani, %d luni si %d zile\n", years, months, days);
    return 0;
}
