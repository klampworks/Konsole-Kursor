#include <QObject>
#include <iostream>

class my_obj : public QObject {

	Q_OBJECT

	public slots:
		void show() {
			std::cout << "Hello from cpp." << std::endl;
		}
};
