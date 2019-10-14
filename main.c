#include <stdio.h>
#include <stdlib.h>
 
void menu (unsigned char *opcao){
    printf ("*.* Escolha uma opcao: *.*\n");
    printf ("\n1. Validar um CPF");
    printf ("\n2. Gerar digitos verificadores");
    printf ("\n3. Sair");
    printf ("\nOpcao desejada: ");
    scanf  ("%d", opcao);
}
void menu_dois (unsigned char *opcao_dois){
    printf ("\n\n1. Voltar ao menu inicial");
    printf ("\n2. Sair");
    printf ("\nOpcao desejada: ");
    scanf  ("%d", opcao_dois);
}
 
void leitura_dados(long long int *cpf){
    printf ("\nInsira o CPF: ");
    scanf ("%llu", cpf);
}

int digitos_verificadores(long long cpf){
    int verificador, i, sm=0, d1, d2, n;
    long long cpf_aux;
    
    //primeiro digito 
    cpf_aux= cpf;
    for (i=2; i<=10; i++){
        n= cpf_aux%10;
        sm+= n*i;
        cpf_aux/=10;
    }
    if ((11-(sm%11))==10 || (sm%11)==0)
        d1=0;
    else 
        d1=11-(sm%11);
    //segundo digito 
    cpf_aux= cpf;
    sm=0;
    for (i=2; i<=11; i++){
        if (i==2)
            sm+=d1*i;
        
        if(i>2){
          n= cpf_aux%10;
          sm+= n*i;
        cpf_aux/=10;
        }
    }
    if ((11-(sm%11))==10 || (sm%11)==0)
        d2=0;
    else 
        d2=11-(sm%11);
    
    verificador= (d1*10)+d2;
    return verificador;
}

int validacao(long long cpf){
    int resultado;
    long long cpf_aux= cpf/100;
    if(digitos_verificadores(cpf_aux) == (cpf%100))
        resultado=1; 
    
    return resultado; 
}
 
int main() {
    
    unsigned char opcao, opcao_dois;
    long long int cpf;
    
    do{
        system("cls");
        menu(&opcao);
        while(opcao>3 || opcao<1){
            system("cls");
            printf ("Opcao invalida.\nTente novamente:\n\n");
            menu(&opcao);
        }
              
        if (opcao==1){
            system("cls");
            printf ("*.* Validar CPF *.*\n");
            leitura_dados(&cpf);
            if (validacao(cpf)==1)
                printf ("\nO CPF informado eh valido.");
            else
               printf ("\nO CPF informado eh invalido.");
            menu_dois(&opcao_dois);
        }
        
        if (opcao==2){
            system("cls");
            printf ("*.* Gerar digitos verificadores de um CPF *.*\n");
            leitura_dados(&cpf);
            printf ("\n\nDigitos verificadores do CPF informado: %d", (digitos_verificadores(cpf)));
            menu_dois(&opcao_dois);
        }
        
        if (opcao==3 || opcao_dois==2)
            system("cls");
        
    }while(opcao!=3 && opcao_dois!=2); 
    return (EXIT_SUCCESS);
}


