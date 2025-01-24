/*! \file
    \brief 
 */

// Должна быть первой
#include "umba/umba.h"
//---
#include "umba/app_main.h"
#include "umba/debug_helpers.h"
#include "umba/string_plus.h"
#include "umba/rule_of_five.h"
#include "umba/filename.h"
#include "umba/filesys.h"

//#-sort
#include "umba/simple_formatter.h"
#include "umba/char_writers.h"
//#+sort

//
#include "umba/tokenizer.h"
//
#include "umba/tokenizer/tokenizer_log.h"
#include "umba/tokenizer/tokenizer_log_console.h"

//
#include "../fnset_stub.h"

//
#include <memory>
#include <string>




umba::StdStreamCharWriter coutWriter(std::cout);
umba::StdStreamCharWriter cerrWriter(std::cerr);
umba::NulCharWriter       nulWriter;

umba::SimpleFormatter umbaLogStreamErr(&cerrWriter);
umba::SimpleFormatter umbaLogStreamMsg(&coutWriter);
umba::SimpleFormatter umbaLogStreamNul(&nulWriter);

bool umbaLogGccFormat   = false; // true;
bool umbaLogSourceInfo  = false;


#include "../log.h"



UMBA_APP_MAIN()
{
    UMBA_USED(argc); UMBA_USED(argv);

    using FilenameSetType       = SimpleFilenameSet<std::size_t, std::string>;
    using SharedFilenameSetType = std::shared_ptr<FilenameSetType>;
    using ParserConsoleErrorLog = umba::tokenizer::log::ParserConsoleErrorLog<FilenameSetType>;

    auto pFilenameSet = std::make_shared<FilenameSetType>();
    auto pParserLog   = std::make_shared<ParserConsoleErrorLog>(pFilenameSet);


    std::string inputFilename;

    if (umba::isDebuggerPresent())
    {
        // argsParser.args.clear();
        // argsParser.args.push_back("--overwrite");

        std::string cwd;
        std::string rootPath = umba::shellapi::getDebugAppRootFolder(&cwd);
        std::cout << "App Root Path: " << rootPath << "\n";
        std::cout << "Working Dir  : " << cwd << "\n";

        inputFilename = rootPath + "/_src/umba-peg/tests/umba-peg-test-tpl.cpp";

    } // if (umba::isDebuggerPresent())

    else
    {
        if (argc>1)
        {
            inputFilename = argv[1];
        }
    }

    if (inputFilename.empty())
    {
        LOG_ERR << "No input file taken\n";
        return 1;
    }

    std::string inputText;
    if (!umba::filesys::readFile(inputFilename, inputText))
    {
        LOG_ERR << "failed to read file: '" << inputFilename << "\n";
    }


    

    return 0;
}




