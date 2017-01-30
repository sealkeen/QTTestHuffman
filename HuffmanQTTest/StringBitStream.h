#ifndef STRINGBITSTREAM_H
#define STRINGBITSTREAM_H

#include <sstream>
#include <string>

using std::stringstream;

class StringBitStream
{
private :
	// Number of unfilled bits in the current byte, always between 0 and 7 (inclusive). 
	int _bitsPending { 7 };

	// Number of accumulated bits in the current byte, always between 0 and 7 (inclusive).
	int _numBitsFilled;

	bool _endOfByte{ true };
	char _currentByte;

	int NextBit();
public :
	// Accumulates a bit in the stream until the entire byte is filled.
	void Write(bool b);

	// Closes this stream and the underlying output stream.
	void Close();

	stringstream *_inputStream {nullptr};
	std::string _outputStream;
	StringBitStream(std::string str);
	void Write(int ch);
	int Read();
	bool ReadByte();
	char ReturnByte();
	~StringBitStream();
	bool eof {false};
	void Refresh();
};

#endif // !STRINGBITSTREAM_H
