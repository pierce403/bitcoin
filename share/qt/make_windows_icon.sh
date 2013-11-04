#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/hydracoin.png
ICON_DST=../../src/qt/res/icons/hydracoin.ico
convert ${ICON_SRC} -resize 16x16 hydracoin-16.png
convert ${ICON_SRC} -resize 32x32 hydracoin-32.png
convert ${ICON_SRC} -resize 48x48 hydracoin-48.png
convert hydracoin-16.png hydracoin-32.png hydracoin-48.png ${ICON_DST}

