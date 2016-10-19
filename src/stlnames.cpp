#include <unordered_map.h>
#include "abs-macros.h"
#include "lib/sys.h"

// TODO: Profile, is std::unordered_map faster, or std::map?
constexpr std::unordered_map <std::string, stl_func> FUNCTION_NAMES =
    {
        "builtins.sys.workdir", sys::workdir
    };