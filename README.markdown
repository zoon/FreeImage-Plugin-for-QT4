FreeImage QT4 Plugin
=========
    Author & Contact : Andrew Zhilin <andrew_zhilin@yahoo.com>


Overview
--------

The FreeImagePlugin brings [FreeImage][1] functionality to the
[QT4][2].  For this plugin was planned mainly for extending
[p4merge][3], it is limited with reading-only capabilities.

With this plugin and p4merge you can diff almost any image format
supported by FreeImage, including among others PSD, TGA, JP2 and DDS.


Build
-----

Building plugin can be rather tricky: you should use the same
libraries, the same version of compiler, and most importantly exactly
the same ['buildkey'][4] as the host application.

Plugin prebuilt for p4merge for win32 will be attached

Installation
-----------

Just copy qfreeimage4.dll (or .so) to the plugins/imageformats. All
should just work.


License
-------
FreeImage QT4 Plugin released under the MIT License.


[1]: http://freeimage.sourceforge.net/
[2]: http://qt.nokia.com/
[3]: http://blog.perforce.com/blog/?p=1394
[4]: http://qt.nokia.com/doc/4.0/plugins-howto.html#the-build-key

