#include <cassert.h>
#include <time.h>
#include <stdio.h>

#define debug

void logMessage(const char* message){
    #if debug == 1
        assert(message && "Log message is NULL.");
        assert((strlen(message) > 0) && "Log message is empty.");
    #endif

    time_t currentTime = time(NULL);
    printf("%s: %s", ctime(&currentTime), message);
}