Konsole-Kursor
==============

An extension for KDE Konsole to facilitate the drawing of arbitrary cursor shapes.

This project provides two alternative ways of achieving this: a static patch and a dynamic patch.

Static patch
=

This will add an extra "Custom (static)" option to the cursor selection combobox in the profile settings dialogue. When this option is selected, the painting code will call a method in a separate source file. This file is where the user will add their custom drawing code using QPainter.

This approach introduces the least overhead (if any at all assuming the function is inlined) however, any changes to the painting code will require konsole to be recompiled.

Dynamic patch
=
This will add an extra "Custom (dynamic)" option to the cursor selection combobox in the profile settings dialogue. When this option is selected, the painting code will read in a script file and interpret the contents. The first language to be supported will be Lua. Konsole's QPainter object will be exposed to the scripting interface like it is with the static patch so the same painting logic will work for both approaches. 

This approach introduces considerable overhead but it also means that konsole does not need to be recompiled or even restarted when the painting code is changed. This is ideal for experimenting with  ideals before committing a final design to the static approach.

No releases yet as this is a work in progress. 
