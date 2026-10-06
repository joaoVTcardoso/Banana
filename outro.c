#include <stdio.h>

int main(){

    int opcao;
    char destinatario[11];
    float valorDeposito;
    
    while (opcao != 1){
        /* Menu de entrada */
        printf("\n--- Bem vindo ao Sistema de Caixa Eletronico ---\n"); 
        printf("\n(1) Entrar para area de transferencia com senha\n");
        printf("(2) finalizar operacao\n");

        printf("\nDigite opcao desejada: ");
        scanf("%d", &opcao);

        if (opcao == 1){

            /* Menu de transferencia */
            printf("\n--- Area de Transferencia ---\n");
            printf("\n(1) Fazer um deposito\n");
            printf("(2) Verificar saldo\n");
            printf("(3) Opcao 3\n");
            printf("(4) Sair\n");

            printf("\nDigite opcao desejada: ");
            scanf("%d", &opcao);

            while (opcao != 4)
            {
                /* Opcoes do menu de transferencia */
                if (opcao == 1){
                    printf("Para quem deseja destinar a tranferencia: \n");
                    scanf("%c", &destinatario);
                    
                    printf("Qual o valor desejado para a tranferencia: \n");
                    scanf("%f", &valorDeposito);
                    
                    printf("Voce fez uma transferencia para %c de %f", destinatario, valorDeposito);
                    
                }
                else if (opcao == 2)
                {
                    printf("prencher");
                }
                else if (opcao == 3)
                {
                    printf("prencher");
                }  
                
            }
        } 
        else{
            return 0;
        }

        printf("ok");
    }

    printf("\nOperacao finalizada.\n");
    return 0;
}