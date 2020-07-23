#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <err.h>
#include <sys/types.h>

//funzione che controlla se la stringa passata come argomento è o meno un numero
int isNumber(char number[]){
    int i = 0;
    if (number[i] == '-'){
        i++;
    }
    for (; number[i] != '\0'; i++){
        if (!isdigit(number[i])) 
            return 0;
    }
    return i;
}

//funzione che esegue fibonacci richiamando ad ogni passo della ricorsione un nuovo processo
int fibonacci(int n){
	int pid1;
    int pid2;
	int fib;
	int status;
    int sum;

    //casi base della ricorsione con fibonacci
    if(n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }

    //creo un processo che si occuperà di calcolare(n-1)
	pid1 = fork();
	if (pid1 == 0){
        exit(fibonacci(n-1));
    }else {
        if ( pid1 < 0 ){
            perror("fork");
            exit(EXIT_FAILURE);
        } else{
            if (waitpid(pid1, &status, 0) == -1){
                perror("waitpid");
            }
        }
    }
    //attendo il completamento del processo 1
    if (WIFEXITED(status)){ //se vi è stato un exit lo attendo e lo catturo se non vi è stato un errore
        fib = WEXITSTATUS(status);
    }

    //creo un processo che si occupera di calcolare (n-2)
	pid2 = fork();
	if (pid2 == 0){ 
        exit(fibonacci(n-2));
        }
	else{
        if (pid2 < 0){
            perror("fork");
            exit(EXIT_FAILURE);
        } else{
            if (waitpid(pid2, &status, 0) == -1){
                perror("waitpid");
            }
        }
    }


	
    //attendo il completamento del processo2
    if (WIFEXITED(status)){ //se vi è stato un exit lo attendo e lo catturo se non vi è stato un errore
        sum = fib + WEXITSTATUS(status);
    }
	return sum;
}

int main(int argc, char *argv[]){
    if (argc != 2 || !isNumber(argv[1])){
        fprintf(stderr, "Inserisci un unico argomento: %s [INT]\n", argv[0]);
        return -1;
    }
    int numero = atoi(argv[1]);
    if(numero >= 0 && numero <= 10){ //controllo sull'input inserito
        //fprintf(stdout, "%d\n", numero);
    } else {
        fprintf(stderr, "Inserisci un unico numero compreso tra 0 e 10: %s\n", argv[0]);
        return -1;
    }     
    fprintf(stdout, "%d\n", fibonacci(numero));
    return 0;
}

