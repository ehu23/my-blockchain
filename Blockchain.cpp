#include "Blockchain.h"

// Blockchain constructor
Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block")); // Default creation of Genesis Block. emplace_back is essentially push_back
    _nDifficulty = 4; // lower the difficulty, easier to create a block
}

// Function to add a block to the blockchain
void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

// Access last block in chain
Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}

