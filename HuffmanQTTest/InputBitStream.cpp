#include "string"
#include "InputBitStream.h"
#include "fstream"

using namespace std;

InputBitStream::~InputBitStream()
{
    if(_inputStream != nullptr)
    {
        _inputStream->close();
        delete _inputStream;
    }
	delete _inputStream;
}

InputBitStream::InputBitStream(std::string str)
{
	eof = false;
	if (_inputStream == nullptr)
	{
		_inputStream = new ifstream();
	}
	_inputStream->open(str);
}

//Reading bit
int InputBitStream::Read()
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
			if (ReadByte() != 0) //Reading the next Byte
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

/*Reads the next byte from the Byte stream
(Remember that we are using implementation of ByteStream when reading bits)	*/
bool InputBitStream::ReadByte()
{
	if (!_inputStream->eof())
	{
		*_inputStream >> _currentByte;
		if (_inputStream->eof())
			eof = true;
		return true;
	}
	else
	{
		eof = true;
		return false;
	}
}

//Exctracting the pending bit from the current byte
int InputBitStream::NextBit()
{
	return (_currentByte >> _bitsPending--) & 1;
}


char InputBitStream::ReturnByte()
{
	return _currentByte;
}
