#ifndef CUSTOMCURSOR_HPP
#define CUSTOMCURSOR_HPP

namespace CustomCursor {

	void latin_cross(QPainter&, const QRect&);
	void chara(QPainter&, const QRect&, const char*, const QString&);

	inline void draw_cursor(QPainter &painter, const QRect &cursorRect) {

		//latin_cross(painter, cursorRect);
		chara(painter, cursorRect, NULL, "A");
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

	inline void chara(QPainter &painter, const QRect &cursorRect, 
		const char *family, const QString &to_paint) {

		QFont font = painter.font();

		/* Save the original font family. */
		QString old_family = font.family();
		bool same_family;

		/* If the new family is different then set it. */
		if (same_family = (family && family != old_family))
			font.setFamily(family);

		painter.drawText(cursorRect, Qt::AlignCenter, to_paint);

		/* Restore the original font. */
		if (!same_family) {
			font.setFamily(old_family);
			painter.setFont(font);
		}
	}
}
#endif
