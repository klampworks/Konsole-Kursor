#include <QtLua/State>
#include <QtLua/Value>
#include <QtCore>
#include <QDialog>
#include <QApplication>

void call_lua(const QtLua::State &state, const char *filename)
{
	QFile file(filename);

	/* Open the Lua script file. */
	file.open(QIODevice::ReadOnly);

	/* Execute the contents. */
	state.exec_chunk(file);
	
	/* Close the file. */
	file.close();
}

int main()
{
	QApplication app(0, NULL);

	QtLua::State state;
	state.openlib(QtLua::AllLibs);

	QDialog *cpp_dialog = new QDialog();

	/* Pass the QDialog pointer to the Lua state. */
	state["lua_dialog"] = cpp_dialog;

	call_lua(state, "dialog_demo.lua");
	
	return app.exec();
}
