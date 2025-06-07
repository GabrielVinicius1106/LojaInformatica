#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions/lerInteiroSeguro.h"
#include "functions/validarEstado.h"
#define MAX_CARRINHO 32

struct Produto {
    char nome[64];
    double preco;
};

struct ItemCarrinho {
    struct Produto produto;
    int quantidadeItens; 
};


void delay(int milliseconds) {
    #ifdef _WIN32
        #include <windows.h>
        Sleep(milliseconds);    
    #else
        #include <unistd.h>
        usleep(milliseconds * 1000);
    #endif
}

void exibirInformacao() {

    system("clear || cls");

    printf ("\n ******************************************");
    printf ("\n **           SUAS INFORMACOES           **\n");
    printf (" ******************************************\n");

}

void loading(char *message){

    for (int i = 0; i < 3; i++){
        system("clear || cls");
        printf(" %s. \n", message);
        delay(250);
        system("clear || cls");
        printf(" %s.. \n", message);
        delay(250);
        system("clear || cls");
        printf(" %s... \n", message);
        delay(250);
        system("clear || cls");
    }
}

int main() {

    int option, optionProcessor, optionVideoCard, optionMotherBoard, optionDisk, optionMemory, optionFont, qntd = 0, nItem = 0;
    int voltar;
    char warning[64] = "";
    char name[100], UF[10], city[100], street[100], methodPayment[16];
    int number = 0, timesPayment = 0, optionPayment = 0;
    double percentageOff = 0; 

    struct Produto processador1 = {"Ryzen 5 3600", 700.0};
    struct Produto processador2 = {"Ryzen 7 5700X", 1200.0};
    struct Produto processador3 = {"Intel Core i9 13400", 2450.0};

    struct Produto placaVideo1 = {"Geforce GTX 1660 Super", 1100.0};
    struct Produto placaVideo2 = {"RX 580", 540.0};
    struct Produto placaVideo3 = {"Geforce RTX 4080 TI", 5400.0};

    struct Produto motherBoard1 = {"Gigabyte B550M Aorus Elite AM4", 900.0};
    struct Produto motherBoard2 = {"Biostar A320MH AM4", 390.0};
    struct Produto motherBoard3 = {"Gigabyte B760M Aorus Elite LGA 1700", 1200.0};

    struct Produto armazenamento1 = {"SSD Kingston 240GB", 130.0}; 
    struct Produto armazenamento2 = {"SSD Crucial 1TB", 470.0}; 
    struct Produto armazenamento3 = {"SSD Samsung 2TB NVMe", 1250.0}; 

    struct Produto memoria1 = {"XPG 3200Mhz 8GB", 140.0};
    struct Produto memoria2 = {"Corsair Vengeance 3200Mhz 16GB", 360.0};
    struct Produto memoria3 = {"G.SKILL Trident 6000Mhz 32GB", 1250.0};

    struct Produto fonte1 = {"Corsair CV450 450W", 240.0};
    struct Produto fonte2 = {"Cooler Master 650W", 350.0};
    struct Produto fonte3 = {"XPG Core Reactor 600W", 650.0};

    struct ItemCarrinho carrinho[MAX_CARRINHO];

    while (1) {
        optionProcessor = 0;
        optionVideoCard = 0;
        option = 0;

        system("clear || cls");

        printf ("\n ******************************************");
        printf ("\n **          LOJA DE INFORMATICA         **\n");
        printf (" ******************************************\n");
        if (strlen(warning) > 0){
            printf("\n %s\n\n", warning);
            warning[0] = '\0';
        } else {
            printf("\n");
        }
        printf(" 1 - Processadores\n");
        printf(" 2 - Placas de Video\n");
        printf(" 3 - Placas Mae\n");
        printf(" 4 - Armazenamento\n");
        printf(" 5 - Memoria\n");
        printf(" 6 - Fontes de Alimentacao\n");
        printf(" \n");
        printf(" 7 - Ver Carrinho\n");
        printf(" \n");
        printf(" 8 - Sair\n");
        printf(" \n");
        printf(" Insira uma opcao: ");
        // Entrada segura de opção de categoria
        option = lerInteiroSeguro();

        system("clear || cls");

        if (option == 8){
            loading("Encerrando");
            printf("Ate mais!\n\n");
            break;
        } else {
            switch(option){

                case 1:
                    while (optionProcessor != 4){
                        system("clear || cls");

                        printf ("\n ******************************************");
                        printf ("\n **             PROCESSADORES            **\n");
                        printf (" ******************************************\n");
                        if (strlen(warning) > 0){
                            printf("\n %s\n\n", warning);
                            warning[0] = '\0';
                        } else {
                            printf("\n");
                        }
                        printf(" 1 - %-20s | R$ %.2f \n", processador1.nome, processador1.preco);
                        printf(" 2 - %-20s | R$ %.2f \n", processador2.nome, processador2.preco);
                        printf(" 3 - %-20s | R$ %.2f \n", processador3.nome, processador3.preco);
                        printf("\n");
                        printf(" 4 - Voltar \n");
                        printf("\n");
                        printf(" Insira uma opcao: ");
                        // Entrada segura de opção de processador
                        optionProcessor = lerInteiroSeguro();
                        
                        if (optionProcessor == 4){
                            break;
                        } else if (optionProcessor < 1 || optionProcessor > 4) {
                            strcpy(warning, "Escolha uma opcao valida!");
                        } else {
                            while (qntd <= 0){
                                printf(" Insira a quantidade: ");
                                qntd = lerInteiroSeguro();
                            }

                            printf("\n");
                            system("clear || cls");

                            switch (optionProcessor) {
                                case 1:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = processador1;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Ryzen 5 3600 adicionado ao carrinho!");  
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                case 2:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = processador2;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Ryzen 7 5700X adicionado ao carrinho!");  
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                case 3:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = processador3;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Intel Core i9 13400 adicionado ao carrinho!");  
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                default:
                                    break;
                                
                            }
                            qntd = 0;
                        }
                        
                        
                    }
                    break;  

                case 2:
                    while (optionVideoCard != 4){
                        system("clear || cls");

                        printf ("\n ******************************************");
                        printf ("\n **            PLACAS DE VIDEO           **\n");
                        printf (" ******************************************\n");
                        if (strlen(warning) > 0){
                            printf("\n %s\n\n", warning);
                            warning[0] = '\0';
                        } else {
                            printf("\n");
                        }
                        printf(" 1 - %-24s | R$ %.2f \n", placaVideo1.nome, placaVideo1.preco);
                        printf(" 2 - %-24s | R$ %.2f \n", placaVideo2.nome, placaVideo2.preco);
                        printf(" 3 - %-24s | R$ %.2f \n", placaVideo3.nome, placaVideo3.preco);
                        printf("\n");
                        printf(" 4 - Voltar \n");
                        printf("\n");
                        printf(" Insira uma opcao: ");
                        // Entrada segura de opção de placa de vídeo
                        optionVideoCard = lerInteiroSeguro();
                        
                        if (optionVideoCard == 4){
                            break;
                        } else if (optionVideoCard < 1 || optionVideoCard > 4) {
                            strcpy(warning, "Escolha uma opcao valida!");
                        } else {
                            while (qntd <= 0){
                                printf(" Insira a quantidade: ");
                                qntd = lerInteiroSeguro();
                            }

                            printf("\n");
                            system("clear || cls");

                            switch (optionVideoCard) {
                                case 1:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = placaVideo1;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Geforce GTX 1660 Super adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    
                                    break;

                                case 2:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = placaVideo2;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "RX 580 adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                case 3:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = placaVideo3;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Geforce RTX 4080 TI adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                default:
                                    break;
                                
                            }
                            qntd = 0;
                        }
                        
                        
                    }
                    break;

                case 3:
                    while (optionMotherBoard != 4){
                        system("clear || cls");

                        printf ("\n ******************************************");
                        printf ("\n **               PLACAS MÃE             **\n");
                        printf (" ******************************************\n");
                        if (strlen(warning) > 0){
                            printf("\n %s\n\n", warning);
                            warning[0] = '\0';
                        } else {
                            printf("\n");
                        }
                        printf(" 1 - %-36s | R$ %.2f \n", motherBoard1.nome, motherBoard1.preco);
                        printf(" 2 - %-36s | R$ %.2f \n", motherBoard2.nome, motherBoard2.preco);
                        printf(" 3 - %-36s | R$ %.2f \n", motherBoard3.nome, motherBoard3.preco);
                        printf("\n");
                        printf(" 4 - Voltar \n");
                        printf("\n");
                        printf(" Insira uma opcao: ");
                        // Entrada segura de opção de placa mãe
                        optionMotherBoard = lerInteiroSeguro();
                        
                        if (optionMotherBoard == 4){
                            break;
                        } else if (optionMotherBoard < 1 || optionMotherBoard > 4) {
                            strcpy(warning, "Escolha uma opcao valida!");
                        } else {
                            while (qntd <= 0){
                                printf(" Insira a quantidade: ");
                                qntd = lerInteiroSeguro();
                            }

                            printf("\n");
                            system("clear || cls");

                            switch (optionMotherBoard) {
                                case 1:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = motherBoard1;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Gigabyte B550M Aorus Elite AM4 adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    
                                    break;

                                case 2:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = motherBoard2;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Biostar A320MH AM4 adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                case 3:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = motherBoard3;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Gigabyte B760M Aorus Elite LGA 1700 adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                default:
                                    break;
                                
                            }
                            qntd = 0;
                        }
                        
                        
                    }
                    break;

                case 4:
                    while (optionDisk != 4){
                        system("clear || cls");

                        printf ("\n ******************************************");
                        printf ("\n **             ARMAZENAMENTO            **\n");
                        printf (" ******************************************\n");
                        if (strlen(warning) > 0){
                            printf("\n %s\n\n", warning);
                            warning[0] = '\0';
                        } else {
                            printf("\n");
                        }
                        printf(" 1 - %-20s | R$ %.2f \n", armazenamento1.nome, armazenamento1.preco);
                        printf(" 2 - %-20s | R$ %.2f \n", armazenamento2.nome, armazenamento2.preco);
                        printf(" 3 - %-20s | R$ %.2f \n", armazenamento3.nome, armazenamento3.preco);
                        printf("\n");
                        printf(" 4 - Voltar \n");
                        printf("\n");
                        printf(" Insira uma opcao: ");
                        // Entrada segura de opção de armazenamento
                        optionDisk = lerInteiroSeguro();
                        
                        if (optionDisk == 4){
                            break;
                        } else if (optionDisk < 1 || optionDisk > 4) {
                            strcpy(warning, "Escolha uma opcao valida!");
                        } else {
                            while (qntd <= 0){
                                printf(" Insira a quantidade: ");
                                qntd = lerInteiroSeguro();
                            }

                            printf("\n");
                            system("clear || cls");

                            switch (optionDisk) {
                                case 1:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = armazenamento1;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "SSD Kingston 240GB adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    
                                    break;

                                case 2:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = armazenamento2;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "SSD Crucial 1TB adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                case 3:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = armazenamento3;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "SSD Samsung 2TB adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                default:
                                    break;
                                
                            }
                            qntd = 0;
                        }
                        
                        
                    }
                    break;

                case 5:
                    while (optionMemory != 4){
                        system("clear || cls");

                        printf ("\n ******************************************");
                        printf ("\n **                 MEMORIA              **\n");
                        printf (" ******************************************\n");
                        if (strlen(warning) > 0){
                            printf("\n %s\n\n", warning);
                            warning[0] = '\0';
                        } else {
                            printf("\n");
                        }
                        printf(" 1 - %-32s | R$ %.2f \n", memoria1.nome, memoria1.preco);
                        printf(" 2 - %-32s | R$ %.2f \n", memoria2.nome, memoria2.preco);
                        printf(" 3 - %-32s | R$ %.2f \n", memoria3.nome, memoria3.preco);
                        printf("\n");
                        printf(" 4 - Voltar \n");
                        printf("\n");
                        printf(" Insira uma opcao: ");
                        // Entrada segura de opção de memória
                        optionMemory = lerInteiroSeguro();
                        
                        if (optionMemory == 4){
                            break;
                        } else if (optionMemory < 1 || optionMemory > 4) {
                            strcpy(warning, "Escolha uma opcao valida!");
                        } else {
                            while (qntd <= 0){
                                printf(" Insira a quantidade: ");
                                qntd = lerInteiroSeguro();
                            }

                            printf("\n");
                            system("clear || cls");

                            switch (optionMemory) {
                                case 1:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = memoria1;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "XPG 3200Mhz 1x8GB adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    
                                    break;

                                case 2:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = memoria2;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Corsair Vengeance 3200Mhz 16GB adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                case 3:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = memoria3;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "G.SKILL Trident 6000Mhz 32GB adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                default:
                                    break;
                                
                            }
                            qntd = 0;
                        }
                        
                        
                    }
                    break;

                case 6:
                    while (optionFont != 4){
                        system("clear || cls");

                        printf ("\n ******************************************");
                        printf ("\n **         FONTE DE ALIMENTACAO         **\n");
                        printf (" ******************************************\n");
                        if (strlen(warning) > 0){
                            printf("\n %s\n\n", warning);
                            warning[0] = '\0';
                        } else {
                            printf("\n");
                        }
                        printf(" 1 - %-22s | R$ %.2f \n", fonte1.nome, fonte1.preco);
                        printf(" 2 - %-22s | R$ %.2f \n", fonte2.nome, fonte2.preco);
                        printf(" 3 - %-22s | R$ %.2f \n", fonte3.nome, fonte3.preco);
                        printf("\n");
                        printf(" 4 - Voltar \n");
                        printf("\n");
                        printf(" Insira uma opcao: ");
                        // Entrada segura de opção de fonte de alimentação
                        optionFont = lerInteiroSeguro();
                        
                        if (optionFont == 4){
                            break;
                        } else if (optionFont < 1 || optionFont > 4) {
                            strcpy(warning, "Escolha uma opcao valida!");
                        } else {
                            while (qntd <= 0){
                                printf(" Insira a quantidade: ");
                                qntd = lerInteiroSeguro();
                            }

                            printf("\n");
                            system("clear || cls");

                            switch (optionFont) {
                                case 1:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = fonte1;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Corsair CV450 450W adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    
                                    break;

                                case 2:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = fonte2;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "Cooler Master 650W adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                case 3:
                                    if (nItem < MAX_CARRINHO){
                                        carrinho[nItem].produto = fonte3;
                                        carrinho[nItem].quantidadeItens = qntd;
                                        nItem++;
                                        strcpy(warning, "XPG Core Reactor 600W adicionado ao carrinho!");
                                    } else {
                                        strcpy(warning, "Carrinho cheio!"); 
                                    }
                                    break;

                                default:
                                    break;
                                
                            }
                            qntd = 0;
                        }
                        
                        
                    }
                    break;

                case 7:
                    system("clear || cls");
                    
                    printf ("\n ******************************************");
                    printf ("\n **              CARRINHO                **\n");
                    printf (" ******************************************\n");
                    printf("\n");

                    if (nItem != 0){
                        double total = 0;
                        for (int i = 0; i < nItem; i++){
                            double subtotal = (carrinho[i].quantidadeItens * carrinho[i].produto.preco);
                            printf(" Produto: %-36s | Preco: R$ %-8.2f | Qntd: %-3i | Subtotal: R$ %-8.2f \n", carrinho[i].produto.nome, carrinho[i].produto.preco, carrinho[i].quantidadeItens, subtotal);
                            total += subtotal;
                        }

                        printf("\n Total: R$ %.2f\n", total);

                    } else {
                        printf(" Nao ha itens no carrinho! \n");

                        printf("\n ------------------------------------ \n");

                        printf("\n ENTER - Voltar ao Menu \n");
                        printf("\n Digite ENTER: ");
                        voltar = lerInteiroSeguro();
                        voltar = 0;
                        break;

                    }

                    printf("\n ------------------------------------ \n");

                    printf("\n OUTRA TECLA - Fechar Pedido \n");
                    printf("\n ENTER - Voltar ao Menu \n");
                    printf("\n Insira uma OPCAO: ");
                    voltar = lerInteiroSeguro();
                    
                    if (voltar == 0){
                        break;
                    } else {    
                        // INSERIR INFORMAÇÕES DO USUÁRIO:

                        exibirInformacao();

                        // Iniciar a string vazia
                        name[0] = '\0';

                        // Inserir e Validar NOME DO CLIENTE
                        while (strlen(name) == 0){
                            printf("\n Insira seu NOME: ");
                            fgets(name, sizeof(name), stdin);
                            name[strcspn(name, "\n")] = '\0';
                        }

                        exibirInformacao();
                        
                        // Inserir e Validar UF
                        lerUF(UF, sizeof(UF));

                        exibirInformacao();

                        // Iniciar a string vazia
                        city[0] = '\0';

                        // Inserir e Validar CIDADE
                        while (strlen(city) == 0){
                            printf("\n Insira a CIDADE: ");
                            fgets(city, sizeof(city), stdin);
                            city[strcspn(city, "\n")] = '\0';
                        }

                        exibirInformacao();

                        // Iniciar a string vazia   
                        street[0] = '\0';

                        // Inserir e Validar RUA
                        while (strlen(street) == 0){
                            printf("\n Insira a RUA: ");
                            fgets(street, sizeof(street), stdin);
                            street[strcspn(street, "\n")] = '\0';
                        }

                        exibirInformacao();

                        // Inserir e Validar NUMERO DA RESIDENCIA
                        while (number <= 0) {
                            printf("\n Insira o NUMERO: ");
                            number = lerInteiroSeguro(); // Retorna a parte inteira do numero caso possua caracteres
                        }
                        
                        exibirInformacao();

                        printf("\n");
                        printf(" 1 - PIX (10%% de Desconto) \n");
                        printf(" 2 - DEBITO (5%% de Desconto) \n");
                        printf(" 3 - CREDITO (Ate 12 Vezes; Sem Desconto) \n");

                        while (optionPayment != 1 && optionPayment != 2 && optionPayment != 3){
                            printf("\n Insira a FORMA DE PAGAMENTO: ");
                            optionPayment = lerInteiroSeguro();
                        }

                        switch(optionPayment){

                            case 1: 
                                // PIX
                                percentageOff = 10;
                                strcpy(methodPayment, "PIX");
                                break;

                            case 2:
                                // DÉBITO
                                percentageOff = 5;
                                strcpy(methodPayment, "DEBITO");
                                break;

                            case 3:
                                // CRÉDITO
                                strcpy(methodPayment, "CREDITO");
                                percentageOff = 0;

                                while (timesPayment <= 0 || timesPayment > 12){
                                    printf("\n Insira a QUANTIDADE DE VEZES (ate 12X): ");
                                    timesPayment = lerInteiroSeguro();
                                }
                                break;
                        }

                        system("clear || cls");

                        printf ("\n ******************************************");
                        printf ("\n **             PEDIDO FECHADO           **\n");
                        printf (" ******************************************\n");
                        printf("\n");
                        
                        double total = 0;
                        for (int i = 0; i < nItem; i++){
                            char produto[64];
                            strcpy(produto, carrinho[i].produto.nome);
                            int qntdItens = carrinho[i].quantidadeItens;
                            double preco = carrinho[i].produto.preco;
                            double subtotal = carrinho[i].quantidadeItens * carrinho[i].produto.preco;
                            
                            printf(" Produto: %-36s | Preco: R$ %-8.2f | Qntd: %-3i | Subtotal: R$ %-8.2f \n", produto, preco, qntdItens, subtotal);

                            total += subtotal;
                        }

                        printf("\n Subtotal: R$ %.2f", total);
                        printf("\n");
                        printf ("\n ******************************************");
                        printf ("\n **                CLIENTE               **\n");
                        printf (" ******************************************\n");

                        // Cliente
                        printf("\n Cliente: %s", name);
                        printf("\n Cidade: %s - %s", city, UF);
                        printf("\n Endereco: %s, %i", street, number);
                        printf("\n");
                        
                        // Pagamento
                        printf ("\n ******************************************");
                        printf ("\n **               PAGAMENTO              **\n");
                        printf (" ******************************************\n");
                        
                        printf("\n Forma de Pagamento: %s", methodPayment);
                        
                        if (strcmp(methodPayment, "CREDITO") == 0){
                            printf("\n Quantidade de Parcelas: %ix", timesPayment);
                        } else {
                            printf("\n DESCONTO: %.1f%%", percentageOff);
                        }

                        printf("\n");

                        // Frete
                        printf ("\n ******************************************");
                        printf ("\n **                FRETE                 **\n");
                        printf (" ******************************************\n");

                        if (strcmp(UF, "SC") == 0 || strcmp(UF, "PR") == 0 || strcmp(UF, "RS") == 0){
                            printf("\n FRETE: GRATIS");
                        } else {
                            printf("\n FRETE: 5%%");
                        }

                        printf("\n");

                        // Valor Total
                        printf ("\n ******************************************");
                        printf ("\n **             VALOR TOTAL              **\n");
                        printf (" ******************************************\n");

                        printf("\n Total dos Itens: R$ %.2f", total);
                        double valueOff = 0;
                        if (strcmp(methodPayment, "CREDITO") == 0){
                            valueOff = 0;
                            printf("\n Quantidade de Parcelas: %ix", timesPayment);
                        } else {
                            valueOff = (percentageOff/100) * total;
                            printf("\n Desconto a Vista: R$ %.2f", valueOff);
                        }
                        
                        printf("\n");

                        double valueFreight = 0;
                        if (strcmp(UF, "SC") == 0 || strcmp(UF, "PR") == 0 || strcmp(UF, "RS") == 0){
                            valueFreight = 0.0;
                            printf("\n Frete: GRATIS");
                        } else {
                            valueFreight = (5.0/100) * total;
                            printf("\n Frete: R$ %.2f", ((5.0/100) * total));
                        }
                        printf("\n");
                        printf("\n TOTAL DO PEDIDO: R$ %.2f", (total - valueOff + valueFreight));

                        if (strcmp(methodPayment, "CREDITO") == 0){
                            printf("\n PAGAMENTO: %ix de R$ %.2f", timesPayment, ((total - valueOff + valueFreight)/timesPayment));
                        }

                        printf("\n");
                        printf("\n ------------------------------------------\n\n");
                        return 0;
                    }
                
                default:
                    strcpy(warning, "Escolha uma opcao valida!");
                    break;

            }
        }

        printf("\n");


    }
    

}