#pragma once
#include "CDS_SimpleHashMap.hpp"

CDS_SimpleHashMap::CDS_SimpleHashMap() : _N(26), _StartByte('a') {
  for (int i = 0; i < this->_N; i++) {
    this->_Slots[i] = this->p_State->NeverUsed;
  }
}

const std::array<std::string, 26> &CDS_SimpleHashMap::Slots() {
  return this->_Slots;
}

CDS_Result<std::string> CDS_SimpleHashMap::Get(std::string &key) {
  CDS_Result<size_t> index = this->_HashFunction(key);
  if (index.IsError())
    return CDS_Result<std::string>::Failure(index.ErrorMessage);

  size_t indexUnpacked = index.Unpack();
  for (int i = 0; i < this->_N; i++) {
    if (this->_Slots[indexUnpacked] == this->p_State->Tombstone ||
        this->_Slots[indexUnpacked] == this->p_State->Occupied) {
      indexUnpacked = (indexUnpacked + 1) % this->_N;
    } else if (this->_Slots[indexUnpacked] == this->p_State->NeverUsed) {
      return CDS_Result<std::string>::Failure("The key does not exist");
    } else {
      return CDS_Result<std::string>::Success(this->_Slots[indexUnpacked]);
    }
  }
  return CDS_Result<std::string>::Failure("The key does not exist");
}

CDS_Result<std::string> CDS_SimpleHashMap::Insert(std::string &key) {
  return CDS_Result<std::string>::Failure("Not Implemented");
}

CDS_Result<std::string> CDS_SimpleHashMap::Delete(std::string key) {
  return CDS_Result<std::string>::Failure("Not Implemented");
}

CDS_Result<size_t> CDS_SimpleHashMap::_HashFunction(std::string &key) {
  /*
   * In: Key as a string
   * Out: Index where to put value or error
   */
  size_t length = key.size();
  if (key.empty()) {
    return CDS_Result<size_t>::Failure("The key provided is empty");
  }

  byte lastByte = (byte)key.back();
  if (lastByte < 'a' || lastByte > 'z') {
    return CDS_Result<size_t>::Failure("The key is not hashable");
  }

  byte diffByte = lastByte - this->_StartByte;

  return CDS_Result<size_t>::Success((size_t)diffByte);
}
