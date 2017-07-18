#include "Information.h"



Information * Information::GetInstanceOfInfo()
{
    static Information info;
    return & info;
}