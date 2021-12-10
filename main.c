#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
#define SIZE 49
#define DAY 30
#define MONTH 11

typedef struct{
    int cod, year;
    char name[50], position[50];
    float hourValue;
    int flag;
    int workedHours[DAY][MONTH];
} Employees;

Employees jobers[SIZE];

void menu();
void registerUser();
void insertHour();
void calcPayment();
void userList();
void editUser();
void removeUser();


int main()
{
    setlocale(LC_ALL, "portuguese");
    int op=0;
    menu();
    return 0;
}

void menu(){
    int op;
    do{
        system("cls");
        printf("-------------------------------------\n\n");
        printf("---------- Fict�cia Ltda ------------\n\n");
        printf("-------------------------------------\n\n");
        printf("Selecione uma op��o:\n\n");
        printf("1-CADASTRAR\n");
        printf("2-INSERIR HORAS TRABALHADAS\n");
        printf("3-CALCULAR SAL�RIO\n");
        printf("4-LISTAR FUNCION�RIOS CADASTRADOS\n");
        printf("5-ALTERAR DADOS DO FUNCION�RIO\n");
        printf("6-EXCLUIR\n");
        printf("0-SAIR\n");
        scanf("%d", &op);

        switch(op){
        case 0:
        break;
        case 1: registerUser();
        break;
        case 2: insertHour();
        break;
        case 3: calcPayment();
        break;
        case 4: userList();
        break;
        case 5: editUser();
        break;
        case 6: removeUser();
        break;
        default: printf("Op��o inv�lida!");
        }
    }while(op!=0);

}

void registerUser(){
    int year;
    char name[50], position[50];
    float hourValue;
    int op;
    do{
        system("cls");
        printf("Informe os dados: \n\n");

        getchar();
        printf("Nome: ");
        fgets(name, sizeof(name), stdin);

        printf("Ano: ");
        scanf("%d", &year);

        getchar();
        printf("Cargo: ");
        fgets(position, sizeof(position), stdin);

        printf("Valor hora: ");
        scanf("%f", &hourValue);

        for(int i = 0; i < SIZE; ++i){
            if(jobers[i].flag==0){
                jobers[i].cod=i+1;
                strcpy(jobers[i].name, name);
                jobers[i].year=year;
                strcpy(jobers[i].position, position);
                jobers[i].hourValue=hourValue;
                jobers[i].flag=1;
                break;
            }
        }

        printf("1 - CONTINUAR CADASTRANDO\n");
        printf("0 - SAIR \n");
        scanf("%d", &op);
    }while(op!=0);

}

void insertHour(){
    int i, j;
    int id, op;
    int workedHours[DAY][MONTH];
    userList();
    printf("Digite o c�digo do funcion�rio para adicionar horas: ");
    scanf("%d", &id);
    --id;
    do{
        system("cls");
        printf("Informe o dia e m�s referente as horas: \n\n");
        scanf("%d %d", &i, &j);
        if(i<=31 && j<=12){
            printf("Informe a quantidade de horas do dia %d m�s %d: ", i, j);
            scanf("%d", &workedHours[i][j]);

            jobers[id].workedHours[i][j]=workedHours[i][j];
            jobers[id].cod=id+1;

            printf("%d horas trabalhadas em %d/%d\n", jobers[id].workedHours[i][j], i, j);
        }else{
            printf("VALOR INV�LIDO!!!\n");
        }


        printf("1 - CONTINUAR ADICIONANDO HORAS\n");
        printf("0 - SAIR \n");
        scanf("%d", &op);
    }while(op!=0);

}

void calcPayment(){
    int id, op, y;
    do{
        system("cls");
        userList();
        printf("Digite o c�digo do funcion�rio para Calcular pagamento: \t");
        scanf("%d", &id);
        printf("Informe o m�s referente ao calculo: \t");
        scanf("%d", &y);
        if(y<12 && y>0){
            --id;
        int totalHour=0;
        float payment;
        for(int x=0; x<DAY; ++x){
            totalHour = jobers[id].workedHours[x][y] + totalHour;
        }
        payment = totalHour * jobers[id].hourValue;
        printf("Sal�rio m�s %d R$%.2f\n", y, payment);
        }else{
            printf("Valor inv�lido\n");
        }

        printf("1 - CONTINUAR CALCULANDO\n");
        printf("0 - SAIR \n");
        scanf("%d", &op);
    }while(op!=0);


}

void userList(){
    system("cls");
    printf("LISTA DE FUNCION�RIOS\n");
    for(int i=0; i<SIZE; ++i){
        if(jobers[i].flag==1){
            printf("\nC�digo: %d\n", jobers[i].cod);
            printf("\nNome: %s\n", jobers[i].name);
            printf("\nAno: %d\n", jobers[i].year);
            printf("\nCargo: %s\n", jobers[i].position);
            printf("\nValor Hora: %.2f\n\n", jobers[i].hourValue);
            printf("-----------------------------\n\n");
        }
    }
    system("pause");
}

void editUser(){
    int id;
    userList();
    printf("Digite o c�digo do funcion�rio para Editar: ");
    scanf("%d", &id);
    --id;
    int year;
    char name[50], position[50];
    float hourValue;
    int op;
    do{
        system("cls");
        printf("Informe os dados: \n\n");
        getchar();
        printf("Nome: ");
        fgets(name, sizeof(name), stdin);

        printf("Ano: ");
        scanf("%d", &year);
        getchar();

        printf("Cargo: ");
        fgets(position, sizeof(position), stdin);

        printf("Valor hora: ");
        scanf("%f", &hourValue);

        jobers[id].cod=id+1;
        strcpy(jobers[id].name, name);
        jobers[id].year=year;
        strcpy(jobers[id].position, position);
        jobers[id].hourValue=hourValue;

        printf("1 - CONTINUAR EDITANDO\n");
        printf("0 - SAIR \n");
        scanf("%d", &op);
    }while(op!=0);
}

void removeUser(){
    int id;
    userList();
    printf("Digite o c�digo do funcion�rio para excluir: ");
    scanf("%d", &id);
    --id;
    jobers[id].flag=0;
    printf("Usu�rio exclu�do com sucesso!\n");
}

