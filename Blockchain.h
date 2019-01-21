#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
    public:
        // Constructor
        Blockchain();

        // Public Functions
        void AddBlock(Block bNew);

    private:

        // Private Variables
        uint32_t _nDifficulty;
        vector<Block> _vChain;

        // Private Functions
        Block _GetLastBlock() const;
};

