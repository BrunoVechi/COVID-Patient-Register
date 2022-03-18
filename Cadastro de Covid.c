#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <string.h>
#include <windows.h>

void Cabecalho(){
	system("cls");
	
	printf("***********************************************************\n");
    printf("**************   BANCO DE DADOS - COVID-19  ***************\n");
    printf("***********************************************************\n\n");
}

void clear_keyboard_buffer(){
	
	/*Limpa buffer de teclado */
	
	printf ("Pressione Enter, e digite o novo valor! ");
		
    int ch;
    do {
        ch = fgetc(stdin);        
    } while (ch != EOF && ch != '\n');

}

void clear_keyboard_buffer2(){
	
	/*Limpa buffer de teclado */

    int ch;
    do {
        ch = fgetc(stdin);        
    } while (ch != EOF && ch != '\n');

}

void Ler_Banco(){
    Start:;
    Cabecalho();
	char c;
	int inf = 0;
	
    FILE *banco;  
  	banco = fopen("Banco_de_Dados.txt", "r");
 
	do{ 
	    Inicio:
	    if (inf == 1){ printf("NOME DO PACIENTE: "); printf("%c", c); inf += 1 ;}			      	
    	c = fgetc(banco);
    	
		if(c == ';'){ 
		inf += 1 ;
		if(inf > 26){
			printf("\n----------------\n");
			inf = 1;
			c = fgetc(banco);
			goto Inicio;} 
		
		c = fgetc(banco);		
		}
		
		if (inf == 3){ printf("\nCPF: "); inf += 1;}
		if (inf == 5){ printf("\nANO DE NASCIMENTO: "); inf += 1;}
		if (inf == 7){ printf("\nTELEFONE: "); inf += 1;}
		if (inf == 9){ printf("\nEMAIL: "); inf += 1;}
		if (inf == 11){ printf("\nDATA DE DIAGNOSTICO: "); inf += 1;}
		if (inf == 13){ printf("\nCOMORBIDADE: "); inf += 1;}
		if (inf == 15){ printf("\nRUA: "); inf += 1;}
		if (inf == 17){ printf("\nNUMERO DA CASA: "); inf += 1;}
		if (inf == 19){ printf("\nBAIRRO: "); inf += 1;}
		if (inf == 21){ printf("\nCIDADE: "); inf += 1;}
		if (inf == 23){ printf("\nESTADO: "); inf += 1;}
		if (inf == 25){ printf("\nCEP: "); inf += 1;}
	
		if (c != EOF) 
		{	if(inf != 1)
				{printf("%c", c);}
		}
		else
		{ break;}
	
  		}
  		
		while (c!= '\n' );
		fclose(banco);
		
	int opcao = 0;
   
   
    clear_keyboard_buffer2();
    
    printf("\n\n----------------\n");
    printf("\n1) - VOLTAR AO MENU ANTERIOR\n");
    printf("2) - FILTRAR PACIENTES DO GRUPO DE RISCO\n");    
    printf("3) - SAIR DO SISTEMA\n\n"); 
	Menuu:   
    printf("DIGITE A OPCAO DESEJADA: ");
    scanf("%d", &opcao);
    
    switch (opcao)
    
        {   case 1 : 
                break;          	
            
            case 2 : 
				system("cls");
			    Cabecalho();
			     
				char c;
				int inf = 0;
				
			    FILE *banco2;  
			  	banco2 = fopen("Banco_de_Dados_RISCO.txt", "r");
			 
					do{ 
					Inicio2:
				    if (inf == 1){ printf("NOME DO PACIENTE: "); printf("%c", c); inf += 1 ;}			      	
			    	c = fgetc(banco2);
			    	
					if(c == ';'){ 
					inf += 1 ;
					if(inf > 26){
						printf("\n----------------\n");
						inf = 1;
						c = fgetc(banco2);
						goto Inicio2;} 
					
					c = fgetc(banco2);		
					}
					
					if (inf == 3){ printf("\nCPF: "); inf += 1;}
					if (inf == 5){ printf("\nANO DE NASCIMENTO: "); inf += 1;}
					if (inf == 7){ printf("\nTELEFONE: "); inf += 1;}
					if (inf == 9){ printf("\nEMAIL: "); inf += 1;}
					if (inf == 11){ printf("\nDATA DE DIAGNOSTICO: "); inf += 1;}
					if (inf == 13){ printf("\nCOMORBIDADE: "); inf += 1;}
					if (inf == 15){ printf("\nRUA: "); inf += 1;}
					if (inf == 17){ printf("\nNUMERO DA CASA: "); inf += 1;}
					if (inf == 19){ printf("\nBAIRRO: "); inf += 1;}
					if (inf == 21){ printf("\nCIDADE: "); inf += 1;}
					if (inf == 23){ printf("\nESTADO: "); inf += 1;}
					if (inf == 25){ printf("\nCEP: "); inf += 1;}
				
					if (c != EOF) 
					{	if(inf != 1)
							{printf("%c", c);}
					}
					else
					{ break;}
				
			  		}
		
					while (c!= '\n' );
				
				fclose(banco2);
					
				int opcao2 = 0;
			   
			   
			    clear_keyboard_buffer2();
			    
			    printf("\n\n----------------\n");			    
			    printf("\n1) - VOLTAR AO MENU ANTERIOR\n");
			    printf("2) - CONSULTAR TODOS PACIENTES\n");    
			    printf("3) - SAIR DO SISTEMA\n\n"); 
				Menuu2:   
			    printf("DIGITE A OPCAO DESEJADA: ");
			    scanf("%d", &opcao2);
			    
			    switch (opcao2)
			    
			        {   case 1 :					        		                
			                goto Sair;          	
			            
			            case 2 : 
							Cabecalho(); 
						   	goto Start; 				      
			            	break;
							
						case 3 :  
						    printf("\nTecle Enter!\n");           
			            	exit(0);			 
			            	
			
			            default :
			                printf("\nOPCAO INVALIDA!\n\n");                           
			                goto Menuu2;              
			            	   
			        }
				
			case 3 :  
			    printf("\nTecle Enter!\n");           
            	exit(0);			 
            	

            default :
                printf("\nOPCAO INVALIDA!\n\n");                           
                goto Menuu;              
            	   
        }
		
		Sair:;
}

