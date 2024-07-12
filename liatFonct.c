#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int strFic(FILE *fic)//char count in file
{
    char i;
    int a = 0;
    while ((i = fgetc(fic)) != EOF)
        a++;
        
    return a;
}

int strLine(FILE *fic)//line count in file
{
    char i;
    int a = 0;
    while ((i = fgetc(fic)) != EOF)
        if (i == '\n')
            a++;
        
    return a;

}

/*option -n du fichier*/

void liat(FILE *fic, int nbrLine )//FILE *fic, int nbrLine, 
{
    if (fic == NULL)
        exit(EXIT_FAILURE);
    
    char i;
    int n, l;
    int a;

    nbrLine = strFic(fic);
    rewind(fic);
    l = strLine(fic);
    rewind(fic);
    a = 0;
    
    while ((i = fgetc(fic)) != EOF)
    {
        if (i == '\n')
        {
            a++; 
        }
        if (a >= l-nbrLine)
        {
            putchar(i);
        }
    }

    return ;
}


/*option "-c NUM" afficher les n dernier caractere, les "\n" , "\t"... sont inclus
    En mode "r"
*/
void out_Last_NUM_BYTES__c__(FILE *fic, int nbrChar)
{
    char c;
    int a;
    int i;
    a = strFic(fic);
    rewind(fic);
    
    i = 0;
    while ((c = fgetc(fic)) != EOF)
    {
        if (i >= (a - nbrChar))
        {
            putchar(c);
        }
        i++;
    }

}

/*option "-f" affichage en temps reel du contenue*/
void follow_As_Grows(FILE *fic)
{
    char c;
    int charNumber0;
    int charNumber;

    while ((c = fgetc(fic)) != EOF)
    {
        putchar(c);
    }

    while (1)
    {
        //fclose(fic);
        charNumber = strFic(fic);

        if (charNumber >= charNumber0)
        {
            charNumber0 = charNumber;

            fic = fopen("test", "r");

            while ((c = fgetc(fic)) != EOF)
            {
                putchar(c);
            }
            fclose(fic);
                
        }
        sleep(1);
        system("clear");
    }

}

