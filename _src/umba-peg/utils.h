#pragma once

#include "umba/tokenizer.h"
//
#include "umba/tokenizer/token_collection.h"



//template<typename StringType>
//StringType 
inline
std::string getTokenKindString(umba::tokenizer::payload_type p)
{
    using StringType = std::string;

    switch(p)
    {
        case UMBA_TOKENIZER_TOKEN_UNEXPECTED                                  : return umba::string_plus::make_string<StringType>("unxp");
        case UMBA_TOKENIZER_TOKEN_LINEFEED                                    : return umba::string_plus::make_string<StringType>("lf");
        case UMBA_TOKENIZER_TOKEN_SPACE                                       : return umba::string_plus::make_string<StringType>("space");
        case UMBA_TOKENIZER_TOKEN_TAB                                         : return umba::string_plus::make_string<StringType>("tab");
        case UMBA_TOKENIZER_TOKEN_IDENTIFIER                                  : return umba::string_plus::make_string<StringType>("ident");
        case UMBA_TOKENIZER_TOKEN_SEMIALPHA                                   : return umba::string_plus::make_string<StringType>("semialpha");
        // https://en.wikipedia.org/wiki/Bracket
        case UMBA_TOKENIZER_TOKEN_CURLY_BRACKET_OPEN                          : return umba::string_plus::make_string<StringType>("curly");
        case UMBA_TOKENIZER_TOKEN_CURLY_BRACKET_CLOSE                         : return umba::string_plus::make_string<StringType>("curly");
        case UMBA_TOKENIZER_TOKEN_ROUND_BRACKET_OPEN                          : return umba::string_plus::make_string<StringType>("round");
        case UMBA_TOKENIZER_TOKEN_ROUND_BRACKET_CLOSE                         : return umba::string_plus::make_string<StringType>("round");
        case UMBA_TOKENIZER_TOKEN_ANGLE_BRACKET_OPEN                          : return umba::string_plus::make_string<StringType>("angle");
        case UMBA_TOKENIZER_TOKEN_ANGLE_BRACKET_CLOSE                         : return umba::string_plus::make_string<StringType>("angle");
        case UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_OPEN                         : return umba::string_plus::make_string<StringType>("square");
        case UMBA_TOKENIZER_TOKEN_SQUARE_BRACKET_CLOSE                        : return umba::string_plus::make_string<StringType>("square");
        case UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_START           : return umba::string_plus::make_string<StringType>("cmnt");
        case UMBA_TOKENIZER_TOKEN_OPERATOR_MULTI_LINE_COMMENT_END             : return umba::string_plus::make_string<StringType>("cmnt");
        case UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_START                            : return umba::string_plus::make_string<StringType>("pp");
        case UMBA_TOKENIZER_TOKEN_CTRL_CC_PP_END                              : return umba::string_plus::make_string<StringType>("pp");

        case UMBA_TOKENIZER_TOKEN_RAW_CHAR                                    : return umba::string_plus::make_string<StringType>("raw");
        case UMBA_TOKENIZER_TOKEN_PLANTUML_COLOR                              : return umba::string_plus::make_string<StringType>("clr");
        

        // case : return umba::string_plus::make_string<StringType>("");
        // case : return umba::string_plus::make_string<StringType>("");
        // case : return umba::string_plus::make_string<StringType>("");
        // case : return umba::string_plus::make_string<StringType>("");
        // case : return umba::string_plus::make_string<StringType>("");
        // case : return umba::string_plus::make_string<StringType>("");




        //case : return umba::string_plus::make_string<StringType>("");
        default:

            if (p>=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FIRST && p<=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_LAST)
            {
                if (p&UMBA_TOKENIZER_TOKEN_FLOAT_FLAG)
                    return umba::string_plus::make_string<StringType>("num");
                else
                    return umba::string_plus::make_string<StringType>("num");
            }

            if (p>=UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_FIRST && p<=UMBA_TOKENIZER_TOKEN_OPERATOR_SINGLE_LINE_COMMENT_LAST)
                return umba::string_plus::make_string<StringType>("sngl-cmnt");

            //if (p>=UMBA_TOKENIZER_TOKEN_NUMBER_USER_LITERAL_FIRST && p<=UMBA_TOKENIZER_TOKEN_NUMBER_USER_LITERAL_LAST)
            if (p>=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_FIRST && p<=UMBA_TOKENIZER_TOKEN_NUMBER_LITERAL_LAST)
                return umba::string_plus::make_string<StringType>("num");

            if (p>=UMBA_TOKENIZER_TOKEN_OPERATOR_FIRST && p<=UMBA_TOKENIZER_TOKEN_OPERATOR_LAST)
                return umba::string_plus::make_string<StringType>("op");

            if (p>=UMBA_TOKENIZER_TOKEN_STRING_LITERAL_FIRST && p<=UMBA_TOKENIZER_TOKEN_STRING_LITERAL_LAST)
                return umba::string_plus::make_string<StringType>("str");

            if (p>=UMBA_TOKENIZER_TOKEN_KEYWORD_SET1_FIRST && p<=UMBA_TOKENIZER_TOKEN_KEYWORD_SET1_LAST)
                return umba::string_plus::make_string<StringType>("kwd1");

            if (p>=UMBA_TOKENIZER_TOKEN_KEYWORD_SET2_FIRST && p<=UMBA_TOKENIZER_TOKEN_KEYWORD_SET2_LAST)
                return umba::string_plus::make_string<StringType>("kwd2");

            if (p>=UMBA_TOKENIZER_TOKEN_KEYWORD_SET3_FIRST && p<=UMBA_TOKENIZER_TOKEN_KEYWORD_SET3_LAST)
                return umba::string_plus::make_string<StringType>("kwd3");

            if (p>=UMBA_TOKENIZER_TOKEN_KEYWORD_SET4_FIRST && p<=UMBA_TOKENIZER_TOKEN_KEYWORD_SET4_LAST)
                return umba::string_plus::make_string<StringType>("kwd4");

            if (p>=UMBA_TOKENIZER_TOKEN_KEYWORD_SET5_FIRST && p<=UMBA_TOKENIZER_TOKEN_KEYWORD_SET5_LAST)
                return umba::string_plus::make_string<StringType>("kwd5");

            if (p>=UMBA_TOKENIZER_TOKEN_KEYWORD_SET6_FIRST && p<=UMBA_TOKENIZER_TOKEN_KEYWORD_SET6_LAST)
                return umba::string_plus::make_string<StringType>("kwd6");

            if (p>=UMBA_TOKENIZER_TOKEN_KEYWORD_SET7_FIRST && p<=UMBA_TOKENIZER_TOKEN_KEYWORD_SET7_LAST)
                return umba::string_plus::make_string<StringType>("kwd7");

            if (p>=UMBA_TOKENIZER_TOKEN_KEYWORD_SET8_FIRST && p<=UMBA_TOKENIZER_TOKEN_KEYWORD_SET8_LAST)
                return umba::string_plus::make_string<StringType>("kwd8");

            return umba::string_plus::make_string<StringType>("<UNKNOWN>");
    }
}