int Risco(char ano[]){
	
	/* Verifica idade , caso igual ou maior que 65, entra pro grupo de risco*/
	int Ano = atoi(ano);
    if (2021 - 65 >= Ano ){ return 1;}
    return 0;	
}

int Only_TEXT(char num[]){

	/*Verifica cada caracter, se houver numero retorna 0 */
	
	int isDigito = 0;
	int j=0;
		
  	while(j<strlen(num)){
  	isDigito += isdigit(num[j]);  	
  	j++;}
  	
  	if (isDigito > 0){ return 0;}  	
  	return 1;
}

int Only_NUM(char num[]){
	
	/*Verifica cada caracter, se houver texto retorna 0 */
	
	int isDigito = 0;
	int j=0;
		
  	while(j<strlen(num)){
  	isDigito = isdigit(num[j]);
	if (isDigito == 0){return 0;}  	
  	j++;} 	
  	  	
  	return 1;
}

int Tamanho(int min , int max, char text[]){
	
	/*Verifica se string tem tamanho dentro de min-max, se sim retorna 1 */
	
	if (strlen(text) >= min && strlen(text) <= max )
	{
		return 1;
	}
	
	return 0;
}

void CadastroPaciente(){
	
	 /* A CADA 13  ponto vírgulas ';' = 1 PACIENTE */
	 
	
		clear_keyboard_buffer();
	
	
	    char nome[50];
		char CEPidade[50];
	    char paciente[250];
	    char Buffer1[100];
		int Grupo_Risco = 0;
			    
	    
 		system("cls");
	   	printf("***********************************************************\n");
    	printf("**************   CADASTRO DE NOVO PACIENTE  ***************\n");
    	printf("***********************************************************\n\n");		 
		 
		/*------DADOS PESSOAIS--------*/ 
		
		printf ("-------------------\n");
	    printf ("  Dados pessoais");
	    printf ("\n-------------------\n");
				
	    printf ("Nome completo: ");	
		strcat(paciente, ";");	/*Adiciona separador ','*/   
	    do{gets(Buffer1); 
		if (Only_TEXT(Buffer1) == 0 || Tamanho(5,50,Buffer1) == 0)
		{MessageBox(0,"Somente texto! Min 5, Max 50 caracteres", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Only_TEXT(Buffer1) == 0 || Tamanho(5,50,Buffer1) == 0 );  /*Validacao para de texto Min5 Max50*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/	
		strcat(nome, Buffer1);	/*Salva nome para arquivo de comorbidade*/	
		strcat(nome, ".txt");	/*Salva extencao do arquivo de comorbidade */  
	    
	    printf ("CPF: ");
	    do{gets(Buffer1); 
		if (Only_NUM(Buffer1) == 0 || Tamanho(11,11,Buffer1) == 0)
		{MessageBox(0,"Somente Numeros! Deve conter 12 Digitos", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Only_NUM(Buffer1) == 0 || Tamanho(11,11,Buffer1) == 0 );  /*Validacao para de Numero de 11 digitos*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
	    
	    printf ("Ano de nascimento: ");
	    do{gets(Buffer1); 
		if (Only_NUM(Buffer1) == 0 || Tamanho(4,4,Buffer1) == 0)
		{MessageBox(0,"Somente Numeros! Deve conter 4 Digitos", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Only_NUM(Buffer1) == 0 || Tamanho(4,4,Buffer1) == 0 );  /*Validacao para de Numero de 4 digitos*/	    
	    if (Risco(Buffer1) == 1){ Grupo_Risco = 1;} /* Verifica idade , caso igual ou maior que 65, entra para grupo de risco*/
		strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
		int idad = 2021 - atoi(Buffer1);
		sprintf(CEPidade, "%d", idad);/*Salva idade para arquivo de comorbidade*/	
		strcat(CEPidade, " anos de idade, CEP: ");/*Salva idade para arquivo de comorbidade*/   
	
	    printf ("Telefone: ");
	    do{gets(Buffer1); 
		if (Only_NUM(Buffer1) == 0 || Tamanho(12,12,Buffer1) == 0)
		{MessageBox(0,"Somente Numeros, DDD + Numero! Formato: xxxxxxxxxxxx", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Only_NUM(Buffer1) == 0 || Tamanho(12,12,Buffer1) == 0 );  /*Validacao para de Numero de 12 digitos*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
	    
	    printf ("Email: ");
	    do{gets(Buffer1); 
		if (Tamanho(5,50,Buffer1) == 0)
		{MessageBox(0,"Deve conter '@' ! Min 5, Max 50 caracteres", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Tamanho(5,50,Buffer1) == 0 );  /*Validacao para de texto Min5 Max50 */	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
	    
	    printf ("Data do Diagnostico: ");
	    do{gets(Buffer1); 
		if (Tamanho(10,10,Buffer1) == 0)
		{MessageBox(0,"Formato dd/mm/aaaa! Deve conter 10 caracteres", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Tamanho(10,10,Buffer1) == 0 );  /*Validacao para de Numero de 10 digitos*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
	    
	    printf ("Comorbidade? Se não, tecle Enter!: ");
	    gets(Buffer1);
		if (Tamanho(1,50,Buffer1) == 1){ 
		Grupo_Risco = 1; strcat(paciente, Buffer1);}/*Concatena com string final*/
		else{ strcat(paciente, ".");} /* Se nao, salva .*/ 
	    strcat(paciente, ";"); /*Adiciona separador ','*/  
	        
	   /*------DADOS ENDEREÇO--------*/  
	   
	    printf ("\n-------------------\n");
	    printf ("    Endereço");
	    printf ("\n-------------------\n");
	    printf ("Rua: ");
	    do{gets(Buffer1); 
		if (Only_TEXT(Buffer1) == 0 || Tamanho(5,50,Buffer1) == 0)
		{MessageBox(0,"Somente texto! Min 5, Max 50 caracteres", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Only_TEXT(Buffer1) == 0 || Tamanho(5,50,Buffer1) == 0 );  /*Validacao para de texto Min5 Max50*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
	    
	    printf ("Numero da casa: ");
	    do{gets(Buffer1); 
		if (Only_NUM(Buffer1) == 0 || Tamanho(1,5,Buffer1) == 0)
		{MessageBox(0,"Somente Numeros! Min 1, Max 5 Digitos", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Only_NUM(Buffer1) == 0 || Tamanho(1,5,Buffer1) == 0 );  /*Validacao para de Numero de min1 max5 digitos*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
	    
	    printf ("Bairro: ");
	    do{gets(Buffer1); 
		if (Tamanho(1,20,Buffer1) == 0)
		{MessageBox(0,"Deve conter Min 1 e Max 20 caracteres", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Tamanho(1,20,Buffer1) == 0 );  /*Validacao para de texto de min1 e max20 digitos*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
	    
	    printf ("Cidade: ");
	   	do{gets(Buffer1); 
		if (Tamanho(1,20,Buffer1) == 0)
		{MessageBox(0,"Deve conter Min 1 e Max 20 caracteres", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Tamanho(1,20,Buffer1) == 0 );  /*Validacao para de texto de min1 e max20 digitos*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
	    
	    printf ("Estado: ");
	    do{gets(Buffer1); 
		if (Tamanho(1,20,Buffer1) == 0)
		{MessageBox(0,"Deve conter Min 1 e Max 20 caracteres", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Tamanho(1,20,Buffer1) == 0 );  /*Validacao para de texto de min1 e max20 digitos*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/
	    strcat(paciente, ";");	/*Adiciona separador ','*/
	    
	    printf ("CEP: ");
	    do{gets(Buffer1); 
		if (Only_NUM(Buffer1) == 0 || Tamanho(8,8,Buffer1) == 0)
		{MessageBox(0,"Somente Numeros! deve conter 8 Digitos", "Erro", MB_OK ); clear_keyboard_buffer();}}/*Se informação incorreta*/ 
		while (Buffer1[0] == '\0' || Only_NUM(Buffer1) == 0 || Tamanho(8,8,Buffer1) == 0 );  /*Validacao para de Numero de 8 digitos*/	    
	    strcat(paciente, Buffer1); /*Concatena com string final*/	    
		strcat(CEPidade, Buffer1);/*Salva CEP para arquivo de comorbidade*/   
		
		/* BANCO DE DADOS*/
		FILE *Banco;
		Banco = fopen("Banco_de_Dados.txt", "a"); 
		fputs(paciente, Banco);  
		fclose(Banco);
		
		/* BANCO DE DADOS - GRUPO DE RISCO*/
		if (Grupo_Risco == 1){
			
			FILE *Banco2;
			Banco2 = fopen("Banco_de_Dados_RISCO.txt", "a"); 
			fputs(paciente, Banco2);  
			fclose(Banco2);
			
			FILE *Pacient;
			Pacient = fopen( nome, "a"); 
			fputs(CEPidade, Pacient);  
			fclose(Pacient);
			
		}	
		
		MessageBox(0,"Cadastro realizado com sucesso!", "", MB_OK );	
	
		
}

void Login(){
	
	char login[6] = "admin"; 
    char senha[7] = "123456";
    char login1[6]; 
	char senha1[7];   
    
    do{  
		system("cls");
		printf("***********************************************************\n");
    	printf("******  SEJA BEM VINDO AO BANCO DE DADOS - COVID-19  ******\n");
    	printf("***********************************************************\n\n");
    	
		printf("Digite o Login: ");
    	scanf("%s", login1);

    	printf("Digite a Senha: ");
    	scanf("%s", senha1);
		
		if (strcmp(login, login1) || strcmp(senha, senha1)){
		
			printf("\n\nLOGIN OU SENHA INCORRETO!\n\n");
			system("pause");
			system("cls");}			
		
	} while (strcmp(login, login1) || strcmp(senha, senha1));
	
	printf("\n\nLOGIN EFETUADO COM SUCESSO!\n\n ");
    system("pause");
    
}

void Menu(){
	
	int opcao = 0;
    Menuu:
    clear_keyboard_buffer2();
    
    Cabecalho();
    
    printf("1) - CADASTRO DE PACIENTE\n");
    printf("2) - CONSULTAR PACIENTES\n");    
    printf("3) - SAIR DO SISTEMA\n\n");    
    printf("DIGITE A OPCAO DESEJADA: ");
    scanf("%d", &opcao);
    
    switch (opcao)
    
        {   case 1 : 
                CadastroPaciente();
				break;          	
            
            case 2 : 				
			    Ler_Banco(); 				      
            	break;
				
			case 3 :  
			    printf("\nTecle Enter!\n");         
            	exit(0);			 
            	

            default :
                printf("\nOPCAO INVALIDA!\n\n");
                system("pause");                
                system("cls");
                goto Menuu;              
            	   
        } 
		
		goto Menuu;         

}

int main(){

    setlocale(LC_ALL, "");
  
    Login();

    Menu();  

    return 0;
}
