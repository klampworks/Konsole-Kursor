#ifndef CUSTOMCURSOR_HPP
#define CUSTOMCURSOR_HPP

namespace CustomCursor {

	inline void draw_cursor(QPainter &painter, const QRect &cursorRect) {

		int centre = cursorRect.left() + ((cursorRect.right() - cursorRect.left()) / 2);
		painter.drawLine(centre,
			cursorRect.top(),
			centre,
			cursorRect.bottom());

		centre = cursorRect.top() + ((cursorRect.bottom() - cursorRect.top()) / 3);

		painter.drawLine(cursorRect.left(),
			centre,
			cursorRect.right(),
			centre);
	}
}
#endif
