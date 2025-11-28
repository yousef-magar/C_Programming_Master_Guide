```c
#include <stdio.h>
#include <string.h>

int main() {

    // MAB LIBS GAME

    char noun[50] = "";
    char verb[50] = "";
    char adjective_01[50] = "";
    char adjective_02[50] = "";
    char adjective_03[50] = "";
    
    printf("Enter an adj. (desc.): ");
    fgets(adjective_01, sizeof(adjective_01), stdin);
    adjective_01[strlen(adjective_01) - 1] = '\0';
    
    
    printf("Enter a noun (anumal or person): ");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun) - 1] = '\0';
    
    
    printf("Enter an adj. (desc.): ");
    fgets(adjective_02, sizeof(adjective_02), stdin);
    adjective_02[strlen(adjective_02) - 1] = '\0';
    
    
    printf("Enter a verb (ending w/ ing): ");
    fgets(verb, sizeof(verb), stdin);
    verb[strlen(verb) - 1] = '\0';


    printf("Enter an adj. (desc.): ");
    fgets(adjective_03, sizeof(adjective_03), stdin);
    adjective_03[strlen(adjective_03) - 1] = '\0';
  
    printf("\nToday I went to a %s zoo.\n", adjective_01);
    printf("In an exhibit, I saw a %s.\n", noun);
    printf("%s was %s and %s!\n", noun, adjective_02, verb);
    printf("I was %s!\n", adjective_03);
  return 0; 
}
```
