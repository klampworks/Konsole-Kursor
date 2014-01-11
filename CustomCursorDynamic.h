#ifndef CUSTOMCURSORDYNAMIC_H
#define CUSTOMCURSORDYNAMIC_H
#include <QObject>
#include <QPainter>
#include <QRect>
#include <iostream>

class PainterWrapper : public QObject {

	Q_OBJECT

	QPainter *painter;
	QRect *cursorRect;

	public:
		PainterWrapper(QPainter &painter, QRect &cursorRect);

	public slots:
		void drawLine(int x1, int y1, int x2, int y2);
		void drawChar(QString family, QString to_paint);
		void drawChar(QString family, int to_paint);
		void drawDistroLogo(int distro);
		void say_hello();
};

class RectWrapper : public QObject {

	Q_OBJECT

	QRect *cursorRect;

	public:
		RectWrapper(QRect &);

	public slots:
		int top();
		int bottom();
		int left();
		int right();

};
#endif
