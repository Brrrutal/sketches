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

void LuaScript::Register(
        const char* pMetatableName, 
        const char* pModuleName, 
        const luaL_Reg* pFunctionTable,
        const luaL_Reg* pMetaFunctionTable)
{
    luaL_newmetatable(m_pScriptEnv, pMetatableName);
    lua_pushvalue(m_pScriptEnv, STACK_TOP);
    lua_setfield(m_pScriptEnv, STACK_TOP - 1, "__index");
    luaL_register(m_pScriptEnv, NULL, pMetaFunctionTable);
    luaL_register(m_pScriptEnv, pModuleName, pFunctionTable);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void LuaScript::AddGlobalObject(const char* objectName, void* pObject)
{
    lua_pushlightuserdata(m_pScriptEnv, pObject);
    lua_setglobal(m_pScriptEnv, objectName);
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
