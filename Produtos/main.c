#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <strings.h>

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
/*
bool cadastrarEstoque(Estoque estoque){
	int i;
	for(i=0; i<100; i++){
		
		if()
			
	}
	
}
*/





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


void CadastrarProdutosMenu(){
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
	printf("6. Sair\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Informe uma das opcoes de menu: ");
	
}


void consutar(){

int i;	
	clearScreen();
	
	for(i=0; i<=100; i++)
	{
		if(produtos[i].preco!=00)
		{
			printf("cod barras = %s nome = %s preco=%.2lf\n",produtos[i].cod_barras,produtos[i].nome,produtos[i].preco);
		}
	}
	
	getch();
}



void CadastroProdutos(){
	int opcao;
	bool podeSair = false;
	while(!podeSair){
		CadastrarProdutosMenu();
		
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
	
	
	CadastroProdutos();
	
	return 0;
}

/*
int main(){

	setlocale(LC_ALL,"Portuguese");
	
	int a;
	
	
	printf("\aEscolha uma das opções a seguir!!");
	printf("\n 1 ---> Cadastrar um produto");
	printf("\n 2 ---> Consuntar a lista de produtos já cadastrados");
	printf("\n 3 ---> Fechar o programa\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:{
			
			CadastroProdutos();
			
			break;
		}
	
		case 2:{
			
			
			
			
			break;
		}
	
		case 3:{
			
			
			
			break;
		}
		
	}
	
	
	return 0;
}
*/
