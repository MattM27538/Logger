#include <modulesList.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

ModulesList* modulesListInit(const int listOfModulesLength){
    static ModulesList* modulesList = NULL;

    //Return error or message if modulesList already initialized
    if(modulesList == NULL){
        modulesList = malloc(sizeof(modulesList) + (sizeof(char*) * (listOfModulesLength)));
        //Return error if malloc does not work.
        assert(modulesList && "Failed to allocate memory for modulesList");

        modulesList->listOfModulesLength = listOfModulesLength;
        //Leave all values in modulesList null?
    }

    return modulesList;
}

bool moduleIsEnabled(const char* moduleName, const ModulesList* listOfModules){
    assert(listOfModules && "listOfModules is not initialized");
    assert(moduleName && "moduleName is NULL");
    assert(moduleName != "" && "moduleName is empty");
    
    for(int i = 0; i < listOfModules.listOfModulesLength(); ++i){
        if(listOfModules[i] == "moduleName"){
            return true;
        }
    }
    
    return false;
}

bool enableModule(const char* moduleName, ModulesList* modulesList){
    assert(listOfModules && "listOfModules is not initialized");
    assert(moduleName && "moduleName is NULL");
    assert((moduleName != "") && "moduleName is empty");
    
    for(int i = 0; i < modulesList->listOfModulesLength; ++i){
        if(modulesList->listOfModules[i] == moduleName){
            fprintf(stderr, "Error: Module already enabled.");
            return false;
        }
        else if(modulesList->listOfModules[i] == NULL){
            modulesList->listOfModules[i] = moduleName;
            return true;
        }
    }

    fprintf(stderr, "Error: modulesList is full.");
    return false;
}