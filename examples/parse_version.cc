#include <array>
#include <iostream>

#include "stx/result.h"

using std::array, std::string_view;
using stx::Result, stx::Ok, stx::Err;
using namespace std::literals;

enum class Version { Version1 = 1, Version2 = 2, Unknown };

Result<Version, string_view> parse_version(array<uint8_t, 6> const& header) {
  switch (header.at(0)) {
    case 1:
      return Ok(Version::Version1);
    case 2:
      return Ok(Version::Version2);
    default:
      return Err("Unknown Version"sv);
  }
}

int main() {
  auto version = parse_version({2, 3, 4, 5, 6, 7}).unwrap_or(Version::Unknown);
}
