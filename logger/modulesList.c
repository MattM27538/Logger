#include <modulesList.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

ModulesList* modulesListInit(){
    static ModulesList* modulesList = NULL;

    //Return error or message if modulesList already initialized
    if(modulesList == NULL){
        modulesList = malloc(sizeof(modulesList));
        //Return error if malloc does not work.
        assert(modulesList && "Failed to allocate memory for modulesList");

        //Leave all values in modulesList null?
    }


    return modulesList;
}