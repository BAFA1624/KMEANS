#include "ProcessFile.h"

int main() {

	RawData* data = ParseFile("data.txt");
	RowHolder* test = RawToRows(data);

	/*unsigned long i;
	for (i = 0; i < test->n_rows; ++i) {
		printf("%s\n", test->rows[i]);
	}*/

	delRawData(data);
	delRowHolder(test);

}
