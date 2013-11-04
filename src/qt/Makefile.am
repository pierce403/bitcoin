include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS =  $(INCLUDES) -I$(top_builddir)/src/obj \
  -I$(top_srcdir)/src/leveldb/include -I$(top_srcdir)/src \
  -I$(top_srcdir)/src/leveldb/helpers -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms $(BOOST_INCLUDES) $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS) $(BDB_CPPFLAGS)
AM_LDFLAGS = $(PTHREAD_CFLAGS)
bin_PROGRAMS = hydracoin-qt
noinst_LIBRARIES = libhydracoinqt.a
SUBDIRS = $(BUILD_TEST_QT)
DIST_SUBDIRS = test

# hydracoin qt core #
QT_TS = locale/hydracoin_ach.ts locale/hydracoin_af_ZA.ts locale/hydracoin_ar.ts \
  locale/hydracoin_be_BY.ts locale/hydracoin_bg.ts locale/hydracoin_bs.ts \
  locale/hydracoin_ca_ES.ts locale/hydracoin_ca.ts locale/hydracoin_cs.ts \
  locale/hydracoin_cy.ts locale/hydracoin_da.ts locale/hydracoin_de.ts \
  locale/hydracoin_el_GR.ts locale/hydracoin_en.ts locale/hydracoin_eo.ts \
  locale/hydracoin_es_CL.ts locale/hydracoin_es.ts locale/hydracoin_et.ts \
  locale/hydracoin_eu_ES.ts locale/hydracoin_fa_IR.ts locale/hydracoin_fa.ts \
  locale/hydracoin_fi.ts locale/hydracoin_fr_CA.ts locale/hydracoin_fr.ts \
  locale/hydracoin_gu_IN.ts locale/hydracoin_he.ts locale/hydracoin_hi_IN.ts \
  locale/hydracoin_hr.ts locale/hydracoin_hu.ts locale/hydracoin_id_ID.ts \
  locale/hydracoin_it.ts locale/hydracoin_ja.ts locale/hydracoin_kk_KZ.ts \
  locale/hydracoin_ko_KR.ts locale/hydracoin_la.ts locale/hydracoin_lt.ts \
  locale/hydracoin_lv_LV.ts locale/hydracoin_ms_MY.ts locale/hydracoin_nb.ts \
  locale/hydracoin_nl.ts locale/hydracoin_pl.ts locale/hydracoin_pt_BR.ts \
  locale/hydracoin_pt_PT.ts locale/hydracoin_ro_RO.ts locale/hydracoin_ru.ts \
  locale/hydracoin_sk.ts locale/hydracoin_sq.ts locale/hydracoin_sr.ts \
  locale/hydracoin_sv.ts locale/hydracoin_th_TH.ts locale/hydracoin_tr.ts \
  locale/hydracoin_uk.ts locale/hydracoin_vi.ts locale/hydracoin_vi_VN.ts \
  locale/hydracoin_zh_CN.ts locale/hydracoin_zh_TW.ts

QT_FORMS_UI = forms/aboutdialog.ui forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui forms/editaddressdialog.ui forms/intro.ui \
  forms/optionsdialog.ui forms/overviewpage.ui forms/receiverequestdialog.ui \
  forms/receivecoinsdialog.ui \
  forms/rpcconsole.ui forms/sendcoinsdialog.ui forms/sendcoinsentry.ui \
  forms/signverifymessagedialog.ui forms/transactiondescdialog.ui

QT_MOC_CPP = moc_aboutdialog.cpp moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp moc_askpassphrasedialog.cpp \
  moc_hydracoinaddressvalidator.cpp moc_hydracoinamountfield.cpp \
  moc_hydracoingui.cpp moc_hydracoinunits.cpp moc_clientmodel.cpp \
  moc_csvmodelwriter.cpp moc_editaddressdialog.cpp moc_guiutil.cpp \
  moc_intro.cpp moc_macdockiconhandler.cpp moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp moc_notificator.cpp moc_optionsdialog.cpp \
  moc_optionsmodel.cpp moc_overviewpage.cpp moc_paymentserver.cpp \
  moc_receiverequestdialog.cpp moc_qvalidatedlineedit.cpp moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_rpcconsole.cpp moc_sendcoinsdialog.cpp moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp moc_splashscreen.cpp moc_trafficgraphwidget.cpp moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp moc_transactionview.cpp moc_walletframe.cpp \
  moc_walletmodel.cpp moc_walletview.cpp

BITCOIN_MM = macdockiconhandler.mm macnotificationhandler.mm

QT_MOC = intro.moc overviewpage.moc rpcconsole.moc

QT_QRC_CPP = qrc_hydracoin.cpp
QT_QRC = hydracoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

