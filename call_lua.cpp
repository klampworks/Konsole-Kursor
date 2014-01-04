extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}

int main() {

	lua_State *L = lua_open();
	luaL_openlibs(L);   
	luaL_loadfile(L, "hello_world.lua");
	lua_pcall(L, 0, 0, 0);
	lua_getglobal(L, "hello");
	lua_pcall(L, 0, 0, 0);
}
