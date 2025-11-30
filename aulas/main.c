#include <stdio.h>

int main() {
    int numeros[10];

    for(int i = 0; i < 10; i++) {
        printf("%d", &numeros[i]);
    }
    printf("Enter 10 integers:\n");
    return 0;
}

int phones_array(void) {
    long int phones[5];
    int i;

    for(int i = 0; i < 5; i++) {
        printf("Phone %d: %d\n", i + 1, phones[i]);
        scanf("%ld", &phones[i]);
    }
    return 0;
}

char read_character(void) {
    char name[50];
    printf("Enter your name: \n");
    strcpy("%s", name); // pegou valor existente e fez atrubuicao 
    return name;
    // scanf("%s", name);
}