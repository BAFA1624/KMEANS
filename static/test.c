#include "ProcessFile.h"

int main() {

	RawData* data = ParseFile("data.txt");
	RowHolder* test = RawToRows(data);

	int i;
	for (i = 0; i < 1; ++i) {
		printf("\n%s\nn_rows = %lu\n", test->rows[i], test->n_rows);
	}

}
