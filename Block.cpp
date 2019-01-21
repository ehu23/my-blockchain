#include "Block.h"
#include "sha256.h"

// Block Constructor using initializer list
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1; // A default value for _nNonce
    _tTime = time(nullptr); // stores current time into _tTime
}

// Accessor to get the block's hash
string Block::GetHash() {
    return _sHash;
}

// Mine Block Function
void Block::MineBlock(uint32_t nDifficulty) {
    // Make a string with nDifficulty leading zeroes
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; i++) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    string str(cstr);

    // Hash until the hash has as much leading zeroes as nDifficulty
    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl;
}

// Calculate Hash, returns it as a string
// 'inline' makes it more efficient whenever its called
inline string Block::_CalculateHash() const {
    stringstream ss; // all the inputs combined together that we want a hash of
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}
