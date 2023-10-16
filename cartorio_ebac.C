#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função resposável por cadastrar os usuários no sistemas
{
	//inicio criação de váriaveis/string
	// Char serve para armazenar UM caracter ao fazermos alocamos 1 byte de memória para armazenar o cracter
	//a sintaxe dele é: char nomedavariavel
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de váriaveis/string
	
	printf("Digite o cpf a ser cadastrado:"); //coletando informação de usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string.
	
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
	//printf("Você escolheu consultar os nomes!\n");
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
		printf("o usuário não se encontra no sistema!.\n");
		system("pause");
		
		}	
}



int main()
{ 
	int opcao=0; // Definindo as váriaveis
	int laco=1;
	
	for(laco=1;laco=1;) 
	
	{
		system("cls");
	
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha da opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar Nomes \n");
		printf("\t3 - Deletar Nomes \n\n"); 
		printf("\t4 - Sair do siatema \n\n");

		printf("opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenamento a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
				registro(); //chamada de funções
				system("pause");
			break;
			
			case 2:
				consulta(); //chamada de funções
			break;
			
			case 3:
				deletar();
			break;

			case 4:
			printf("obrigado por utilizar o sistema"");
			break;
			
			default:
				printf("Essa opçcao não está disponível!\n");
				system ("pause");	
			break;
		}	//fim da seleção
	}
}


			
	
	
		
		
	
