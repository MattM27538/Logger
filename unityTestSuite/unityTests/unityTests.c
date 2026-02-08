#include "../unity.h"
#include "../unity.c"
#include "../../include/modulesList.h"
#include <stdbool.h>


void setUp(){}

// void testmodulesListInit(){

// }
//TODO: Change array to variable size array?
void addModulesToModulesList(ModulesList* modulesList, const char* arrayOfModuleNames[], const int arrayOfModuleNamesLength){
    for(int i = 0, i < arrayOfModuleNamesLength; ++i){
        enableModule(listOfModules[i], modulesList);
    }
}

void testEnableModuleListIsFull(){
    const int numberOfModules = 5;
    modulesList* modulesList = modulesListInit(numberOfModules);
    // modulesList* modulesList = NULL;
    // modulesList = modulesListInit(numberOfModules);

    const char* arrayOfModuleNames[numberOfModules] = {"module1, module2, module3, module4, module5"};
    addModulesToModulesList(modulesList, arrayOfModuleNames, numberOfModules);

    TEST_ASSERT(enableModule("module6", modulesList) == false);
}

void tearDown(){

}

int main(){
    UNITY_BEGIN();

    RUN_TEST(testEnableModuleListIsFull);

    return UNITY_END();
}