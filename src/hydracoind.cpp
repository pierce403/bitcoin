// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ui_interface.h"
#include "init.h"
#include "util.h"
#include "main.h"
#include "hydracoinrpc.h"
#include <boost/algorithm/string/predicate.hpp>

void DetectShutdownThread(boost::thread_group* threadGroup)
{
    bool fShutdown = ShutdownRequested();
    // Tell the main threads to shutdown.
    while (!fShutdown)
    {
        MilliSleep(200);
        fShutdown = ShutdownRequested();
    }
    if (threadGroup)
    {
        threadGroup->interrupt_all();
        threadGroup->join_all();
    }
}

//////////////////////////////////////////////////////////////////////////////
//
// Start
//
bool AppInit(int argc, char* argv[])
{
    boost::thread_group threadGroup;
    boost::thread* detectShutdownThread = NULL;

    bool fRet = false;
    try
    {
        //
        // Parameters
        //
        // If Qt is used, parameters/hydracoin.conf are parsed in qt/hydracoin.cpp's main()
        ParseParameters(argc, argv);
        if (!boost::filesystem::is_directory(GetDataDir(false)))
        {
            fprintf(stderr, "Error: Specified data directory \"%s\" does not exist.\n", mapArgs["-datadir"].c_str());
            return false;
        }
        ReadConfigFile(mapArgs, mapMultiArgs);
        // Check for -testnet or -regtest parameter (TestNet() calls are only valid after this clause)
        if (!SelectParamsFromCommandLine()) {
            fprintf(stderr, "Error: Invalid combination of -regtest and -testnet.\n");
            return false;
        }

        if (mapArgs.count("-?") || mapArgs.count("--help"))
        {
            // First part of help message is specific to hydracoind / RPC client
            std::string strUsage = _("Bitcoin version") + " " + FormatFullVersion() + "\n\n" +
                _("Usage:") + "\n" +
                  "  hydracoind [options]                     " + _("Start Bitcoin server") + "\n" +
                _("Usage (deprecated, use hydracoin-cli):") + "\n" +
                  "  hydracoind [options] <command> [params]  " + _("Send command to Bitcoin server") + "\n" +
                  "  hydracoind [options] help                " + _("List commands") + "\n" +
                  "  hydracoind [options] help <command>      " + _("Get help for a command") + "\n";

            strUsage += "\n" + HelpMessage(HMM_BITCOIND);

            fprintf(stdout, "%s", strUsage.c_str());
            return false;
        }

        // Command-line RPC
        bool fCommandLine = false;
        for (int i = 1; i < argc; i++)
            if (!IsSwitchChar(argv[i][0]) && !boost::algorithm::istarts_with(argv[i], "hydracoin:"))
                fCommandLine = true;

        if (fCommandLine)
        {
            int ret = CommandLineRPC(argc, argv);
            exit(ret);
        }
#ifndef WIN32
        fDaemon = GetBoolArg("-daemon", false);
        if (fDaemon)
        {
            // Daemonize
            pid_t pid = fork();
            if (pid < 0)
            {
                fprintf(stderr, "Error: fork() returned %d errno %d\n", pid, errno);
                return false;
            }
            if (pid > 0) // Parent process, pid is child process id
            {
                CreatePidFile(GetPidFile(), pid);
                return true;
            }
            // Child process falls through to rest of initialization

            pid_t sid = setsid();
            if (sid < 0)
                fprintf(stderr, "Error: setsid() returned %d errno %d\n", sid, errno);
        }
#endif

        detectShutdownThread = new boost::thread(boost::bind(&DetectShutdownThread, &threadGroup));
        fRet = AppInit2(threadGroup);
    }
    catch (std::exception& e) {
        PrintExceptionContinue(&e, "AppInit()");
    } catch (...) {
        PrintExceptionContinue(NULL, "AppInit()");
    }

    if (!fRet)
    {
        if (detectShutdownThread)
            detectShutdownThread->interrupt();

        threadGroup.interrupt_all();
        // threadGroup.join_all(); was left out intentionally here, because we didn't re-test all of
        // the startup-failure cases to make sure they don't result in a hang due to some
        // thread-blocking-waiting-for-another-thread-during-startup case
    }

    if (detectShutdownThread)
    {
        detectShutdownThread->join();
        delete detectShutdownThread;
        detectShutdownThread = NULL;
    }
    Shutdown();

    return fRet;
}

extern void noui_connect();
int main(int argc, char* argv[])
{
    bool fRet = false;
    fHaveGUI = false;

    // Connect hydracoind signal handlers
    noui_connect();

    fRet = AppInit(argc, argv);

    if (fRet && fDaemon)
        return 0;

    return (fRet ? 0 : 1);
}
