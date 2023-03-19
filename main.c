// OTAVIO SALOMAO ROCHA         TURMA M2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGS_LENGTH 103
#define DIR_LENGHT 10

int minOperations(char ** logs, int logsSize) {
    int quantity = 0;

    for ( int i=0 ; i<logsSize ; i++ ) {
        if ( quantity == 0 ) {
            if ( !strcmp(logs[i], "./") || !strcmp(logs[i], "../") ) {
                ;
            } else {
                quantity++;
            }
        } else {
            if ( !strcmp(logs[i], "./") ) {
                ;
            } else if ( !strcmp(logs[i], "../") ) {
                quantity--;
            } else {
                quantity++;
            }
        }
    }

    return quantity;
}

int main() {
    char ** logs;
    int count = 0;
    char log[10];
    int j = 0;
    int flag;
    int steps;

    logs = ( char ** )malloc( LOGS_LENGTH * sizeof(char *) );
    
    for ( int i=0 ; i<LOGS_LENGTH ; i++ ) {
        j = 0;
        flag = 0;
        scanf("%9[^\n]s", log);
        if ( !strcmp(log, "esc") ) {
            i = LOGS_LENGTH;
        } else {
            while ( log[j] != '\0' ) {
                if ( log[j] == '/' ) {
                    flag++;
                }
                j++;
            }
            
            if ( flag==1 ) {
                logs[count] = ( char * )malloc( sizeof( char ) * DIR_LENGHT );
                strcpy(logs[count], log);
                count++;
            }
        }
        getchar();
    }

    steps = minOperations( logs, count );
    printf("Serao %d operacoes ate o main\n", steps);

    for ( int i=0 ; i<count ; i++ )
        free( logs[i] );
    free( logs );

    return 0;
}
