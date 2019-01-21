#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Block {
    public:

        // Constructor
        Block(uint32_t nIndexIn, const string& sDataIn);

        // Public Methods
        string GetHash();

        void MineBlock(uint32_t nDifficulty);

        // Public Variables
        string sPrevHash;

    private:

        // Private Variables
        uint32_t _nIndex;
        int64_t _nNonce;
        string _sData;
        string _sHash;
        time_t _tTime;

        // Private Functions
        string _CalculateHash() const;
};

