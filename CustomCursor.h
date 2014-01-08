#ifndef CUSTOMCURSOR_HPP
#define CUSTOMCURSOR_HPP

namespace CustomCursor {

	void latin_cross(QPainter&, const QRect&);

	inline void draw_cursor(QPainter &painter, const QRect &cursorRect) {

		latin_cross(painter, cursorRect);
	}

	inline void latin_cross(QPainter &painter, const QRect &cursorRect) {

		int axis;

		/* Find the horizontal centre of the drawing area. */
		axis = cursorRect.left() + ((cursorRect.right() - cursorRect.left()) / 2);

		/* Draw a vertial line alone the given axis. */
		painter.drawLine(axis,
			cursorRect.top(),
			axis,
			cursorRect.bottom());

		/* Find the point 30% from the top. */
		axis = cursorRect.top() + ((cursorRect.bottom() - cursorRect.top()) / 3);

		/* Draw a horizontal line along the given axis. */
		painter.drawLine(cursorRect.left(),
			axis,
			cursorRect.right(),
			axis);
	}
}
#endif
