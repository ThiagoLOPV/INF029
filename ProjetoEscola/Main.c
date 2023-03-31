#include<stdio.h>
#include<string.h>
#define TAM_ALUNO 3
#define LISTA_CHEIA -1
#define MATRICULA_INVALIDA -2
#define CAD_SUCESSO -3
#define ALUNO_DELETADO -4
#define TAM_DIS 3

typedef struct disciplina
{
  char nome[50];
  int codigo;
  int semestre;
  int Professor;
  int alunos[TAM_DIS];
}Disciplina;
typedef struct dma
{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct ficha
{
int matricula;
char nome[50];
char sexo;
Data dataNascimento;
int ativo;
char CPF[15];
} Pessoa;

//PSEUDO FUNCOES
int CadastrarAluno();
int Aluno();
void ListarAluno();
int DeletarAluno();

int CadastrarProfessor();
void ListarProfessor();
int DeletarProfessor();

int CadastrarDisciplina();
int InserirAluno();
int ExcluirAluno();

int main()
{
  Disciplina disciplinas[TAM_DIS];
  int qtdDis = 0;
  Pessoa listProf[TAM_ALUNO];
  int qtdProf = 0;
  Pessoa listAluno[TAM_ALUNO];
  int qtdAluno = 0;
  int loop = 1;
  int opcao;

  while(loop)
  {
    printf("lesgo\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("4 - Sair\n");
    scanf("%d", &opcao);
    switch(opcao)
    {
      //ALUNO
      case 1:
      {
        int loopAluno = 1;
        while(loopAluno)
        {
          printf("ALUNOS\n");
          printf("1 - Cadastrar\n");
          printf("2 - Deletar\n");
          printf("3 - Listar\n");
          printf("4 - Sair\n");
          int opcaoAluno;
          scanf("%i", &opcaoAluno);
          switch(opcaoAluno)
          {
            case 1: //CADASTRAR
              {
                int retorno = CadastrarAluno(listAluno[TAM_ALUNO],qtdAluno);
                if(retorno == CAD_SUCESSO){
                  printf("Sucesso!\n");
                  qtdAluno++;
                }
                break;
              }
            case 2: //DELETAR
              {
                int delete = DeletarAluno(listAluno[TAM_ALUNO],qtdAluno);
                break;
              }
            case 3: //LISTAR
              {
                ListarAluno(listAluno[TAM_ALUNO],qtdAluno);
                break;
              }
            case 4: //SAIR
              {
                printf("\n============================\n");
                loopAluno = 0;
                break;
              }
            default: 
            printf("OPCAO INVALIDA!");
          }
        }
        break;
      }
      //PROFESSOR
      case 2:
      {
        int loopProf = 1;
         while(loopProf)
         {
            printf("Professores\n");
            printf("1 - Cadastrar\n");
            printf("2 - Deletar\n");
            printf("3 - Listar\n");
            printf("4 - Sair\n");
            int opcaoProf;
            scanf("%i", &opcaoProf);
            switch(opcaoProf)
            {
              case 1:
              {
                int retorno = CadastrarProfessor(listProf[TAM_ALUNO], qtdProf);
                if(retorno == CAD_SUCESSO)
                {
                  printf("Sucesso!\n");
                  qtdProf++;
                }
                break;
              }
              case 2:
              {
                int delete = DeletarProfessor(listProf[TAM_ALUNO],qtdProf);
                break;
              }
              case 3:
              {
                ListarAluno(listProf[TAM_ALUNO],qtdProf);
                break;
              }
              case 4:
              {
                printf("\n============================\n");
                loopProf = 0;
                break;
              }
              default:
              printf("OPCAO INVALIDA!");
            }
        break;
         }
      }
      //DISCIPLINA
      case 3:
      {
        int loopDis = 1;
        while(loopDis)
        {
          printf("Disciplina\n");
          printf("1 - Inserir Aluno\n");
          printf("2 - Excluir Aluno\n");
          printf("3 - Listar Disciplinas\n");
          printf("4 - Cadastrar Disciplina\n");
          printf("5 - Sair\n");
          int opcaoDis;
          scanf("%i", &opcaoDis);
          switch(opcaoDis)
          {
            case 1: //Inserir Aluno
              {
                int retorno = InserirAluno();
                if(retorno == CAD_SUCESSO)
                {
                  printf("sucesso!");
                }
                break;
              }
            case 2: //Excluir Aluno
              {
                break;
              }
            case 3: //Listar Disciplinas
              {
                break;
              }
            case 4:
              {
                int retorno = CadastrarDisciplina();
                if(retorno == CAD_SUCESSO)
                {
                  printf("Sucesso!");
                  qtdDis++;
                }
                break;
              }
            case 5: //Sair
              {
                printf("\n============================\n");
                loopDis = 0;
                break;
              }
            default: 
            printf("OPCAO INVALIDA!");
          }
        }
        break;
      }
      //SAIR
      case 4:
      {
        printf("\n============================\n");
        loop = 0;
        break;
      }
      default: 
      printf("OPCAO INVALIDA!");
    }
    
  
  }
}

//ALUNO
int CadastrarAluno(Pessoa listaluno[], int qtdaluno)
{
  char nome[50];
  char sexo;
  char disciplina[10];
  Data dataNascimento;
  int ativo;
  char CPF[15];
  printf("n* de matricula: ");
  int matricula;
  scanf("%d", &matricula);
  scanf("%d", &listaluno[qtdaluno].matricula);
    
  printf("Digite o nome: ");
  fgets(listaluno[qtdaluno].nome, 50, stdin); 
    
  size_t ln = strlen(listaluno[qtdaluno].nome) - 1; 
  if (listaluno[qtdaluno].nome[ln] == '\n')
  {
    listaluno[qtdaluno].nome[ln] = '\0';
  }
  printf("Digite o sexo: ");
  scanf("%c", &listaluno[qtdaluno].sexo);
    
  printf("Digite o dia de nascimento: ");
  scanf("%d", &listaluno[qtdaluno].dataNascimento.dia);
  
  printf("Digite o mês de nascimento: ");
  scanf("%d", &listaluno[qtdaluno].dataNascimento.mes);
  
  printf("Digite o ano de nascimento: ");
  scanf("%d", &listaluno[qtdaluno].dataNascimento.ano);
  getchar();
  
  printf("Digite o CPF: ");
  fgets(listaluno[qtdaluno].CPF, 15, stdin); 
  ln = strlen(listaluno[qtdaluno].CPF) - 1; 
  if (listaluno[qtdaluno].CPF[ln] == '\n'){
    listaluno[qtdaluno].CPF[ln] = '\0';
  }
  return CAD_SUCESSO;
}
void ListarAluno(Pessoa listaluno[], int qtdaluno)
{
  if(qtdaluno == 0){
    printf("Lista vazia!!\n\n");
  }
  else{
    printf("ordenar por sexo(1), nome(2) ou idade(3) ?");
    int listoption;
    scanf("%d", &listoption);
    switch(listoption){
      case 1:{
        for(int i = 0; i<qtdaluno; i++){
          if(listaluno[i].ativo == 1 && (listaluno[i].sexo == 'f' || listaluno[i].sexo == 'F')){
            printf("%s\n", listaluno[i].nome);
            printf("aluno %d\n", listaluno[i].matricula);
            printf("Sexo: %c\n", listaluno[i].sexo);
            printf("Data Nascimento: %d/%d/%d\n", listaluno[i].dataNascimento.dia, listaluno[i].dataNascimento.mes, listaluno[i].dataNascimento.ano);
            printf("CPF: %s\n", listaluno[i].CPF);
          }
        }
        for(int i = 0; i<qtdaluno; i++){
          if(listaluno[i].ativo == 1 && (listaluno[i].sexo == 'm' || listaluno[i].sexo == 'M')){
            printf("%s\n", listaluno[i].nome);
            printf("aluno %d\n", listaluno[i].matricula);
            printf("Sexo: %c\n", listaluno[i].sexo);
            printf("Data Nascimento: %d/%d/%d\n", listaluno[i].dataNascimento.dia, listaluno[i].dataNascimento.mes, listaluno[i].dataNascimento.ano);
            printf("CPF: %s\n", listaluno[i].CPF);
          }
        }
      }
      case 2: {
        
        char nomeaux[50];
        for (int i = 1; i < qtdaluno; i++) { 
          for (int j = 1; j < qtdaluno; j++) {
      // verifica se tem que ser depois, se for troca de posição
            if (strcmp(listaluno[j - 1].nome, listaluno[j].nome) > 0) {
               strcpy(nomeaux, listaluno[j - 1].nome);
               strcpy(listaluno[j - 1].nome, listaluno[j].nome);
               strcpy(listaluno[j].nome, nomeaux);
            }
          }
        }
        for(int i = 0; i<qtdaluno; i++){
          if(listaluno[i].ativo == 1){
            printf("%s\n", listaluno[i].nome);
            printf("aluno %d\n", listaluno[i].matricula);
            printf("Sexo: %c\n", listaluno[i].sexo);
            printf("Data Nascimento: %d/%d/%d\n", listaluno[i].dataNascimento.dia, listaluno[i].dataNascimento.mes, listaluno[i].dataNascimento.ano);
            printf("CPF: %s\n", listaluno[i].CPF);
          }
        }
      }
      case 3: {
        Pessoa aux;
        for(int i =0; i < qtdaluno;i++){
          if (listaluno[i].dataNascimento.ano > listaluno[i+1].dataNascimento.ano){
            aux = listaluno[i+1];
            listaluno[i+1]=listaluno[i];
            listaluno[i] = aux;
          }
        }
        for(int i =0; i < qtdaluno;i++){
          if (listaluno[i].dataNascimento.ano == listaluno[i+1].dataNascimento.ano){
            if (listaluno[i].dataNascimento.mes > listaluno[i+1].dataNascimento.mes){
              aux = listaluno[i+1];
              listaluno[i+1]=listaluno[i];
              listaluno[i] = aux;
            }
          }
        }
        for(int i =0; i < qtdaluno;i++){
          if(listaluno[i].dataNascimento.ano == listaluno[i+1].dataNascimento.ano){
            if(listaluno[i].dataNascimento.mes == listaluno[i+1].dataNascimento.mes){
              if(listaluno[i].dataNascimento.dia > listaluno[i+1].dataNascimento.dia){
                aux = listaluno[i+1];
                listaluno[i+1]=listaluno[i];
                listaluno[i] = aux;
              }
            }
          }
        }
        for(int i = 0; i<qtdaluno; i++){
          if(listaluno[i].ativo == 1){
            printf("%s\n", listaluno[i].nome);
            printf("aluno %d\n", listaluno[i].matricula);
            printf("Sexo: %c\n", listaluno[i].sexo);
            printf("Data Nascimento: %d/%d/%d\n", listaluno[i].dataNascimento.dia, listaluno[i].dataNascimento.mes, listaluno[i].dataNascimento.ano);
            printf("CPF: %s\n", listaluno[i].CPF);
          }  
        }
      }
    }
  }
}
int DeletarAluno(Pessoa listaluno[], int qtdaluno)
{
  printf("Digite o n* de matricula do aluno que será excluído:");
  int matricula;
  int aux;
  scanf("%d", &matricula);
  for(int i = 0;i<qtdaluno;i++){
    if(listaluno[i].matricula == matricula){
      listaluno[i].ativo = 0;
      aux++;
      return ALUNO_DELETADO;
    }
  }
  return MATRICULA_INVALIDA;
}

//PROFESSOR
int CadastrarProfessor(Pessoa listProf[], int qtdProf)
{
  int matricula;
  char nome[50];
  char sexo;
  char disciplina[10];
  Data dataNascimento;
  int ativo;
  char CPF[15];
  if(qtdProf == TAM_ALUNO)
  {
    return LISTA_CHEIA;
  } 
  else
  {
    printf("n* de matricula: ");
    int matricula;
    scanf("%d", &matricula);
    if(matricula < 0)
    {
      return MATRICULA_INVALIDA;
    }
    printf("\n### Cadastro de Aluno ###\n");
    printf("Digite a matrícula: ");
    scanf("%d", &listProf[qtdProf].matricula);
    getchar();
    
    printf("Digite o nome: ");
    fgets(listProf[qtdProf].nome, 50, stdin); 
  
    size_t ln = strlen(listProf[qtdProf].nome) - 1; //size_t = unsigned integer type
    if (listProf[qtdProf].nome[ln] == '\n')
    {
      listProf[qtdProf].nome[ln] = '\0';
    }
    printf("Digite o sexo: ");
    scanf("%c", &listProf[qtdProf].sexo);
    
    printf("Digite o dia de nascimento: ");
    scanf("%d", &listProf[qtdProf].dataNascimento.dia);
  
    printf("Digite o mês de nascimento: ");
    scanf("%d", &listProf[qtdProf].dataNascimento.mes);
  
    printf("Digite o ano de nascimento: ");
    scanf("%d", &listProf[qtdProf].dataNascimento.ano);
    getchar();
  
    printf("Digite o CPF: ");
    fgets(listProf[qtdProf].CPF, 15, stdin); 
    ln = strlen(listProf[qtdProf].CPF) - 1; 
    if (listProf[qtdProf].CPF[ln] == '\n')
    {
      listProf[qtdProf].CPF[ln] = '\0';
    }
    return CAD_SUCESSO;
  }
} 
int DeletarProfessor(Pessoa listProf[], int qtdProf)
{
  printf("Digite o n* de matricula do aluno que será excluído:");
  int matricula;
  int aux;
  scanf("%d", &matricula);
  for(int i = 0;i<qtdProf;i++){
    if(listProf[i].matricula == matricula){
      listProf[i].ativo = 0;
      aux++;
      return ALUNO_DELETADO;
    }
  }
  return MATRICULA_INVALIDA;
}
void ListarProfessor(Pessoa listProf[], int qtdProf)
{
  if(qtdProf == 0)
  {
    printf("Lista vazia!!\n\n");
  }
  else{
    printf("ordenar por sexo(1), nome(2) ou idade(3) ?");
    int listoption;
    scanf("%d", &listoption);
    switch(listoption){
      case 1:{
        for(int i = 0; i<qtdProf; i++){
          if(listProf[i].ativo == 1 && (listProf[i].sexo == 'f' || listProf[i].sexo == 'F')){
            printf("%s\n", listProf[i].nome);
            printf("aluno %d\n", listProf[i].matricula);
            printf("Sexo: %c\n", listProf[i].sexo);
            printf("Data Nascimento: %d/%d/%d\n", listProf[i].dataNascimento.dia, listProf[i].dataNascimento.mes, listProf[i].dataNascimento.ano);
            printf("CPF: %s\n", listProf[i].CPF);
          }
        }
        for(int i = 0; i<qtdProf; i++){
          if(listProf[i].ativo == 1 && (listProf[i].sexo == 'm' || listProf[i].sexo == 'M')){
            printf("%s\n", listProf[i].nome);
            printf("aluno %d\n", listProf[i].matricula);
            printf("Sexo: %c\n", listProf[i].sexo);
            printf("Data Nascimento: %d/%d/%d\n", listProf[i].dataNascimento.dia, listProf[i].dataNascimento.mes, listProf[i].dataNascimento.ano);
            printf("CPF: %s\n", listProf[i].CPF);
          }
        }
      }
      case 2: {
        
        char nomeaux[50];
        for (int i = 1; i < qtdProf; i++) { 
          for (int j = 1; j < qtdProf; j++) {
      // verifica se tem que ser depois, se for troca de posição
            if (strcmp(listProf[j - 1].nome, listProf[j].nome) > 0) {
               strcpy(nomeaux, listProf[j - 1].nome);
               strcpy(listProf[j - 1].nome, listProf[j].nome);
               strcpy(listProf[j].nome, nomeaux);
            }
          }
        }
        for(int i = 0; i<qtdProf; i++){
          if(listProf[i].ativo == 1){
            printf("%s\n", listProf[i].nome);
            printf("aluno %d\n", listProf[i].matricula);
            printf("Sexo: %c\n", listProf[i].sexo);
            printf("Data Nascimento: %d/%d/%d\n", listProf[i].dataNascimento.dia, listProf[i].dataNascimento.mes, listProf[i].dataNascimento.ano);
            printf("CPF: %s\n", listProf[i].CPF);
          }
        }
      }
      case 3: {
        Pessoa aux;
        for(int i =0; i < qtdProf;i++){
          if (listProf[i].dataNascimento.ano > listProf[i+1].dataNascimento.ano){
            aux = listProf[i+1];
            listProf[i+1]=listProf[i];
            listProf[i] = aux;
          }
        }
        for(int i =0; i < qtdProf;i++){
          if (listProf[i].dataNascimento.ano == listProf[i+1].dataNascimento.ano){
            if (listProf[i].dataNascimento.mes > listProf[i+1].dataNascimento.mes){
              aux = listProf[i+1];
              listProf[i+1]=listProf[i];
              listProf[i] = aux;
            }
          }
        }
        for(int i =0; i < qtdProf;i++){
          if(listProf[i].dataNascimento.ano == listProf[i+1].dataNascimento.ano){
            if(listProf[i].dataNascimento.mes == listProf[i+1].dataNascimento.mes){
              if(listProf[i].dataNascimento.dia > listProf[i+1].dataNascimento.dia){
                aux = listProf[i+1];
                listProf[i+1]=listProf[i];
                listProf[i] = aux;
              }
            }
          }
        }
        for(int i = 0; i<qtdProf; i++){
          if(listProf[i].ativo == 1){
            printf("%s\n", listProf[i].nome);
            printf("aluno %d\n", listProf[i].matricula);
            printf("Sexo: %c\n", listProf[i].sexo);
            printf("Data Nascimento: %d/%d/%d\n", listProf[i].dataNascimento.dia, listProf[i].dataNascimento.mes, listProf[i].dataNascimento.ano);
            printf("CPF: %s\n", listProf[i].CPF);
          }  
        }
      }
    }
  }
}

//DISCIPLINA
int InserirAluno(Disciplina disciplinas[], int qtdDis, Pessoa alunos[])
{
  char nome[50];
  int codigo;
  int semestre;
  int Professor;
  if(qtdDis == TAM_DIS)
  {
    return LISTA_CHEIA;
  } 
  else
  {
    printf("n* de matricula:");
    int matricula;
    scanf("%d", &matricula);
    if(matricula < 0)
    {
      return MATRICULA_INVALIDA;
    }
    for(int i = 1; i < TAM_DIS; i++)
    {
      if(alunos[i].matricula == matricula)
      {
        if(disciplinas[i].alunos[i] == 0 && disciplinas[i].alunos[i] != matricula)
        {  
          disciplinas[i].alunos[i] = matricula;
          return CAD_SUCESSO;
          break;
        }
      }
    }
  }
  return 0;
}
int CadastrarDisciplina(Disciplina disciplinas[], int qtdDis)
{
  printf("nome da disciplina: ");
  fgets(disciplinas[qtdDis].nome, 50, stdin); 
    
  size_t ln = strlen(disciplinas[qtdDis].nome) - 1; 
  if (disciplinas[qtdDis].nome[ln] == '\n')
  {
    disciplinas[qtdDis].nome[ln] = '\0';
  }
  printf("código: ");
  scanf("&d", &disciplinas[qtdDis].codigo);
  printf("semestre: ");
  scanf("%d", &disciplinas[qtdDis].semestre);
  printf("professor da disciplina: ");
  scanf("%d", &disciplinas[qtdDis].Professor);
  return CAD_SUCESSO;
}
int ExcluirAluno(Disciplina disciplinas[], int qtdDis, Pessoa alunos[])
{
  char nome[50];
  int codigo;
  int semestre;
  int Professor;
  printf("n* de matricula:");
  int matricula;
  scanf("%d", &matricula);
  if(matricula < 0)
  {
    return MATRICULA_INVALIDA;
  }
  for(int i = 1; i < TAM_DIS; i++)
  {
    if(alunos[i].matricula == matricula)
    {
      if(disciplinas[i].alunos[i] == matricula)
      {  
        disciplinas[i].alunos[i] = -1;
        return CAD_SUCESSO;
        break;
      }
    }
  }
  return 0;
}
void ListarDisc(Disciplina disciplinas[], int qtdDis)
{
  for(int i=0; i < TAM_DIS; i++)
    {
      for(int j = 0; j < TAM_DIS; j++)
      {
        printf("Disciplina: ");
        printf("%c", disciplinas[i].nome[j]);
      }
    }
}