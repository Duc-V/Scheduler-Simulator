#ifndef TYPE_H
#define TYPE_H

#pragma once
#include <string>

namespace osp2023 {
    // Renaming some types so that the types are more meaningful
    using time_type = long long;
    using id_type = int;

    // Declare the constant as extern (do not initialize it here)
    static time_type time_not_set = -1;
}
#endif