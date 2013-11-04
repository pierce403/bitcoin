Release Process
====================

* update translations (ping wumpus, Diapolo or tcatm on IRC)
* see https://github.com/hydracoin/hydracoin/blob/master/doc/translation_process.md#syncing-with-transifex

* * *

###update (commit) version in sources


	hydracoin-qt.pro
	contrib/verifysfbinaries/verify.sh
	doc/README*
	share/setup.nsi
	src/clientversion.h (change CLIENT_VERSION_IS_RELEASE to true)

###tag version in git

	git tag -a v(new version, e.g. 0.8.0)

###write release notes. git shortlog helps a lot, for example:

	git shortlog --no-merges v(current version, e.g. 0.7.2)..v(new version, e.g. 0.8.0)

* * *

##perform gitian builds

 From a directory containing the hydracoin source, gitian-builder and gitian.sigs
  
	export SIGNER=(your gitian key, ie bluematt, sipa, etc)
	export VERSION=(new version, e.g. 0.8.0)
	pushd ./hydracoin
	git checkout v${VERSION}
	popd
	pushd ./gitian-builder

 Fetch and build inputs: (first time, or when dependency versions change)

	mkdir -p inputs; cd inputs/
	wget 'http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.6.tar.gz' -O miniupnpc-1.6.tar.gz
	wget 'https://www.openssl.org/source/openssl-1.0.1c.tar.gz'
	wget 'http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz'
	wget 'ftp://ftp.simplesystems.org/pub/libpng/png/src/history/zlib/zlib-1.2.6.tar.gz'
	wget 'ftp://ftp.simplesystems.org/pub/libpng/png/src/history/libpng15/libpng-1.5.9.tar.gz'
	wget 'https://fukuchi.org/works/qrencode/qrencode-3.2.0.tar.bz2'
	wget 'https://downloads.sourceforge.net/project/boost/boost/1.54.0/boost_1_54_0.tar.bz2'
	wget 'https://svn.boost.org/trac/boost/raw-attachment/ticket/7262/boost-mingw.patch' -O \ 
	     boost-mingw-gas-cross-compile-2013-03-03.patch
	wget 'https://download.qt-project.org/archive/qt/4.8/4.8.3/qt-everywhere-opensource-src-4.8.3.tar.gz'
	wget 'https://protobuf.googlecode.com/files/protobuf-2.5.0.tar.bz2'
	cd ..
	./bin/gbuild ../hydracoin/contrib/gitian-descriptors/boost-win32.yml
	mv build/out/boost-win32-*.zip inputs/
	./bin/gbuild ../hydracoin/contrib/gitian-descriptors/deps-win32.yml
	mv build/out/hydracoin-deps-*.zip inputs/
	./bin/gbuild ../hydracoin/contrib/gitian-descriptors/qt-win32.yml
	mv build/out/qt-win32-*.zip inputs/
	./bin/gbuild ../hydracoin/contrib/gitian-descriptors/protobuf-win32.yml
	mv build/out/protobuf-win32-*.zip inputs/

 Build hydracoind and hydracoin-qt on Linux32, Linux64, and Win32:
  
	./bin/gbuild --commit hydracoin=v${VERSION} ../hydracoin/contrib/gitian-descriptors/gitian.yml
	./bin/gsign --signer $SIGNER --release ${VERSION} --destination ../gitian.sigs/ ../hydracoin/contrib/gitian-descriptors/gitian.yml
	pushd build/out
	zip -r hydracoin-${VERSION}-linux-gitian.zip *
	mv hydracoin-${VERSION}-linux-gitian.zip ../../../
	popd
	./bin/gbuild --commit hydracoin=v${VERSION} ../hydracoin/contrib/gitian-descriptors/gitian-win32.yml
	./bin/gsign --signer $SIGNER --release ${VERSION}-win32 --destination ../gitian.sigs/ ../hydracoin/contrib/gitian-descriptors/gitian-win32.yml
	pushd build/out
	zip -r hydracoin-${VERSION}-win32-gitian.zip *
	mv hydracoin-${VERSION}-win32-gitian.zip ../../../
	popd
	popd

  Build output expected:

  1. linux 32-bit and 64-bit binaries + source (hydracoin-${VERSION}-linux-gitian.zip)
  2. windows 32-bit binary, installer + source (hydracoin-${VERSION}-win32-gitian.zip)
  3. Gitian signatures (in gitian.sigs/${VERSION}[-win32]/(your gitian key)/

repackage gitian builds for release as stand-alone zip/tar/installer exe

**Linux .tar.gz:**

	unzip hydracoin-${VERSION}-linux-gitian.zip -d hydracoin-${VERSION}-linux
	tar czvf hydracoin-${VERSION}-linux.tar.gz hydracoin-${VERSION}-linux
	rm -rf hydracoin-${VERSION}-linux

**Windows .zip and setup.exe:**

	unzip hydracoin-${VERSION}-win32-gitian.zip -d hydracoin-${VERSION}-win32
	mv hydracoin-${VERSION}-win32/hydracoin-*-setup.exe .
	zip -r hydracoin-${VERSION}-win32.zip hydracoin-${VERSION}-win32
	rm -rf hydracoin-${VERSION}-win32

**Perform Mac build:**

  OSX binaries are created by Gavin Andresen on a 32-bit, OSX 10.6 machine.

	qmake RELEASE=1 USE_UPNP=1 USE_QRCODE=1 hydracoin-qt.pro
	make
	export QTDIR=/opt/local/share/qt4  # needed to find translations/qt_*.qm files
	T=$(contrib/qt_translations.py $QTDIR/translations src/qt/locale)
	python2.7 share/qt/clean_mac_info_plist.py
	python2.7 contrib/macdeploy/macdeployqtplus Bitcoin-Qt.app -add-qt-tr $T -dmg -fancy contrib/macdeploy/fancy.plist

 Build output expected: Bitcoin-Qt.dmg

###Next steps:

* Code-sign Windows -setup.exe (in a Windows virtual machine) and
  OSX Bitcoin-Qt.app (Note: only Gavin has the code-signing keys currently)

* upload builds to SourceForge

* create SHA256SUMS for builds, and PGP-sign it

* update hydracoin.org version
  make sure all OS download links go to the right versions

* update forum version

* update wiki download links

* update wiki changelog: [https://en.hydracoin.it/wiki/Changelog](https://en.hydracoin.it/wiki/Changelog)

Commit your signature to gitian.sigs:

	pushd gitian.sigs
	git add ${VERSION}/${SIGNER}
	git add ${VERSION}-win32/${SIGNER}
	git commit -a
	git push  # Assuming you can push to the gitian.sigs tree
	popd

-------------------------------------------------------------------------

### After 3 or more people have gitian-built, repackage gitian-signed zips:

From a directory containing hydracoin source, gitian.sigs and gitian zips

	export VERSION=(new version, e.g. 0.8.0)
	mkdir hydracoin-${VERSION}-linux-gitian
	pushd hydracoin-${VERSION}-linux-gitian
	unzip ../hydracoin-${VERSION}-linux-gitian.zip
	mkdir gitian
	cp ../hydracoin/contrib/gitian-downloader/*.pgp ./gitian/
	for signer in $(ls ../gitian.sigs/${VERSION}/); do
	 cp ../gitian.sigs/${VERSION}/${signer}/hydracoin-build.assert ./gitian/${signer}-build.assert
	 cp ../gitian.sigs/${VERSION}/${signer}/hydracoin-build.assert.sig ./gitian/${signer}-build.assert.sig
	done
	zip -r hydracoin-${VERSION}-linux-gitian.zip *
	cp hydracoin-${VERSION}-linux-gitian.zip ../
	popd
	mkdir hydracoin-${VERSION}-win32-gitian
	pushd hydracoin-${VERSION}-win32-gitian
	unzip ../hydracoin-${VERSION}-win32-gitian.zip
	mkdir gitian
	cp ../hydracoin/contrib/gitian-downloader/*.pgp ./gitian/
	for signer in $(ls ../gitian.sigs/${VERSION}-win32/); do
	 cp ../gitian.sigs/${VERSION}-win32/${signer}/hydracoin-build.assert ./gitian/${signer}-build.assert
	 cp ../gitian.sigs/${VERSION}-win32/${signer}/hydracoin-build.assert.sig ./gitian/${signer}-build.assert.sig
	done
	zip -r hydracoin-${VERSION}-win32-gitian.zip *
	cp hydracoin-${VERSION}-win32-gitian.zip ../
	popd

- Upload gitian zips to SourceForge
- Celebrate 
