#!/bin/bash

BUILD_DIR="build/deb"
NAME="sta-to-csv"
MAJOR=0
MINOR=1
PATCH=0
REV=1
ARCH="amd64"
DEB_PATH="$BUILD_DIR/$NAME"_"$MAJOR.$MINOR.$PATCH-$REV"_$ARCH
INSTALL_DIR="usr/local/bin"

sudo rm -rf "$BUILD_DIR"
mkdir -p "$DEB_PATH/$INSTALL_DIR"
cp -R deb/* "$DEB_PATH"
cp build/release/sta-to-csv "$DEB_PATH/$INSTALL_DIR"
#chmod -R 755 "$DEB_PATH"
#chmod a-x "$DEB_PATH/usr/share/doc/pkg/copyright"
#sudo chown -R root:root "$DEB_PATH"
#dpkg-deb --build "$DEB_PATH"
#lintian "$DEB_PATH".deb
