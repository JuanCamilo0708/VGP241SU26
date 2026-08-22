#pragma once
#include <string>
#include <iostream>
class Texture
{
public:
	Texture(const std::string& filePath)
		: mFilePath(filePath)
	{
	}
	Texture() {}
	void Print() {
		std::cout << "Rendering " << mFilePath << "\n";
	}
private:
	std::string mFilePath;

};
