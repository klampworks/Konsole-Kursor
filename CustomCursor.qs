//latin_cross();
//painter.drawChar("Kochi Gothic", 12363);
painter.drawDistroLogo(120);

function latin_cross() 
{
	var axis;

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
