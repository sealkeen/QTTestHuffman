#ifndef STRINGBITSTREAM_CPP
#define STRINGBITSTREAM_CPP

#include "StringBitStream.h"
#include "string"
#include "sstream"

using namespace std;

StringBitStream::~StringBitStream()
{
	if (_inputStream != nullptr)
	{
		delete _inputStream;
	}
	//if (_outputStream != nullptr)
	//{
	//	delete _outputStream;
	//}
}

StringBitStream::StringBitStream(std::string str)
{
	eof = false;
	if (_inputStream == nullptr)
	{
		_inputStream = new stringstream(str);
	}
	_outputStream = "";
	//if (_outputStream == nullptr)
	//{
	//	//_outputStream = new stringstream("");	
	_numBitsFilled = 0;
	_bitsPending = 8;
	_currentByte = 0;
	//}
}

//Reading bit
int StringBitStream::Read()
{
	if (!eof) {
		if (!_endOfByte) // If we have not read the whole byte which is in memory
		{
			if (_bitsPending >= 0)
				return NextBit();
			else
			{
				_endOfByte = true;
				Read();
			}
		}
		else
		{
			if (ReadByte() != 0) //Reading the next char
			{
				_endOfByte = false;
				_bitsPending = 7;
				Read();
			}
			else
			{
				eof = true;
				return -1;
			}
		}
	}
	else { return -1; }
}

/*Reads the next character from the string stream
(Remember that we are using implementation of StringStream when reading bits)	*/
bool StringBitStream::ReadByte()
{
	if (!_inputStream->eof())
	{
		*_inputStream >> _currentByte;
		if (_inputStream->eof()) {
			eof = true; 
			return false;
		}
		return true;
	}
	else
	{
		eof = true;
		return false;
	}
}

//Exctracting the pending bit from the current byte
int StringBitStream::NextBit()
{
	return (_currentByte >> _bitsPending--) & 1;
}


char StringBitStream::ReturnByte()
{
	return _currentByte;
}

void StringBitStream::Close() {
	while (_numBitsFilled != 0)
		Write(0);
}
//#include "iostream"
void StringBitStream::Write(int b) {
	if (b != 0 && b != 1)
		throw ("Argument must be 0 or 1");
	_currentByte = (_currentByte << 1) | b;
	_numBitsFilled++;
	if (_numBitsFilled == 8) {
		_outputStream += (_currentByte);
		//std::string str;*_outputStream << str;
		//*_outputStream >> str;
		// cout << "QQQQQQQQ"<< str  << "QQQQQQQQ";
		_currentByte = 0;
		_numBitsFilled = 0;
	}
}

void StringBitStream::Refresh()
{
	_currentByte = '\0';
	_numBitsFilled = 0;
}

#endif // !STRINGBITSTREAM_H


//Debug
//StringBitStream *sBS = new StringBitStream("");
//sBS->Write(0); sBS->Write(1); sBS->Write(0); sBS->Write(0); sBS->Write(0); sBS->Write(1); sBS->Write(1); sBS->Write(0);
//sBS->Write(0); sBS->Write(0); sBS->Write(1); sBS->Write(0); sBS->Write(0); sBS->Write(1); sBS->Write(1); sBS->Write(0);
//std::string strg;
//*sBS->_stringStream >> strg;
//cout << strg << endl;
//cout << (int)'F' << endl;
//return 0;