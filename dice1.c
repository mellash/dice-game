/*dice1.c*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_random(int max) {
  int random_num;
  /*Limiting the rand function output to to 6 digits*/
  random_num = rand() % max + 1;

  return random_num;
}

int main(void) {
  // Disable output buffering for faster response from the stdout
  // and stderr
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);

  int balance, bet, guess;
  /*Get the process id, and use it as a way to produce random number*/
  srand(getpid());

  balance = 1000;

  while (1) {
    /*Getting the bet money*/
    printf("Make your bet: ");
    scanf("%d", &bet);

    /*Getting the user guess*/
    printf("Make your gues(1-6, 0 to quit): ");
    scanf("%d", &guess);

    /*If user type 0 it will quit the game*/
    if (guess == 0) {
      return 0;
    }

    /*Emulating dice throwing*/
    printf("\n");
    printf("🎲\n");
    printf("     🎲\n");
    printf("🎲\n");
    printf("     🎲\n");
    printf("\n");
    sleep(2);

    /*Getting random number from my_random function*/
    int dice = my_random(6);
    printf("The dice is %d\n", dice);

    /*If guess is not the correct dice, reduce the bet from the blance*/
    if (guess != dice) {
      balance -= bet;
      printf("Sorry, you lost 🥲\n");
    } else {
      /*Else triple it, and add the bet to the balance*/
      balance += bet * 3;
      printf("You won, Congratulations 🥳\n");
    }

    /*Print the balance after the bet got reduced or added*/
    printf("Balance: $%d\n", balance);
    printf("\n");

    /*Finally check if the user balance and quit when it reachs 0*/
    if (balance <= 0) {
      printf("GAME OVER 🫠\n");
      return 0;
    }
  }

  return 0;
}
