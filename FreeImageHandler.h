// Copyright (C) 2010 by Andrew Zhilin <andrew_zhilin@yahoo.com>

#ifndef FREEIMAGEHANDLER_Z131718_H
#define FREEIMAGEHANDLER_Z131718_H

#include "freeimageplugin_global.h"
#include <QtGui/QImageIOHandler>
#include <QtGui/QImage>
#include <QDebug>

#include <FreeImage.h>

QT_BEGIN_NAMESPACE

class FreeImageHandler : public QImageIOHandler
{
public:
    FreeImageHandler();
    virtual ~FreeImageHandler();
    bool canRead() const;
    bool read(QImage *image);

    QByteArray name() const;

    QVariant option(ImageOption option) const;

    void setOption(ImageOption option, const QVariant &value);

    bool supportsOption(ImageOption option) const;

public:
    static FreeImageIO& fiio();
    static FREE_IMAGE_FORMAT GetFIF(QIODevice *device, const QByteArray& fmt);    

private:
    static QImage& QImageNone();
    static bool IsQImageNone(const QImage& qi);
    static QVector<QRgb>& PaletteNone();
    static bool IsPaletteNone(const QVector<QRgb> &pal);
    static QImage FIBitmapToQImage(FIBITMAP *dib);
    static QVector<QRgb> GetPalette(FIBITMAP *dib);
};




QT_END_NAMESPACE

#endif // FREEIMAGEHANDLER_Z131718_H
