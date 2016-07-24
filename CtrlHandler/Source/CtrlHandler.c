/***********************************************************************
* COPYRIGHT:        GPL v3
* FILENAME :        CtrlHandler.c            
*
* DESCRIPTION :
*       CtrlHandler.exe shows how to handle Ctrl + Break, Ctrl + C
*       and other console signals. They will stop, in a controlled 
*       way the main infinite loop.
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
        printf("CTRL+C can't be never received \n");
        return TRUE;
    case CTRL_BREAK_EVENT:
        bExit = TRUE;
        printf("CTRL+BREAK event received \n");
        return TRUE;
    case CTRL_CLOSE_EVENT:
        bExit = TRUE;
        printf("Close event \n");
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

    //Feature: Disable CTRL_C_EVENT signal
    SetConsoleCtrlHandler(NULL, TRUE);


    while(!bExit)
    {
        // Replace this dumb while body with yours. 
        Sleep(1000);
        dCount++;
    }
    printf("Number of loops: %.0f \n Stopping the program \n", dCount);
    return 0;
}