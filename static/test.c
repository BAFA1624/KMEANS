#include "ProcessFile.h"

int main() {

	int** test = FileToIntArray( "test.txt", ',' );
    int i, j;
    for ( i = 0; i < 3; ++i ) {

        for ( j = 0; j < 5; ++j ) {

            printf("%d\t", test[i][j]);

        }

        putchar('\n');

    }

}
