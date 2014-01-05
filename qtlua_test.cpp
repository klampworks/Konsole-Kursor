#include <QtLua/State>
#include <QtLua/Value>
#include <QtCore>
#include <QDialog>
#include <QApplication>


int main() {

	QApplication app(0, NULL);

	QtLua::State state;
	state.openlib(QtLua::AllLibs);
	QFile file("hello_world.lua");

	QDialog *hello = new QDialog();

	//Nice...
	state["my_string"] = hello;

	file.open(QIODevice::ReadOnly);

	state.exec_chunk(file);
	//state.exec_statements("my_string:show()");
	
	return app.exec();
}
