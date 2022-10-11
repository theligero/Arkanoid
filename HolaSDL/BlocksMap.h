#ifndef BLOCKSMAP_H_
#define BLOCKSMAP_H_

#include "Block.h"

class BlocksMap
{
private:
	Block** blq;
	int blockSize;
public:
	BlocksMap(int blockSize, int size) : blq(new Block*[size]), blockSize(blockSize) {} // provisional
};

#endif 