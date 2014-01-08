print("hello world")

--QDialog works because it inherits from QObject
--(From QtLua) Value & operator=(QObject *obj);
--lua_dialog:show()

--QRect and QPainter on the other hand are not QObject children.
--
--libqtlua-1.4 forced them through as QVariant but Lua could not
--dereferece the pointer into anything useful.
--
--libqtlua-2.0 will not allow QPainter or QRect to be assigned to
--a Lua value in the first place.
--
--print(cursorRect:left())
--painter:drawLine(100, 100, 200, 200)
