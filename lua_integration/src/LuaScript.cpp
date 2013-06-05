#include "LuaScript.h"

#include <iostream>

namespace
{
const int STACK_TOP = -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

LuaScript::LuaScript() :
    m_pScriptEnv(0)
{
    m_pScriptEnv = luaL_newstate();
    luaL_openlibs(m_pScriptEnv);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

LuaScript::~LuaScript()
{
    if (m_pScriptEnv != 0)
    {
        lua_close(m_pScriptEnv);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void LuaScript::Run(const char* pScriptName)
{
    if (luaL_loadfile(m_pScriptEnv, pScriptName) || lua_pcall(m_pScriptEnv, 0, 0, 0))
    {
        Error();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void LuaScript::Error()
{
    std::cerr << "Error: " << lua_tostring(m_pScriptEnv, STACK_TOP) << std::endl;
    lua_pop(m_pScriptEnv, 1);
}
