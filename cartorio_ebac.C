#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o respos�vel por cadastrar os usu�rios no sistemas
{
	//inicio cria��o de v�riaveis/string
	// Char serve para armazenar UM caracter ao fazermos alocamos 1 byte de mem�ria para armazenar o cracter
	//a sintaxe dele �: char nomedavariavel
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de v�riaveis/string
	
	printf("Digite o cpf a ser cadastrado:"); //coletando informa��o de usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string.
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); // salva o valor da variavel.
	fclose(file); // fecha o arquivo.
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);//salva o valor da variavel.
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s" ,cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//char cpf{40};
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,  "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
	//printf("Voc� escolheu consultar os nomes!\n");
///////	system("pause");	


int deletar()
{
	char cpf[40];
	
	printf("digitar o cpf a ser deletado;");
	scanf("%s",cpf);
	
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
		}	
}



int main()
{ 
	int opcao=0; // Definindo as v�riaveis
	int laco=1;
	
	for(laco=1;laco=1;) 
	
	{
		system("cls");
	
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha da op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar Nomes \n");
		printf("\t3 - Deletar Nomes \n\n"); 
		printf("\t4 - Sair do sistema \n\n");
		printf("op��o:"); //fim do menu
	
		scanf("%d", &opcao); //armazenamento a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
				registro(); //chamada de fun��es
				system("pause");
			break;
			
			case 2:
				consulta(); //chamada de fun��es
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			
			
			default:
				printf("Essa op�cao n�o est� dispon�vel!\n");
				system ("pause");	
			break;
		}	//fim da sele��o
	}
}


			
	
	
		
		
	
