/*
 * Copyright (C) Rida Bazzi, 2017
 *
 * Do not share this file with anyone
 */

#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include "lexer.h"

class Parser {
  public:

    void syntax_error();
    Token expect(TokenType);
    Token peek();
	
	
    void parse_input();
    void parse_program();
    void parse_grammar();
    void parse_rule();


    






};

#endif
