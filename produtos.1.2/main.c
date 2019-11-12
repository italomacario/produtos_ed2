#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef int bool;
enum { false, true };

void limparBuffer(){
  scanf("%*[^\n]"); 	
  scanf("%*c");
}

void clearScreen(){
  system("@cls||clear");
}

typedef struct Estoque{
	
	char cod_barras[100];
	char nome[100];
	int quantidade;

}Estoque;

typedef struct Fornecedor{
	
	char nome[100];
	float preco;
//	int numero_fornecedor;
	float cep[100];
	
}Fornecedor;

typedef struct Produto{
	
//	int id;
	char cod_barras[100];
	char nome[100];
//	char numero_fornecedor;
//	int promocao;
	double preco;
//	int marca;
//	char categoria[100];
	
	
}Produto;

Estoque estoques[100];
Fornecedor fornecedores[100];
Produto produtos[100];







bool cadastrarPodutos(Produto produto){
	int i;
	for(i=0; i<100; i++){
		
		if(produtos[i].preco==0){
			strcpy(produtos[i].cod_barras,produto.cod_barras);
			strcpy(produtos[i].nome,produto.nome);
			produtos[i].preco=produto.preco;
			return true;
		}		
	}
	return false;
}

void MenuCadastroDeProdutos(){
	Produto produto;
	clearScreen();
	
	printf("Informe o codigo de barra do produto ");
	scanf("%100[^\n]",&produto.cod_barras);
	limparBuffer();
	printf("Informe o nome do produto ");
	scanf("%100[^\n]",&produto.nome);
	limparBuffer();
	printf("Informe o preco do produto ");
	scanf("%lf",&produto.preco);
	limparBuffer();
	
	if(cadastrarPodutos(produto)){
		printf("\n\nproduto cadastrado com sucesso!!");
	}else{
		printf("\n\nSem espaco em disco!!");
	}
	getch();
	
}



void bubble_Sort(){
	int n=100;
	int ordenado=0, i;
	Produto produto;
	
	while(ordenado==0){
		
		ordenado=1;
		
		for(i=0; i < n-1; i++){
			
			if(produtos[i].preco > produtos[i+1].preco){
				
				produto.preco=produtos[i].preco;
				strcpy(produto.nome,produtos[i].nome);
				strcpy(produto.cod_barras,produtos[i].cod_barras);
				
				produtos[i].preco=produtos[i+1].preco;
				strcpy(produtos[i].nome,produtos[i+1].nome);
				strcpy(produtos[i].cod_barras,produtos[i+1].cod_barras);
				
				produtos[i+1].preco=produto.preco;
				strcpy(produtos[i+1].nome,produto.nome);
				strcpy(produtos[i+1].cod_barras,produto.cod_barras);
				
				ordenado=0;
			}
		}
		n--;
	}
	consutar();
}




void consutar(){

	int i;	
	clearScreen();
	
	for(i=0; i<=100; i++)
	{
		if(produtos[i].preco!=00)
		{
			printf("cod barras = %s \nnome = %s \npreco=%.2lf\n\n",produtos[i].cod_barras,produtos[i].nome,produtos[i].preco);
		}
	}
	
	getch();
}






void Menu(){
	int opcao;
	bool podeSair = false;
	while(!podeSair){
		
		
		clearScreen();
		printf("=========================\n");
		printf("CADASTRO DE PRODUTOS\n");
		printf("=========================\n");
		printf("\n");
		printf("1. Cadastrar\n");
		printf("2. Consultar\n");
		printf("3. Excluir\n");
		printf("4. Alterar\n");
		printf("5. Listar\n");
		printf("6. Ordenar\n");
		printf("7. Sair\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("Informe uma das opcoes de menu: ");
		
		scanf("%d",&opcao);
		limparBuffer();
		
		switch (opcao){
		   case 1:
		    	MenuCadastroDeProdutos();
		   break;
		   case 2:
				consutar();
		   break;
		   case 3:
		     //Excluir
		   break;
		   case 4:
		     //Alterar
		   break;
		   case 5:
		     //Listar
		   break;
		   
		   case 6:
		    	bubble_Sort();
		   break;
		   
		   case 7:
				podeSair = true;
		   break;
		   
		   
		   
		   
		   default:
		     printf("\nOpcao invalida!!");
		     getch();
		}		
	}
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	
	Menu();
	
	return 0;
}
/*



void insertion_Sort(int *vet, int t)
{
	int i, y, aux;
	
	for(i=1; i<t; i++){
		
		aux=vet[i];
		for(y=i-1; y>=0 && vet[y]>aux; y--){
			vet[y+1]=vet[y];	
		}
		vet[y+1]=aux;
	}	
}




void selection_Sort(int *vet, int t){
	
	int i, y, min, aux;
	
	for(i=0; i < t-1; i++){
		min=i;
		for(y=i+1; y<t; y++){
			if(vet[y]<vet[min]){
				min=y;
			}
		}
		aux=vet[i];
		vet[i]=vet[min];
		vet[min]=aux;
	}	
}

*/