BITCOIN_QT_H  = aboutdialog.h addressbookpage.h addresstablemodel.h \
  askpassphrasedialog.h hydracoinaddressvalidator.h hydracoinamountfield.h \
  hydracoingui.h hydracoinunits.h clientmodel.h csvmodelwriter.h \
  editaddressdialog.h guiconstants.h guiutil.h intro.h macdockiconhandler.h \
  macnotificationhandler.h monitoreddatamapper.h notificator.h optionsdialog.h \
  optionsmodel.h overviewpage.h paymentrequestplus.h paymentserver.h \
  receivecoinsdialog.h \
  receiverequestdialog.h qvalidatedlineedit.h qvaluecombobox.h rpcconsole.h \
  sendcoinsdialog.h sendcoinsentry.h signverifymessagedialog.h splashscreen.h \
  trafficgraphwidget.h transactiondescdialog.h transactiondesc.h transactionfilterproxy.h \
  transactionrecord.h transactiontablemodel.h transactionview.h walletframe.h \
  walletmodel.h walletmodeltransaction.h walletview.h

RES_ICONS = res/icons/hydracoin.png res/icons/address-book.png \
  res/icons/quit.png res/icons/send.png res/icons/toolbar.png \
  res/icons/connect0_16.png res/icons/connect1_16.png \
  res/icons/connect2_16.png res/icons/connect3_16.png \
  res/icons/connect4_16.png res/icons/transaction0.png \
  res/icons/transaction2.png res/icons/clock1.png res/icons/clock2.png \
  res/icons/clock3.png res/icons/clock4.png res/icons/clock5.png \
  res/icons/configure.png res/icons/receive.png res/icons/editpaste.png \
  res/icons/editcopy.png res/icons/add.png res/icons/hydracoin_testnet.png \
  res/icons/toolbar_testnet.png res/icons/edit.png res/icons/history.png \
  res/icons/overview.png res/icons/export.png res/icons/synced.png \
  res/icons/remove.png res/icons/tx_mined.png res/icons/tx_input.png \
  res/icons/tx_output.png res/icons/tx_inout.png res/icons/lock_closed.png \
  res/icons/lock_open.png res/icons/key.png res/icons/filesave.png \
  res/icons/qrcode.png res/icons/debugwindow.png res/icons/hydracoin.ico \
  res/icons/hydracoin_testnet.ico

BITCOIN_QT_CPP = aboutdialog.cpp addressbookpage.cpp \
  addresstablemodel.cpp askpassphrasedialog.cpp hydracoinaddressvalidator.cpp \
  hydracoinamountfield.cpp hydracoin.cpp hydracoingui.cpp \
  hydracoinunits.cpp clientmodel.cpp csvmodelwriter.cpp editaddressdialog.cpp \
  guiutil.cpp intro.cpp monitoreddatamapper.cpp notificator.cpp \
  optionsdialog.cpp optionsmodel.cpp overviewpage.cpp paymentrequestplus.cpp \
  paymentserver.cpp qvalidatedlineedit.cpp qvaluecombobox.cpp \
  receivecoinsdialog.cpp receiverequestdialog.cpp \
  rpcconsole.cpp sendcoinsdialog.cpp sendcoinsentry.cpp \
  signverifymessagedialog.cpp splashscreen.cpp trafficgraphwidget.cpp transactiondesc.cpp \
  transactiondescdialog.cpp transactionfilterproxy.cpp transactionrecord.cpp \
  transactiontablemodel.cpp transactionview.cpp walletframe.cpp \
  walletmodel.cpp walletmodeltransaction.cpp walletview.cpp

RES_IMAGES = res/images/about.png res/images/splash.png \
  res/images/splash_testnet.png

RES_MOVIES = res/movies/update_spinner.mng

BITCOIN_RC = res/hydracoin-qt-res.rc

libhydracoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libhydracoinqt_a_SOURCES = $(BITCOIN_QT_CPP) $(BITCOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libhydracoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libhydracoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

if TARGET_DARWIN
  libhydracoinqt_a_SOURCES += $(BITCOIN_MM)
endif
if TARGET_WINDOWS
  libhydracoinqt_a_SOURCES += $(BITCOIN_RC)
endif
#

# hydracoin-qt binary #
hydracoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
hydracoin_qt_SOURCES = hydracoin.cpp
hydracoin_qt_LDADD = libhydracoinqt.a $(LIBBITCOIN) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

hydracoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/hydracoinstrings.cpp

translate: hydracoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(BITCOIN_QT_CPP) $(BITCOIN_QT_H) $(BITCOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@$(LUPDATE) $^ -locations relative -no-obsolete -ts locale/hydracoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && $(RCC) -name hydracoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -i.bak -e '/^\*\*.*Created:/d' $@ && rm $@.bak
	$(SED) -i.bak -e '/^\*\*.*by:/d' $@ && rm $@.bak

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
