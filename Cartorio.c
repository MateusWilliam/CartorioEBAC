#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função resposável por cadastrar os usuários no sistema
{
	    //inicio da criação de variáveis/string
	    char arquivo[40];
	    char cpf[40];
	    char nome[40];
	    char sobrenome[40];
	    char cargo[40];
	    // final da criação de variáveis/string
	    
	    printf("Digite o CPF a ser cadastrado: "); //Coletando dados dos usuários
	    scanf("%s", cpf); //%s salvando a string
	    
	    strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	    
	    FILE *file; //cria o arquivo
	    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	    fprintf(file,cpf); // salvo o valor da variavel	
	    fclose(file); // fecha o arquivo
	    
	    file = fopen(arquivo, "a"); 	
	    fprintf(file, ","); 
	    fclose(file);
	    
	    printf("Digite o nome a ser cadastrado: ");  //Coletando dados dos usuários
	    scanf("%s",nome); //%s salvando 
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,nome);
	    fclose(file);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file, ",");
	    fclose(file);
	    
	    printf("Digite o sobrenome a ser cadastrado:" );  //Coletando dados dos usuários
	    scanf("%s",sobrenome); //%s salvando
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,sobrenome);
	    fclose(file);
	    
	    file = fopen(arquivo, "a");
	    fprintf(file, ",");
	    fclose(file);
	    
	    printf("Digite o cargo a ser cadastrado:" );  //Coletando dados dos usuários
	    scanf("%s",cargo); //%s salvando
	    
	    file = fopen(arquivo, "a");
	    fprintf(file,cargo);
	    fclose(file);
	
	    system("pause"); 
	    
}

int consultar()
{
	   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	   
	   char cpf[40];
	   char conteudo[200];
	   
	   printf("digite o CPF a ser consultado: ");
	   scanf("%s",cpf);
	   
	   FILE *file;
	   file = fopen(cpf,"r");
	   
	   if(file == NULL)
	   {
	   	    printf("Usuário não registrado!.\n");
	   }
	   
	   while(fgets(conteudo, 200, file) != NULL)
	   {
	   	    printf("\nEssas são as informações do usuário:\n\n");
			printf("%s", conteudo);
			printf("\n\n");	   
	   }
		
		system("pause");
		
}

int deletar()
{
        char cpf[40];
        
        printf("Digite o CPF do usuário a ser deletado: ");
        scanf("%s",cpf);
        
        remove(cpf);
        
        FILE *file;
		file = fopen(cpf,"r"); 
		
		{
			printf("Você tem certeza? \n");
			system("pause");	
		}
		
		if(file == NULL)
		{
			printf("O usuário não se encontra no sistema! .\n");
			system("pause");
		}

}


int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes:\n");
	    printf("\t2 - Consultar nomes:\n");
	    printf("\t3 - Deletar nomes:\n\n");
	    printf("Opção: "); //fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); // responsável por limpar a tela
	    
	    switch(opcao) // inicio da seleção do menu
	    {
	    	case 1:
	        registro(); // chamada de funções
		    break;
		    
		    case 2:
		    consultar(); // chamada de funções
		    break;
		    
		    case 3:
		    deletar(); // chamada de funções
			break;
			
			default:
			printf("Essa opção não está disponivel\n");
	    	system("pause");
	    	break;
					
		} //fim da seleção

	
}
}
