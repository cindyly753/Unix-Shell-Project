#include <stdio.h>
#include <string.h>
#include <unistd.h>​

#define read_end 0
#define write_end 1

void token_read(char* input, char* token[]) {
  const char break_chars[2] = " \t";
  char* t;
  t = strtok(input, break_chars);
  while (t != NULL) {
    printf("token was: %s\n", t);
    t = strtok(NULL, break_chars);
  }
}

int main(int argc, const char * argv[]) {  
  char input[BUFSIZ];
  char last[BUFSIZ];
  char** token;
  int fd[2];

  int shouldRun = 1; /* flag to determine when to exit program */

  memset(input, 0, BUFSIZ * sizeof(char));
  memset(input, 0, BUFSIZ * sizeof(char));
  bool finished = false;
  
  while (shouldRun) {
    printf("osh> ");
    fflush(stdout);
    token_read(input, token);
    
/**     
 * After reading user input, the steps are:     
 * (1) fork a child process using fork()     
 * (2) the child process will invoke execvp()     
 * (3) parent will invoke wait() unless command included &      
**/

    pid_t pid = fork();
    if(pid == 0){
        printf("Invalid\n");
    else {
        if(pid != 0) {
            if(dowait) {
                wait(NULL);
            }

        }
    }

   char lhs[BUFSIZ];
   char rhs[BUFSIZ];
   memset(lhs, 0, BUFSIZ * sizeof(char));
   memset(rhs, 0, BUFSIZ * sizeof(char));

    pid_t pid2 = fork();
    	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	if (pid2 < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}
}
    if(pid2 < 0) {
        printf("Fork Failed\n");
        return 0;
    else if(pid2 == 0){
        dup2(fd[write_end]);
        close(fd[write_end]);
        execp(lhs[0], lhs);
        exit(0);
        }
    else 
        if(pid2 != 0){
            dup2(fd[write_end]);
            close(fd[write_end]);
            execp(rhs[0], rhs);
            exit(0);
        }
    }
    }

    if ((fgets(input, BUFSIZ, stdin)) == NULL) {   
      fprintf(stderr, "no command entered\n");
      exit(1);
    }
    input[strlen(input) - 1] = '\0';          
    printf("input was: \n'%s'\n", input);
​
    if (strncmp(input, "!!", 2) == 0) {
      if (strlen(last) == 0) {
        fprintf(stderr, "no last command to execute\n");
      }
      printf("last command was: %s\n", last);
    } else if (strncmp(input, "exit", 4) == 0) {   /    
      finished = true;
    } else {
      strcpy(last, input);
      printf("You entered: %s\n", input);  
      token_read(input);                                  
      printf("\n");
    }
  }
  return 0;
}
