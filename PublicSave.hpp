#pragma once
#include <iostream>
#include <fstream>
#include <vector>

namespace PublicSave
{
	void InjectOptionBin(const std::string& optionBinPath, const std::string& publicSavPath)
	{
		std::ifstream optionBinFile(optionBinPath, std::ios::binary);
		if (!optionBinFile)
		{
			std::cerr << "Error while opening option.bin file" << std::endl;
			throw std::runtime_error("Failed to open option.bin file");
		}

		std::vector<unsigned char> opBinData(0x100);
		optionBinFile.read(reinterpret_cast<char*>(opBinData.data()), opBinData.size());

		std::fstream publicSavFile(publicSavPath, std::ios::binary | std::ios::in | std::ios::out);
		if (!publicSavFile)
		{
			std::cerr << "Error while opening public.sav file" << std::endl;
			throw std::runtime_error("Failed to open public.sav file");
		}

		publicSavFile.seekp(0x45A00, std::ios::beg);
		publicSavFile.write(reinterpret_cast<const char*>(opBinData.data()), opBinData.size());

		if (!publicSavFile.good())
		{
			std::cerr << "Error while writing to public.sav file" << std::endl;
			throw std::runtime_error("Failed to write to public.sav file");
		}
	}

	void GetOptionBin(const std::string& optionBinName, const std::string& publicSavPath)
	{
		std::ifstream publicSavFile(publicSavPath, std::ios::binary);
		if (!publicSavFile)
		{
			std::cerr << "Error while opening public.sav file" << std::endl;
			throw std::runtime_error("Failed to open public.sav file");
		}

		publicSavFile.seekg(0x45A00, std::ios::beg);

		std::vector<unsigned char> opBinData(0x100);
		publicSavFile.read(reinterpret_cast<char*>(opBinData.data()), opBinData.size());

		if (!publicSavFile)
		{
			std::cerr << "Error while reading public.sav file" << std::endl;
			throw std::runtime_error("Failed to read public.sav file");
		}

		std::ofstream optionBinFile(optionBinName, std::ios::binary);
		if (!optionBinFile)
		{
			std::cerr << "Error while opening option.bin file" << std::endl;
			throw std::runtime_error("Failed to open option.bin file");
		}

		optionBinFile.write(reinterpret_cast<const char*>(opBinData.data()), opBinData.size());

		if (!optionBinFile.good())
		{
			std::cerr << "Error while writing to option.bin file" << std::endl;
			throw std::runtime_error("Failed to write to option.bin file");
		}
	}
};
