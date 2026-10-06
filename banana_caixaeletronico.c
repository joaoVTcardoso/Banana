/* Integrantes: Nome 1, Nome 2, Nome 3 */
#include <stdio.h>

int main(){

    int opcao = 0, destino, senha = 0, pinDefinido = 0, pin, tentativas, acertou, sair = 0, ok, i;
    int qtdDepositos = 0, qtdTransferencias = 0;
    char entrada[50], destinatario[15], confirma;
    float valorDeposito, saldo = 0, totalDepositado = 0, totalTransferido = 0;

    while (sair == 0){
        printf("\n======================================\n");
        printf("   Bem vindo ao Sistema de Caixa Eletronico\n");
        printf("======================================\n");
        printf("\n   (1) Entrar para area de transferencia com senha\n");
        printf("   (2) finalizar operacao\n");
        printf("\n--------------------------------------\n");

        printf("Digite opcao desejada: ");
        ok = scanf("%d", &opcao);
        if (ok != 1){
            scanf("%s", entrada);
            opcao = -1;
        }

        if (opcao == 1){

            opcao = 0;

            while (opcao != 4 && sair == 0)
            {
                printf("\n======================================\n");
                printf("   Area de Transferencia\n");
                printf("======================================\n");
                printf("\n   (1) Fazer um deposito\n");
                printf("   (2) Verificar saldo\n");
                printf("   (3) Definir PIN\n");
                printf("   (4) Sair\n");
                printf("\n--------------------------------------\n");

                printf("Digite opcao desejada: ");
                ok = scanf("%d", &opcao);
                if (ok != 1){
                    scanf("%s", entrada);
                    opcao = -1;
                }

                if (opcao == 1){
                    if (pinDefinido == 0){
                        printf("\n[ERRO] Defina senha primeiro antes de poder fazer transferencia\n");
                    }
                    else{
                        acertou = 0;

                        for (tentativas = 0; tentativas < 3 && acertou == 0; tentativas = tentativas + 1){
                            printf("\nInsira seu PIN: ");
                            ok = scanf("%d", &pin);
                            if (ok != 1){
                                scanf("%s", entrada);
                                pin = -1;
                            }

                            if (pin == senha){
                                acertou = 1;
                            }
                            else if (tentativas < 2){
                                printf("[ERRO] PIN incorreto. Tentativas restantes: %d\n", 2 - tentativas);
                            }
                        }

                        if (acertou == 0){
                            printf("\n[ERRO] PIN incorreto 3 vezes. Sistema encerrado.\n");
                            sair = 1;
                        }
                        else{
                            destino = 0;

                            while (destino != 1 && destino != 2){
                                printf("\n--------------------------------------\n");
                                printf("\n   Para onde deseja destinar a transferencia:\n");
                                printf("   (1) Propria\n");
                                printf("   (2) Transferir para outros\n");
                                printf("\n--------------------------------------\n");
                                printf("Digite opcao desejada: ");
                                ok = scanf("%d", &destino);
                                if (ok != 1){
                                    scanf("%s", entrada);
                                    destino = -1;
                                }

                                if (destino != 1 && destino != 2){
                                    printf("\n[ERRO] Opcao invalida\n");
                                }
                            }

                            if (destino == 1){
                                valorDeposito = 0;

                                while (valorDeposito <= 0){
                                    printf("Qual o valor do deposito (use ponto, ex: 10.50): ");
                                    ok = scanf("%f", &valorDeposito);
                                    if (ok != 1){
                                        scanf("%s", entrada);
                                        valorDeposito = 0;
                                    }

                                    if (valorDeposito <= 0){
                                        printf("\n[ERRO] Valor invalido\n");
                                    }
                                }

                                saldo = saldo + valorDeposito;
                                totalDepositado = totalDepositado + valorDeposito;
                                qtdDepositos = qtdDepositos + 1;

                                printf("\n--------------------------------------\n\n");
                                printf("   * Voce depositou R$ %.2f na sua conta\n", valorDeposito);
                                printf("\n\n--------------------------------------\n");
                            }
                            else{
                                printf("Para quem deseja destinar a transferencia (sem espacos): ");
                                scanf("%s", entrada);
                                for (i = 0; i < 14 && entrada[i] != '\0'; i = i + 1){
                                    destinatario[i] = entrada[i];
                                }
                                destinatario[i] = '\0';

                                valorDeposito = 0;

                                while (valorDeposito <= 0){
                                    printf("Qual o valor da transferencia (use ponto, ex: 10.50): ");
                                    ok = scanf("%f", &valorDeposito);
                                    if (ok != 1){
                                        scanf("%s", entrada);
                                        valorDeposito = 0;
                                    }

                                    if (valorDeposito <= 0){
                                        printf("\n[ERRO] Valor invalido\n");
                                    }
                                }

                                confirma = 'x';

                                while (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N'){
                                    printf("Confirmar transferencia de R$ %.2f para %s? (s/n): ", valorDeposito, destinatario);
                                    scanf("%s", entrada);
                                    confirma = entrada[0];

                                    if (confirma != 's' && confirma != 'S' && confirma != 'n' && confirma != 'N'){
                                        printf("\n[ERRO] Digite s para sim ou n para nao\n");
                                    }
                                }

                                if (confirma == 's' || confirma == 'S'){
                                    saldo = saldo - valorDeposito;
                                    totalTransferido = totalTransferido + valorDeposito;
                                    qtdTransferencias = qtdTransferencias + 1;

                                    printf("\n--------------------------------------\n\n");
                                    printf("   * Voce fez uma transferencia para %s de R$ %.2f\n", destinatario, valorDeposito);
                                    printf("\n\n--------------------------------------\n");
                                }
                                else{
                                    printf("\n   * Transferencia cancelada\n");
                                }
                            }
                        }
                    }
                }
                else if (opcao == 2)
                {
                    printf("\n--------------------------------------\n\n");
                    if (saldo == 0){
                        printf("   * vc eh pobre vc n depositou nada na conta ainda\n");
                    }
                    else{
                        printf("   * Seu saldo eh: R$ %.2f\n", saldo);
                    }
                    printf("\n\n--------------------------------------\n");
                }
                else if (opcao == 3)
                {
                    pin = -1;

                    while (pin < 0){
                        printf("\nInsira seu PIN (apenas numeros): ");
                        ok = scanf("%d", &pin);
                        if (ok != 1){
                            scanf("%s", entrada);
                            pin = -1;
                        }

                        if (pin < 0){
                            printf("\n[ERRO] O PIN deve conter apenas numeros\n");
                        }
                    }

                    senha = pin;
                    pinDefinido = 1;
                    printf("\n   * PIN definido com sucesso\n");
                }
                else if (opcao != 4)
                {
                    printf("\n[ERRO] Opcao invalida\n");
                }

            }
        }
        else if (opcao == 2){
            sair = 1;
        }
        else{
            printf("\n[ERRO] Opcao invalida\n");
        }
    }

    printf("\n======================================\n");
    printf("   Resumo da Sessao\n");
    printf("======================================\n");
    printf("\n   * Depositos na propria conta: %d (total R$ %.2f)\n", qtdDepositos, totalDepositado);
    printf("   * Transferencias para outros: %d (total R$ %.2f)\n", qtdTransferencias, totalTransferido);
    printf("   * Saldo final: R$ %.2f\n", saldo);
    printf("\n--------------------------------------\n");
    printf("\nOperacao finalizada.\n");

    return 0;
}