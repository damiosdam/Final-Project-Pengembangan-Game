#include "ControlHelper.h"

#include <fstream>

int ControlHelper::kunci[5];

void ControlHelper::SetKey()
{
	std::ifstream ReadKey("key.txt");
	int i=0;

	if (ReadKey.is_open()) {
		int key;
		while (ReadKey) {
			key = ReadKey.get();
			kunci[i] = key;
			i++;
		}
	}
}

void ControlHelper::UpdateKey()
{
	std::ofstream WriteKey("key.txt");
	
	for (int i = 0; i < 5; i++) {
		WriteKey << kunci[i] << "\n";
	}

	WriteKey.close();
}
