#include <locale.h> //biblioteca de alocação de texto por região
#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <string.h> //biblioteca de manipulação de strings

int registrar(){

   setlocale(LC_ALL, "Portuguese");
  
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
  
   printf("Digite o CPF a ser registrado: \n");
   scanf("%s", cpf);

   strcpy(arquivo, cpf);              //copia o conteúdo de cpf para arquivo

   FILE *file;
   file = fopen(arquivo, "w");       //cria o arquivo
   fprintf(file, cpf);              //salva o valor da variável
   fclose(file);                   //fecha o arquivo

   file = fopen(arquivo, "a");    //abre o arquivo para atualizar
   fprintf(file, ",");
   fclose(file);

   printf("Digite o nome a ser registrado: ");
   scanf("%s", nome);

   file = fopen(arquivo, "a");  //abre o arquivo para editar
   fprintf(file, nome);         //salva os valores de "nome" no arquivo
   fclose(file);                //fecha a edição do arquivo

   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);

   printf("Digite o sobrenome a ser registrado: ");
   scanf("%s", sobrenome);
  
   file = fopen(arquivo, "a");
   fprintf(file, sobrenome);
   fclose(file);

   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);

   printf("Digite o cargo a ser registrado: ");
   scanf("%s", cargo);

   file = fopen(arquivo, "a");
   fprintf(file, cargo);
   fclose(file);

  
}

int consultar(){

   setlocale(LC_ALL, "Portuguese");
  
   char cpf[40];
   char conteudo[100];

   printf("Digite o CPF a ser consultado: ");
   scanf("%s", cpf);

   FILE *file;
   file = fopen(cpf, "r");

   if(file == NULL){
      printf("CPF não encontrado, por favor digite um CPF válido.\n");
   }

  while(fgets(conteudo, 200, file) != NULL){         //enquanto houver conteudo dentro de file, será                                                           armazenado na variável conteudo
    printf("Essas são as informações do usuário: \n");
    printf("%s", conteudo);
    printf("\n");
  }
   //system("pause");
}

int deletar(){
   char cpf[40];

   printf("Digite o CPF do usuário a ser deletado: ");
   scanf("%s",cpf);

   remove(cpf);

   FILE *file;
   file = fopen(cpf,"r");

   if(file == NULL){
      printf("CPF não encontrado, por favor digite um CPF válido. \n");
      system("pause");
   }
}

int main() {

  int escolha = 0;
  int laco = 1;

  for(laco = 1; laco == 1;)
  {
    system("clear");
  
  setlocale(LC_ALL, "Portuguese");

  printf("+++ Cadastro de Alunos EBAC +++ \n\n");
  printf("Digite a operação desejada:\n\n");
  printf("\t1 - Registrar Aluno\n");
  printf("\t2 - Consultar Aluno\n");
  printf("\t3 - Deletar registro de aluno\n\n");
  printf("\t4 - Sair\n\n");
  // printf("\tEsse software é de uso livre.");

  printf("Qual o número da operação desejada? ");
  scanf("%d", &escolha);

  switch (escolha) 
{
      
     case 1:
     escolha = 1;
     registrar();
     break;

     case 2:
     escolha = 2;
     consultar();
     break;

     case 3:
     escolha = 3;
     deletar();
     break;

     case 4:
     printf("Obrigado por utilizar o sistema.");
     return 0;
     break;

     default:
     printf("Operação inválida! Digite um número de operação válida (1, 2 ou 3).\n");
}
}
}