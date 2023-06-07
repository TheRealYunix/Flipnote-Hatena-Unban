#include <iostream>
#include <ctime>

#include "PublicSave.hpp"

#define FLIPNOTE_USER_ID_SEEK	 0x10

uint32_t GenerateRandomID()
{
	srand(time(0));
	uint32_t randomNumber = 0;
	for (int i = 0; i < 8; i++)
	{
		randomNumber <<= 4; 
		randomNumber |= rand() % 16;
	}
	return randomNumber;
}

void WriteFlipnoteID(const char *path, uint32_t Data)
{
	FILE *file;
	
	if (fopen_s(&file, path, "rb+")) {
		std::cerr << "Error while opening file" << std::endl;
		fclose(file);
		exit(0);
	}

		fseek(file, FLIPNOTE_USER_ID_SEEK, SEEK_SET);
		fwrite(&Data, sizeof(Data), 1, file);
		fclose(file);
}

//0x10	uint64	User's Flipnote Studio ID in little endian byte order
uint64_t ReadFlipnoteID(const char* path)
{
	FILE *data;
	uint64_t FlipnoteID;	//Data Buffer
	if (fopen_s(&data, path, "rb"))
	{
		std::cerr << "Error while opening file" << std::endl;
		fclose(data);
		exit(0);
	}
	fseek(data, FLIPNOTE_USER_ID_SEEK, SEEK_SET);
	fread_s(reinterpret_cast<char*>(&FlipnoteID), sizeof(uint64_t), sizeof(uint64_t), 1, data);
	fclose(data);
	return FlipnoteID;
}
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " [options]\n";
		std::cerr << "Options:\n";
		std::cerr << "  -o <option.bin> <public.sav>    Extract option.bin from public.sav\n";
		std::cerr << "  -i <option.bin> <public.sav>    Inject option.bin into public.sav\n";
		std::cerr << "	<option.bin>              Randomize option.bin\n";
		std::cerr << "By Yunix\n";
		return 1;
	}

	if (strcmp(argv[1], "-o") == 0)
	{
		if (argc != 4)
		{
			std::cerr << "Usage: " << argv[0] << " -o <option.bin> <public.sav> extracts option.bin from public.sav\n";
			return 1;
		}
		PublicSave::GetOptionBin(argv[2], argv[3]);
		std::cout << "Option.bin extracted from public.sav successfully.\n";
	}
	else if (strcmp(argv[1], "-i") == 0)
	{
		if (argc != 4)
		{
			std::cerr << "Usage: " << argv[0] << " -i <option.bin> <public.sav>\n";
			return 1;
		}
		PublicSave::InjectOptionBin(argv[2], argv[3]);
		std::cout << "Option.bin injected into public.sav successfully.\n";
	}
	else
	{
		printf("Your Flipnote ID is: %llX\n\n", ReadFlipnoteID(argv[1]));

		uint32_t RandomID = GenerateRandomID();
		printf("Generated Cheat code: [002207156 %X]\n\n", RandomID);
		WriteFlipnoteID(argv[1], RandomID);

		printf("Your new Flipnote ID is: %llX\n", ReadFlipnoteID(argv[1]));
	}

	system("pause");
	return 0;
}
