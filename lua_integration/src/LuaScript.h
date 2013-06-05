#pragma once

#include <lua/lua.hpp>

class LuaScript
{
public:
    LuaScript();
    ~LuaScript();

    void Run(const char* pScriptName);

private:
    void Error();

    lua_State* m_pScriptEnv; 
};

