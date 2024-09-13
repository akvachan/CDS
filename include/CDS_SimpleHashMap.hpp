#pragma once
#include <array>
#include <memory>
#include <optional>
#include <string>

template <class T> struct CDS_Result {
  std::optional<T> Value;
  std::optional<std::string> ErrorMessage;

  static CDS_Result<T> Success(const T &value);

  static CDS_Result<T> Failure(const std::optional<std::string> &errorMessage);

  bool IsSucces();

  bool IsError(); 

  T &Unpack();
};

class CDS_SimpleHashMap {
  struct _State;
  std::shared_ptr<_State> p_State;
  using byte = unsigned char;

public:
  const std::array<std::string, 26> &Slots();

  CDS_SimpleHashMap();
  CDS_Result<std::string> Get(std::string &key);
  CDS_Result<std::string> Insert(std::string &key);
  CDS_Result<std::string> Delete(std::string key);

private:
  struct _State {
    const std::string NeverUsed = "never used";
    const std::string Occupied = "occupied";
    const std::string Tombstone = "tombstone";
  };

  std::array<std::string, 26> _Slots;
  const byte _StartByte;
  const size_t _N;

  CDS_Result<size_t> _HashFunction(std::string &key);
};

#include "CDS_SimpleHashMap.ipp"
