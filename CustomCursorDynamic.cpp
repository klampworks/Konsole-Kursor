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
	std::cout << "Hello from cpp" << std::endl;
}
