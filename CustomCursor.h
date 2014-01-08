#ifndef CUSTOMCURSOR_HPP
#define CUSTOMCURSOR_HPP

namespace CustomCursor {

	/* Enum for mapping distros to ascii codes for the 
	 * ConkySymbols font family. */
	enum distro {
		tux = 'a',
		tux_inv = 'A',
		ubuntu = 'o',
		ubuntu_inv = 'O',
		suse = 'p',
		suse_inv = 'P',
		redhat = 'q',
		redhat_inv = 'Q',
		fedora = 'r',
		fedora_inv = 'R',
		debian = 's',
		debian_inv = 'S',
		arch = 't',
		arch_inv = 'T',
		mint = 'u',
		mint_inv = 'U',
		mandriva = 'v',
		mandriva_inv = 'V',
		noidea = 'w',
		noidea_inv = 'W',
		gentoo = 'x',
		gentoo_inv = 'X',
		FreeBSD = 'y',
		FreeBSD_inv = 'Y',
		pardus = 'z',
		pardus_inv = 'Z'
	};

	void latin_cross(QPainter&, const QRect&);
	void chara(QPainter&, const QRect&, const char*, const QString&);
	void distro_logo(QPainter&, const QRect&, distro d);

	inline void draw_cursor(QPainter &painter, const QRect &cursorRect) {

		//latin_cross(painter, cursorRect);
	//	chara(painter, cursorRect, "Kochi Gothic", QString("\u304B"));
		chara(painter, cursorRect, "Kochi Gothic", QChar(12363));
		//distro_logo(painter, cursorRect, gentoo);
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
		if (same_family = (family && family != old_family)) {
			font.setFamily(family);
			painter.setFont(font);
		}

		painter.drawText(cursorRect, Qt::AlignLeft, to_paint);

		/* Restore the original font. */
		if (!same_family) {
			font.setFamily(old_family);
			painter.setFont(font);
		}
	}

	inline void distro_logo(QPainter &painter, const QRect &cursorRect, 
		distro d) {

		chara(painter, cursorRect, "ConkySymbols", QString(d));
	}

}
#endif
