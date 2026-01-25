#include "../include/logger.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define debug 1

typedef void(*logDestination)(const char*);
static logDestination logDestinationFunctionPointer = logMessageToStdOut; 

void logMessageToStdOut(const char* message){
    //TODO: extract to function and add to logmessagetofile.
    #if debug == 1
        assert(message && "Log message is NULL.");
        assert((strlen(message) > 0) && "Log message is empty.");
    #endif

    time_t currentTime = time(NULL);
    printf("%s: %s", ctime(&currentTime), message);
}

void logMessageToFile(const char* message){
    static FILE* filePointer = NULL;

    if(filePointer == NULL){
        filePointer = logFileInit();
    }

    //TODO switch to fprintf
    fwrite(message, sizeof(char), strlen(message), filePointer);
}

FILE* logFileInit(){
    FILE* filePointer;

    //TODO: Allow for user to choose name
    filePointer = fopen("log.txt", "w");

    if(filePointer == NULL){
        time_t currentTime = time(NULL);
        fprintf(stderr, "%s: Error opening file from source: %s, function: %s\n", ctime(&currentTime), __FILE__, __func__);
    }
    
    return filePointer;
}