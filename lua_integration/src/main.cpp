#include <iostream>

#include "LuaScript.h"

int main()
{
    LuaScript lua;
    lua.Run("lua/test.lua");
    char key;
    std::cin >> key;
    return 0;
}