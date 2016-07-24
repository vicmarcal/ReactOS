/***********************************************************************
* COPYRIGHT:        GPL v3
* FILENAME :        CtrlHandler.c            
*
* DESCRIPTION :
*       An infinite loop until the "5" key is pressed.
*       THIS WILL NEVER WORK (as expected).
*
* PROGRAMMERS :    Víctor Martínez Calvo  (victor.martinez@reactos.org)
*
*
**/


#include <windows.h>
#include <stdio.h>


int main (void)
{

    DOUBLE dCount = 0;

    //Stop just when the user presses key "5". ASCII code 53. 
    while(_getch() != 53)
    {
        // Replace this dumb while body with yours. 
        Sleep(1000);
        dCount++;
    }
    printf("Number of loops: %.0f \n Stopping the program \n", dCount);
    return 0;
}