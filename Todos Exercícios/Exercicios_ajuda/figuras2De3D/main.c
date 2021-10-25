#include <stdio.h>
#define PI 3.14

void calcula_area_perimetro_quadrado(float lado) {
    printf("\nÁrea quadrado: %.2fm2\n", lado * lado);
    printf("Perímetro quadrado: %.2f\n\n", 4*lado);
}

void calcula_area_perimetro_retangulo(float altura, float base) {
    printf("\nÁrea retangulo: %.2fm2\n", altura * base);
    printf("Perímetro retangulo: %.2f\n\n", 2*altura + 2*base);
}

void calcula_area_perimetro_circulo(float raio) {
    printf("\nÁrea círculo: %.2fm2\n", PI * raio * raio);
    printf("Perímetro círculo: %.2f\n\n", 2 * PI * raio);
}

void calcula_area_perimetro_trapezio(float BaseMaior, float baseMenor, 
                                    float altura, float lado_01, float lado_02) {
    printf("\nÁrea trapézio: %.2fm2\n", ((BaseMaior + baseMenor) * altura) / 2);
    printf("Perímetro trapézio: %.2f\n\n", BaseMaior + baseMenor + lado_01 + lado_02);
}

// triangulo simples
void calcula_area_perimetro_triangulo(float base, float altura, float lado) {
    printf("\nÁrea triângulo: %.2fm2\n", (base * altura) / 2);
    printf("Perímetro triângulo: %.2f\n\n", 3 * lado);
}

void calcula_area_perimetro_losango(float DiagonalMaior, float diagonalMenor, float lado) {
    printf("\nÁrea losangulo: %.2fm2\n", (DiagonalMaior * diagonalMenor)/ 2);
    printf("Perímetro losangulo: %.2f\n\n", 4 * lado);
}

void calcula_volume_cubo(float lado) {
    printf("\nO volume do cubo é: %.2fcm3\n\n", lado * lado * lado);
}

void calcula_volume_esfera(float raio, float altura) {
    printf("\nO volume da esfera é: %.2fcm3\n\n", (4/3) * PI * raio * raio * raio);
}

// Base quadradada
void calcula_volume_piramide(float lado, float altura) {
    printf("\nO volume da piramide é: %.2fcm3\n\n", (lado * lado * altura) / 3);
}

void calcula_volume_cilindro(float raio, float altura) {
    printf("\nO volume do cilindro é: %.2fcm3\n\n", PI * raio * raio * altura);
}

void calcula_volume_cone(float raio, float altura) {
    printf("\nO volume do cone é: %.2fcm3\n\n", (1.0/3.0) * PI * raio * raio * altura);
}

int main() {
    int op, op2;
    float lado, lado_01, lado_02, base, altura, bmenor, Bmaior, dmenor, Dmaior, raio;

    while(1) {
        printf("O que você deseja calcular:\n\n");
        printf("[1] - Figura 2D\n");
        printf("[2] - Figura 3D\n");
        printf("[0] - Sair\n\n");

        printf("Digite uma opção: ");
        scanf("%d", &op);

        if(op == 0)
            break;

        if(op == 1) {
            printf("Qual Figura 2D você deseja calcular: (Em m2)\n\n");
            printf("[1] - Quadrado\n");
            printf("[2] - Retangulo\n");
            printf("[3] - Triangulo\n");
            printf("[4] - Losango\n");
            printf("[5] - Trapézio\n");
            printf("[6] - Circulo\n");
            printf("[0] - Voltar\n\n");

            printf("Digite uma opção: ");
            scanf("%d", &op2);

            switch(op2) {
                case 0:
                    break;
                case 1:
                    printf("Insira o lado:");
                    scanf("%f", &lado);

                    calcula_area_perimetro_quadrado(lado);
                    break;
                case 2:
                    printf("Insira o altura:");
                    scanf("%f", &altura);
                    printf("Insira a base:");
                    scanf("%f", &base);

                    calcula_area_perimetro_retangulo(altura, base);
                    break;
                case 3:
                    printf("Insira o altura:");
                    scanf("%f", &altura);
                    printf("Insira a base:");
                    scanf("%f", &base);
                    printf("Insira o lado:");
                    scanf("%f", &lado);

                    calcula_area_perimetro_triangulo(base, altura, lado);
                    break;
                case 4:
                    printf("Insira a diagonal menor:");
                    scanf("%f", &dmenor);
                    printf("Insira a diagonal maior:");
                    scanf("%f", &Dmaior);
                    printf("Insira o lado:");
                    scanf("%f", &lado);

                    calcula_area_perimetro_losango(Dmaior, dmenor, lado);
                    break;
                case 5:
                    printf("Insira a base menor:");
                    scanf("%f", &bmenor);
                    printf("Insira a base maior:");
                    scanf("%f", &Bmaior);
                    printf("Insira a altura:");
                    scanf("%f", &altura);
                    printf("Insira o lado 1:");
                    scanf("%f", &lado_01);
                    printf("Insira o lado 2:");
                    scanf("%f", &lado_02);

                    calcula_area_perimetro_trapezio(Bmaior, bmenor, altura, lado_01, lado_02);
                    break;
                case 6:
                    printf("Insira o raio:");
                    scanf("%f", &raio);

                    calcula_area_perimetro_circulo(raio);
                    break;
                default:
                    printf("Digite uma opção válida!\n");
                    break;
            }
        } else if (op == 2) {
            printf("Qual Figura 3D você deseja calcular: (Em cm3)\n\n");
            printf("[1] - Cubo\n");
            printf("[2] - Esfera\n");
            printf("[3] - Pirâmide\n");
            printf("[4] - Cilindro\n");
            printf("[5] - Cone\n");
            printf("[0] - Voltar\n\n");

            printf("Digite uma opção: ");
            scanf("%d", &op2);

            switch(op2) {
                case 0:
                    break;
                case 1:
                    printf("Insira o lado:");
                    scanf("%f", &lado);

                    calcula_volume_cubo(lado);
                    break;
                case 2:
                    printf("Insira o raio:");
                    scanf("%f", &raio);
                    printf("Insira a altura:");
                    scanf("%f", &altura);

                    calcula_volume_esfera(raio, altura);
                    break;
                case 3:
                    printf("Insira o lado:");
                    scanf("%f", &lado);
                    printf("Insira a altura:");
                    scanf("%f", &altura);

                    calcula_volume_piramide(lado, altura);
                    break;
                case 4:
                    printf("Insira o raio:");
                    scanf("%f", &raio);
                    printf("Insira a altura:");
                    scanf("%f", &altura);

                    calcula_volume_cilindro(lado, altura);
                    break;
                case 5:
                    printf("Insira o raio:");
                    scanf("%f", &raio);
                    printf("Insira a altura:");
                    scanf("%f", &altura);

                    calcula_volume_cone(raio, altura);
                    break;
                default:
                    printf("Digite uma opção válida!\n");
                    break;
            }   
        }
    }

    return 0;
}