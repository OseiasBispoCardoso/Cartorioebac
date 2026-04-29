#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // bibioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h>  // biblioteca responsável por cuidar das strings

int registro() // reposável por cadastrar o usuário no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	// início criação de variáveis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		// final da criação de variáveis/ string
	printf("digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo eo "w" significa escrever
	fprintf(file,cpf); // Salvo o arquivo
	fclose(file); // Fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,  ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
	
	
	
	
	
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file ;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
		system("pause");
}

int deletar()
{
	char cpf[40];
	// final da seleção de variáveis/string
	
	printf(" digite o Cpf do usuário a ser deletado: "); // coletando imformcação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf(" O usuario não se encontra no sistema!.\n");
		system("pause");
	}
	
	
	
	
}

int main()
	{
	
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	for (laco=1; laco=1;)
	{
	
	
		system("cls");
		
		
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	    printf("### cartório da EBC ####\n\n"); // Início do Menu
	    printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 Registrar Nomes\n");
    	printf("\t2 Consultar Nomes\n");
    	printf("\t3 Deletar Nomes\n\n");
    	printf("\t4 Sair do sistema\n\n");
		printf("Opção:"); // Fim do menu
		
	
		scanf("%d" , &opcao); // Armazenando a escolha do usuário
	
		system("cls"); // respocável por limpar a tela
		
		switch(opcao) // Início da Seleção do menu
		{
			case 1:
			registro(); // chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
		    break;
		    
		    case 4:
		    printf(" Obrigado por ultilizar o sistema! \n");
		    return 0;
		    break;
		    
		    default:
		    printf("Essa opção não está disponível!\n");
			system("pause");
			break; 
		} // fim da seleção
		    
	}
}

