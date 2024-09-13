#pragma once
#include "CDS_SimpleHashMap.hpp"
#include <array>
#include <memory>
#include <optional>
#include <string>

template <class T> CDS_Result<T> CDS_Result<T>::Success(const T &value) {
  return CDS_Result<T>{value, {}};
}

template <class T> CDS_Result<T> CDS_Result<T>::Failure(const std::optional<std::string> &errorMessage) {
  return CDS_Result<T>{{}, errorMessage};
}

template <class T> bool CDS_Result<T>::IsSucces() {
  return !this->ErrorMessage.has_value();
}

template <class T> bool CDS_Result<T>::IsError() {
  return this->ErrorMessage.has_value();
}

template <class T> T &CDS_Result<T>::Unpack() { 
  return this->Value.value(); 
}
