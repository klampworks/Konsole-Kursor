#include <QtLua/State>
#include <QtCore>

int main() {

	QtLua::State state;
	state.openlib(QtLua::AllLibs);
	QFile file("hello_world.lua");

	file.open(QIODevice::ReadOnly);

	state.exec_chunk(file);
}
