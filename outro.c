#include <stdio.h>

int main(){

    int opcao = 0, destino;
    char destinatario;
    float valorDeposito, saldo = 0;
    
    while (opcao != 1){
        /* Menu de entrada */
        printf("\n--- Bem vindo ao Sistema de Caixa Eletronico ---\n"); 
        printf("\n(1) Entrar para area de transferencia com senha\n");
        printf("(2) finalizar operacao\n");

        printf("\nDigite opcao desejada: ");
        scanf("%d", &opcao);

        if (opcao == 1){

            opcao = 0;

            while (opcao != 4)
            {
                /* Menu de transferencia */
                printf("\n--- Area de Transferencia ---\n");
                printf("\n(1) Fazer um deposito\n");
                printf("(2) Verificar saldo\n");
                printf("(3) Opcao 3\n");
                printf("(4) Sair\n");

                printf("\nDigite opcao desejada: ");
                scanf("%d", &opcao);

                /* Opcoes do menu de transferencia */
                if (opcao == 1){
                    printf("\nPara onde deseja destinar a transferencia: \n");
                    printf("(1) Propria\n");
                    printf("(2) Transferir para outros\n");
                    printf("\nDigite opcao desejada: ");
                    scanf("%d", &destino);

                    if (destino == 1){
                        printf("Qual o valor desejado para o deposito: \n");
                        scanf("%f", &valorDeposito);

                        saldo = saldo + valorDeposito;

                        printf("Voce depositou %.2f na sua conta\n", valorDeposito);
                    }
                    else if (destino == 2){
                        printf("Para quem deseja destinar a tranferencia: \n");
                        scanf(" %c", &destinatario);
                        
                        printf("Qual o valor desejado para a tranferencia: \n");
                        scanf("%f", &valorDeposito);

                        saldo = saldo - valorDeposito;
                        
                        printf("Voce fez uma transferencia para %c de %.2f\n", destinatario, valorDeposito);
                    }
                    else{
                        printf("Opcao invalida\n");
                    }
                    
                }
                else if (opcao == 2)
                {
                    if (saldo == 0){
                        printf("vc eh pobre vc n depositou nada na conta ainda\n");
                    }
                    else{
                        printf("Seu saldo eh: %.2f\n", saldo);
                    }
                }
                else if (opcao == 3)
                {
                    printf("prencher");
                }  
                
            }
        } 
        else{
            printf("\nOperacao finalizada.\n");
            return 0;
        }

        printf("ok");
    }

    printf("\nOperacao finalizada.\n");
    return 0;
}
