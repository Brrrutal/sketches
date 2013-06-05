#include <iostream>
#include <vector>

#include "LuaScript.h"

namespace
{

struct List_lua
{
    std::vector<int>* m_pValues;
};

int List_new(lua_State* pState)
{
    List_lua* pList = (List_lua*)lua_newuserdata(pState, sizeof(List_lua));

    std::vector<int>* pVector = reinterpret_cast<std::vector<int>*>(lua_touserdata(pState, 1));
    pList->m_pValues = pVector;

    luaL_getmetatable(pState, "Meta.vector");
    lua_setmetatable(pState, -2);

    return 1;
}

List_lua* List_check(lua_State* pState)
{
    return (List_lua*)luaL_checkudata(pState, 1, "Meta.vector");
}

int List_reserve(lua_State* pState)
{
    List_lua* pList = List_check(pState);
    int newSize = luaL_checkint(pState, 2);

    pList->m_pValues->reserve(newSize);
    return 0;
}

int List_push_back(lua_State* pState)
{
    List_lua* pList = List_check(pState);
    int newValue = luaL_checkint(pState, 2);

    pList->m_pValues->push_back(newValue);
    return 0;
}

int List_size(lua_State* pState)
{
    List_lua* pList = List_check(pState);
    lua_pushnumber(pState, pList->m_pValues->size());
    return 1;
}

static const luaL_Reg List_functions[] = 
{
    {"new", List_new },
    {NULL, NULL}
};

static const luaL_Reg List_metafunctions[] = 
{
    {"reserve", List_reserve},
    {"push_back", List_push_back},
    {"size", List_size},
    {NULL, NULL}
};

}

int main()
{
    std::vector<int> ints;
    LuaScript lua;
    lua.Register("Meta.vector", "vector", List_functions, List_metafunctions);
    lua.AddGlobalObject("cVector", &ints);
    lua.Run("lua/test.lua");
    char key;
    std::cin >> key;
    return 0;
}