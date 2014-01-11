#ifndef CUSTOMCURSORDYNAMIC_H
#define CUSTOMCURSORDYNAMIC_H
#include <QObject>
#include <QPainter>
#include <QRect>
#include <iostream>

class PainterWrapper : public QObject {

	Q_OBJECT

	QPainter *painter;

	public:
		PainterWrapper(QPainter &painter);

	public slots:
		void drawLine(int x1, int y1, int x2, int y2);
		void say_hello();
};

class RectWrapper : public QObject {

	Q_OBJECT

	QRect *cursorRect;

	public:
		RectWrapper(QRect &);

	public slots:
		int top();

};
#endif
