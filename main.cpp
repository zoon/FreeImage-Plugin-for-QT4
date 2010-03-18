// Copyright (C) 2010 by Andrew Zhilin <andrew_zhilin@yahoo.com>

#include <qimageiohandler.h>
#include "freeimageplugin_global.h"
#include "FreeImageHandler.h"


class FreeImagePlugin : public QImageIOPlugin
{
public:
    FreeImagePlugin();
    ~FreeImagePlugin();

    QStringList keys() const;
    Capabilities capabilities(QIODevice *device,const QByteArray &format) const;
    QImageIOHandler *create(QIODevice *device, const QByteArray &format = QByteArray()) const;
};

FreeImagePlugin::FreeImagePlugin()
{
}

FreeImagePlugin::~FreeImagePlugin()
{
}

QStringList FreeImagePlugin::keys() const
{
    // NOTE: "psd" just because an empty list not OK here. We support
    // all FreeImage formats.
    return QStringList("psd");
}


QImageIOPlugin::Capabilities FreeImagePlugin::capabilities(QIODevice *device, const QByteArray &format) const
{
    FREE_IMAGE_FORMAT fif = FreeImageHandler::GetFIF(device,format);
    if (device->isReadable() && FreeImage_FIFSupportsReading(fif))
        return Capabilities(CanRead);
    return 0;
}

QImageIOHandler *FreeImagePlugin::create(QIODevice *device, const QByteArray &format) const
{
    QImageIOHandler *handler = new FreeImageHandler;
    handler->setDevice(device);
    handler->setFormat(format);
    return handler;
}

Q_EXPORT_STATIC_PLUGIN(FreeImagePlugin)
Q_EXPORT_PLUGIN2(freeimageplugin, FreeImagePlugin)
