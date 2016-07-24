/***********************************************************************
* COPYRIGHT:        GPL v3
* FILENAME :        CtrlHandler.c            
*
* DESCRIPTION :
*       Handle CTRL+C signal to not stop abruptly but in a controlled way.
*
* FUNCTIONS :
*       BOOL SignalHandler( cntrlSignal ): Handles the signals received 
*
* PROGRAMMERS :    Víctor Martínez Calvo  (victor.martinez@reactos.org)
*
*
**/


#include <windows.h>
#include <stdio.h>

BOOL bExit;

BOOL WINAPI SignalHandler(DWORD cntrlSignal){
    
    switch (cntrlSignal){

    case CTRL_C_EVENT:
        bExit = TRUE;
        printf("CTRL+C event received \n");
        return TRUE;

    default:
        // bExit keeps being FALSE.
        printf("Event \n");
        return TRUE;
    }
}

int main (void)
{

    DOUBLE dCount = 0;

    //Control the signals received.
    SetConsoleCtrlHandler(SignalHandler, TRUE);

    while(!bExit)
    {
        // Replace this dumb while body with yours. 
        Sleep(1000);
        dCount++;
    }
    printf("Number of loops: %.0f \n Stopping the program \n", dCount);
    return 0;
}