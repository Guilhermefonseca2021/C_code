
int main() {
    int a = 5;
    int b = 10;
    int sum = a + b;
    printf("Hello, University! a soma é: {%d}\n", sum);
    return 0;
}

int conditional_example(int idade) {
    int idade = 45;
    if (idade >= 18) {
        printf("Maior de idade\n");
        return idade;
    } else {
        printf("Menor de idade\n");
        return idade;
    }
}

// build a menu in C
int elevator_system(void) {
    int numero;
    printf("Digite um numero de 1 a 9: \n");

    scanf("%d", &numero);
    printf("1. Option 1\n");

    switch (numero) {
    case 1:
        printf("You selected first floor\n");
        break;
    case 2:
        printf("You selected second floor\n");
        break;
    case 3:
        printf("You selected third floor\n");
        break;
    default:
        printf("Invalid option\n");
        break;
    }
}

int loop_example(void) {
    for (int i = 0; i <= 10; i++) {
        if(i % 2 == 0) {
            printf("Even number: %d\n", i);
        } else {
            printf("Odd number: %d\n", i);
        }
    }
}

int counting_loop(void) {
    int count = 0;
    while(count < 5) {
        printf("Count: %d\n", count);
        count++;
    }
    printf("Finished counting!\n");
}