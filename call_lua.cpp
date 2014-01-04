extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}

#include <iostream>

int main() {

	lua_State *L = lua_open();
	luaL_openlibs(L);   
	luaL_loadfile(L, "hello_world.lua");
	lua_pcall(L, 0, 0, 0);

	lua_getglobal(L, "square");
	lua_pushnumber(L, 6);
	lua_pcall(L, 1, 1, 0);

	int result = lua_tonumber(L, -1);
	std::cout << "Returned " << result << std::endl;
}
