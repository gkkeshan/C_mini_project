#include<stdio.h>
#include <stdlib.h>

int main()
{
    int Option,choice;
    int g=0;
    while(g<1)
    {
        g=0;
        printf("1. Register [Save data]\n");
        printf("2. Login [Verify eligibility]\n");
        printf("3. Show result\n");
        printf("0. Exit \n");
        printf("Enter your Option: ");
        scanf("%d", &Option);

    if (Option==1)
        {

        }
    else if (Option==2)
        {
        
        }
    else if (Option==3)
        {
            printf("show result\n");
        }
    else if (Option==0)
        {
        g++;
        }
    
    else
        {
            printf("Invalid Option!\n");
             
        }
    }
    
}