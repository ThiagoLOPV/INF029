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
  typedef struct disciplina
{
  char nome[50];
  int codigo;
  int semestre;
  int Professor;
  int alunos[TAM_DIS];
}Disciplina;
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