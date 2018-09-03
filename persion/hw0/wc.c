#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include<ctype.h>
const static int OPEN_FILE_ERROR=1;

int main(int argc, char *argv[]) {
    char buffer[1024];
    int infd;
    bool isStdIn;
    if(argc==1){
      infd=STDIN_FILENO;
      isStdIn=true;
      }
    else{
      infd=open(argv[1],O_RDONLY);
      if(infd==-1){
        fprintf (stderr,"File %s can't be open!",argv[1]);
        return OPEN_FILE_ERROR;
        }
      isStdIn=false;
      }
    int readedBetys=0;
    int readedLines=0;
    int readedWords=0;
    bool isPrvousWhiteSpace=true;
    while (true) {
        int currentReaded=read(infd,buffer,1024);

        if(currentReaded==0) break;
        if(currentReaded<0){
            printf ("Cant read the input file anymore\n");
            return -1;
          }
        readedBetys+=currentReaded;
        for(int i=0;i<currentReaded;i++){
            if(!isspace(buffer[i])){
              if(isPrvousWhiteSpace){
                  readedWords+=1;
                  isPrvousWhiteSpace=false;
                }
            }
            else{
                isPrvousWhiteSpace=true;
              }
            if(buffer[i]=='\n')
              readedLines+=1;

          }
      }
    if(!isStdIn)
      printf ("  %i %i %i %s\n",readedLines,readedWords,readedBetys,argv[1]);
    else
      printf ("\t%i\t%i\t%i\n",readedLines,readedWords,readedBetys);
    return 0;
}
