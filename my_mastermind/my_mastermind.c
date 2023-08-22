#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int is_duplicate(char* str, int num){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == (num + '0')){
            return 1;
        }
    }
    return 0;
}

char* gen_rand() {
    srand(time(0));
    int i = 0;
    char* result = malloc(sizeof(char)*5);
    while( i < 4 ){
        int rand_num = rand() % 9;
        if( is_duplicate(result, rand_num)== 1 ) { continue; }

        result[i] = rand_num + '0';
        i++;
    }
    result[5] = '\0';

    return result;
}

void generateCode(char *code) {
    char* random_code = gen_rand();
    strncpy(code, random_code, 4);
    free(random_code);
}

int main(int argc, char **argv) {
    char secretCode[5] = {0};
    int attempts = 10;
    int opt;
    while ((opt = getopt(argc, argv, "c:t:")) != -1) {
        switch (opt) {
            case 'c':
                strncpy(secretCode, optarg, 4);
                break;
            case 't':
                attempts = atoi(optarg);
                break;
            default:
                printf("Invalid option\n");
                return 1;
        }
    }
    if (!secretCode[0]) generateCode(secretCode);
    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    for (int i = 0; i < attempts; i++) {
        printf("---\nRound %d\n>", i+1);
        fflush(stdout);
        char guess[5] = {0};
        int wellPlaced = 0, misplaced = 0, guessLen = 0;
        char c;
        while (read(0, &c, 1) > 0 && c != '\n') {
            if (guessLen < 4) {
                guess[guessLen++] = c;
            }
        }
        if (guessLen != 4) {
            printf("Wrong input!\n");
            continue;
        }
        for (int z = 0; z < 4; z++) {
            if (guess[z] == secretCode[z]) wellPlaced++;
            else {
                for (int k = 0; k < 4; k++) {
                    if (guess[z] == secretCode[k]) {
                        misplaced++;
                        break;
                    }
                }
            }
        }
        if (wellPlaced == 4) {
            printf("Congratz! You did it!\n");
            return 0;
        } else {
            printf("Well placed pieces: %d\nMisplaced pieces: %d\n", wellPlaced, misplaced);
        }
    }
    printf("You failed to find the secret code in the given number of attempts\n");
    return 0;
}
