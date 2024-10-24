#include <stdio.h>

int main(int argc, char** argv) {
    int acc = 0;

    for(int i = 0; argv[1][i] != '\0'; ++i) {
        if (i % 2){
            acc += argv[1][i];
            continue;
        }
        acc -= argv[1][i];
    }

    printf("%d\n", acc);
}