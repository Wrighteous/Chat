#include <string>
#include "utils.h"

const char* convert_to_cstring(QString s)
{
    return s.toStdString().c_str();
}
