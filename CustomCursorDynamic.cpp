#include "CustomCursorDynamic.h"

PainterWrapper::PainterWrapper(QPainter &painter)
{
	this->painter = &painter;
}

void PainterWrapper::say_hello() 
{
	std::cout << "Hello from cpp" << std::endl;
}

void PainterWrapper::drawLine(int x1, int y1, int x2, int y2)
{
	painter->drawLine(x1, y1, x2, y2);
}

RectWrapper::RectWrapper(QRect &cursorRect) 
{
	this->cursorRect = &cursorRect;
}

int RectWrapper::top()
{
	return cursorRect->top();
}

int RectWrapper::bottom()
{
	return cursorRect->bottom();
}
int RectWrapper::left()
{
	return cursorRect->left();
}
int RectWrapper::right()
{
	return cursorRect->right();
}
