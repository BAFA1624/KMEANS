#include "ProcessFile.h"

int main() {

	RawData* data = ParseFile("test.txt");
	int** test = RawToIntArray(data, ' ');
	
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d\t", test[i][j]);
		}
		putchar('\n');
	}

}
