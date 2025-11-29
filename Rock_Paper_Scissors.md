```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getComputerChoice();
int getUserChoice();
void checkWinner(int userChoice, int computerChoic);

int main(){

    // Rock Paper Scissors

    srand(time(NULL));

    printf("*** ROCK PAPER SCISSORS ***");

    int userChoice = getUserChoice();
    int ComputerChoice = getComputerChoice();

    // printf("%d\n", computerChoice);  // Output: 1 or 2 or 3
    // printf("%d\n", userChoice);  // Output: chose 1 or 2 or 3
    
    switch (userChoice)
    {
    case 1:
        printf("U chose ROCK!\n");
        break;
    
    case 2:
        printf("U chose PAPER!\n");
        break;
    case 3:
        printf("U chose SCISSORS!\n");
        break;
    }
    
    switch (ComputerChoice)
    {
    case 1:
        printf("Computer chose ROCK!\n");
        break;
    
    case 2:
        printf("Computer chose PAPER!\n");
        break;
    case 3:
        printf("Computer chose SCISSORS!\n");
        break;
    }

    checkWinner(userChoice, ComputerChoice);
    return 0;
}


int getComputerChoice(){
    return (rand() % 3) + 1;
}

int getUserChoice(){
    int choice = 0;

    do{
        printf("Choose an option\n");
        printf("1. ROCK\n");
        printf("2. PAPER\n");
        printf("3. SCISSORS\n");
        printf("Enter ur choice: \n");
        scanf("%d", &choice);
    }while(choice < 1 || choice > 3);

    return choice;
}
void checkWinner(int userChoice, int computerChoic){
    if(userChoice == computerChoic){
        printf("It's a TIE!");
    }
    else if((userChoice == 1 && computerChoic == 3) || (userChoice == 2 && computerChoic == 3) || (userChoice == 3 && computerChoic == 3) ){
        printf("U WIN!");
    }
    else{
        printf("U LOSE!");
    }
}
```
