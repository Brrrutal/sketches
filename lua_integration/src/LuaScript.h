#pragma once

#include <lua/lua.hpp>

class LuaScript
{
public:
    LuaScript();
    ~LuaScript();

    void Register(
            const char* pMetatableName, 
            const char* pModuleName, 
            const luaL_Reg* pFunctionTable,
            const luaL_Reg* pMetaFunctionTable);

    void AddGlobalObject(const char* objectName, void* object);
    void Run(const char* pScriptName);

private:
    void Error();

    lua_State* m_pScriptEnv; 
};

