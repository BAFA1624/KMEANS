#include "ProcessFile.h"

int main() {

	RawData* data = ParseFile("data.txt");
	RowHolder* test = RawToRows(data);
/*	
	char* txt = data->txt;

	char* test = ConcatArr(txt, 40, 43);

	printf("\n%c%c%c%c\n", txt[40], txt[41], txt[42], txt[43]);
	printf("\n%s\n", test);
*/

	int i;
	for (i = 0; i < 5; ++i) {
		printf("\n%s\n", test->rows[i]);
	}

	delRawData(data);

}
