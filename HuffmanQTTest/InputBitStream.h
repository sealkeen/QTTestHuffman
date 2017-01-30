#ifndef INPUTBITSTREAM_H
#define INPUTBITSTREAM_H

#include <fstream>

using std::ifstream;

class InputBitStream
{
private :
	int NextBit();
	char _currentByte;
	int _bitsPending { 7 };
	bool _endOfByte { true };
public :
	InputBitStream(std::string str);
	int Read();
	bool ReadByte();
	char ReturnByte();
	~InputBitStream();
	ifstream *_inputStream = nullptr;
	bool eof {false};
};
#endif // INPUTBITSTREAM_H