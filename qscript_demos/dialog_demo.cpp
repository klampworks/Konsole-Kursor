#include <QtCore>
#include <QDialog>
#include <QApplication>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>
 #include <QFile>
 #include <iostream>

struct my_obj : public QObject {

	void show() {
		std::cout << "Hello from cpp." << std::endl;
		}
	
};

int main()
{

	my_obj obj;

	QApplication app(0, NULL);

	QDialog cpp_dialog;

	QScriptEngine engine;


	QScriptValue js_dialog = engine.newQObject(&obj);
        engine.globalObject().setProperty("js_dialog", js_dialog);

	QString script_file_name("qdialog_demo.js");
	QFile script_file(script_file_name);
	script_file.open(QIODevice::ReadOnly);
	engine.evaluate(script_file.readAll(), script_file_name);
	script_file.close();

	return app.exec();
}
