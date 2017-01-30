
#include "OutputBitStream.h"

OutputBitStream::OutputBitStream(ofstream* out) {
	_outputStream = out;
	currentByte = 0;
	numBitsFilled = 0;
}

void OutputBitStream::Close() {
	while (numBitsFilled != 0)
		Write(0);
	_outputStream->close();
}

void OutputBitStream::Write(int b) {
	if (b != 0 && b != 1)
		throw ("Argument must be 0 or 1");
	currentByte = (currentByte << 1) | b;
	numBitsFilled++;
	if (numBitsFilled == 8) {
		*_outputStream << (currentByte);
		currentByte = 0;
		numBitsFilled = 0;
	}
}

OutputBitStream::~OutputBitStream()
{
	_outputStream->close();
	delete _outputStream;
}

OutputBitStream::OutputBitStream(std::string str)
{
	numBitsFilled = 0;
	currentByte = 0;
	if (_outputStream == nullptr)
	{
		_outputStream = new ofstream();
	}
	_outputStream->open(str);
}
