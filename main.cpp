#include "CDS_List.hpp"

int main() {
  // Example usage
  CDS_List<std::string> myStrings;
  myStrings.Append("Hello");
  myStrings.Append("World");
  myStrings.Pop();
  std::cout << myStrings << '\n'; // -> [Hello]
}
