#ifndef OUTPUTBITSTREAM_H
#define OUTPUTBITSTREAM_H

#include <fstream>

using std::ofstream;

//A stream where bits can be written to. Written to an underlying byte stream.
class OutputBitStream {

public:
    /* Con/De-structors */

    //Constructs a stream based on the specified byte output stream.
	OutputBitStream(ofstream* out);

    //Constructs a stream based on the file name.
	OutputBitStream(std::string str);

    ~OutputBitStream();
	/* Methods */

    //Writes a bit.
    void OutputBitStream::Write(int b);

    //Closes this stream and the underlying output stream. If called when this
    //bit stream is not at a byte boundary, then the minimum number of "0" bits
    //(between 0 and 7 of them) are written as padding to reach the next byte boundary.
	void OutputBitStream::Close();

private:
	/* Fields */
	// The underlying byte stream to write to (not null).
	ofstream* _outputStream = nullptr;
	// The accumulated bits for the current byte, always in the range [0x00, 0xFF].
	char currentByte;
	// Number of accumulated bits in the current byte, always between 0 and 7 (inclusive).
	int numBitsFilled;
};

#endif //OUTPUTBITSTREAM_H