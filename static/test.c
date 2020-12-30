#include "LoadData.h"

int main() {

	RawData* data;
	data = LoadIntData("data.txt");
	//printf("\n%s\n", data->txt);
	delRawData(data);
}
