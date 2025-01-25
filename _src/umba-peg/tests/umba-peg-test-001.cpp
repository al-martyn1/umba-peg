/*! \file
    \brief Тест коллекции токенов с ленивым фетчем токенов
 */

// Должна быть первой
#include "umba/umba.h"
//---
#include "marty_cpp/src_normalization.h"
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
#include "umba/tokenizer/token_collection.h"
#include "umba/filename_set.h"
#include "umba/escape_string.h"
//
// #include "../fnset_stub.h"

#include "../peg_v1.h"
#include "../utils.h"

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

    using FilenameSetType               = umba:: /* Simple */ FilenameSet<std::size_t /* , std::string */ >;
    using SharedFilenameSetType         = std::shared_ptr<FilenameSetType>;
    using ParserConsoleErrorLog         = umba::tokenizer::log::ParserConsoleErrorLog<FilenameSetType>;

    using TokenizerBuilderType          = decltype(umba::peg::makeTokenizerBuilderPeg<char>());
    using TokenizerType                 = decltype(TokenizerBuilderType().makeTokenizer());
    using TokenizerPayloadType          = umba::tokenizer::payload_type;
    using TokenizerIteratorType         = typename TokenizerType::iterator_type;
    using TokenizerTokenParsedDataType  = typename TokenizerType::token_parsed_data_type;
    using TokenCollectionType           = umba::tokenizer::TokenCollection<TokenizerType>;


// template< typename PayloadType
//         , typename InputIteratorType
//         , typename TokenParsedDataType



    auto pFilenameSet = std::make_shared<FilenameSetType>();
    auto pParserLog   = std::make_shared<ParserConsoleErrorLog>(pFilenameSet);


    //TokenizerBuilder::tokenizer_type



    std::string inputFilename;

    if (umba::isDebuggerPresent())
    {
        // argsParser.args.clear();
        // argsParser.args.push_back("--overwrite");

        std::string cwd;
        std::string rootPath = umba::shellapi::getDebugAppRootFolder(&cwd);
        std::cout << "App Root Path: " << rootPath << "\n";
        std::cout << "Working Dir  : " << cwd << "\n";

        inputFilename = rootPath + "/_src/umba-peg/tests/grammar-001.peg";

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

    inputText = marty_cpp::normalizeCrLfToLf(inputText);


    TokenizerBuilderType tokenizerBuilder = umba::peg::makeTokenizerBuilderPeg<char>();
    TokenCollectionType  tokenCollection  = TokenCollectionType( tokenizerBuilder.makeTokenizer()
                                                               , umba::peg::PegTokenizerConfigurator()
                                                               , pParserLog
                                                               , inputText
                                                               , pFilenameSet->addFile(inputFilename)
                                                               );

    std::size_t cnt = 0;

    // Простое повторение предыдущего токена - 
    // не забываем, что при считывании токена происходит автоматическое смещение указателя на следующий токен
    std::size_t shiftVal = 0;

    for(; ; ++cnt)
    {
        std::size_t tokenPos = 0;
        auto pTokenInfo = tokenCollection.getToken(&tokenPos);
        if (!pTokenInfo)
        {
            std::cout << "Something goes wrong, pTokenInfo is null\n";
            break;
        }

        if (pTokenInfo->isTokenFin())
        {
            std::cout << "!!! Normal stop\n";
            break;
        }

        std::cout << getTokenKindString(pTokenInfo->getTokenType()) 
                  << ": [" << umba::escapeStringC(pTokenInfo->getText()) 
                  << "]" 
                  << ", total fetched: " << tokenCollection.getNumFetchedTokens()
                  << ", idx: " << tokenPos
                  << ", cnt: " << cnt
                  << ", cnt%5: " << cnt%5
                  << "\n";


        if (cnt && (cnt%5)==0) // Для теста делаем сдвиг назад и смотрим, что есть
        {
            std::cout << "--- Shift back by " << shiftVal << "\n";
            tokenPos -= shiftVal;
            tokenCollection.setTokenPos(tokenPos);
        }

    }
    
    std::cout << "!!! Done\n";

    return 0;
}




