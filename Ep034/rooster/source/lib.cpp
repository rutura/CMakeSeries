#include "lib.hpp"

#include <fmt/core.h>

library::library()
    : name {fmt::format("{}", "rooster")}
{
}

void library::print_message(const std::string& message) const
{
  fmt::print("{}\n", message);
}
