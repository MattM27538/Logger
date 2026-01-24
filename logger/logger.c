#include "../include/logger.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define debug 1

void logMessageToStdOut(const char* message){
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

    fwrite(message, sizeof(char), strlen(message), filePointer);
}
