#include "D3DTutException.h"
#include <sstream>

D3DTutException::D3DTutException(int line, const char* file) noexcept
	: line(line), file(file)
{
}

const char* D3DTutException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	
	whatBuffer = oss.str();

	return whatBuffer.c_str();
}

const char* D3DTutException::GetType() const noexcept
{
	return "D3D Tutorial Exception";
}

int D3DTutException::GetLine() const noexcept
{
	return line;
}

const std::string& D3DTutException::GetFile() const noexcept
{
	return file;
}

std::string D3DTutException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
