#include <stdbool.h>

//TODO: Move to source file 
typedef struct{
    char* listOfModules[];
    int listOfModulesLength;
} ModulesList;

ModulesList* modulesListInit(const int listOfModulesLength);

//TODO: Remove from interface
bool moduleIsEnabled(const char* moduleName, const ModulesList* modulesList);

bool enableModule(const char* moduleName, ModulesList* modulesList);