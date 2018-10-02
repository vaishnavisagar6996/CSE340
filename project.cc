/*
 * Copyright (C) Mohsen Zohrevandi, 2017
 *
 * Do not share this file with anyone
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "parser.h"





using namespace std;

LexicalAnalyzer lexer;


void Parser::syntax_error()
{
    cout<<"SYNTAX ERROR";
}
Token Parser::peek(){
    
    Token t = lexer.GetToken();
	lexer.UngetToken(t);
	return t;
}


Token Parser::expect(TokenType expected_type){
    
	Token t = lexer.GetToken();
	if(expected_type == END_OF_FILE)
	    return t;
	if (t.token_type != expected_type){
	    cout<<"inside expect";
	    cout<<"actual token type"<<t.token_type;
	    cout<<"expected token type"<<expected_type;
	    syntax_error();

	}
	
	return t;
}
void Parser::parse_rule()
{
    //rule: ID -> ID 
    Token t;
    
    expect(ID);

    expect(ARROW);
    expect(ID);

    
    
}
void Parser::parse_grammar(){
    //grammar: rule HASH
    // grammar: rule HASH grammar
    parse_rule();

	Token t = peek();
	if(t.token_type == HASH)
	{
	    expect(HASH);
	    parse_grammar();
	}
	else if(t.token_type == DOUBLEHASH){ ///
	   
	}
	else
	{   
	    cout<<"inside else";
	    syntax_error();
	}
}


void Parser::parse_input(){

    //input: grammar DOUBLEHASH 
    parse_grammar();
    expect(DOUBLEHASH);

}
void Parser::parse_program(){
    //program: input EOF



    parse_input();
    expect(END_OF_FILE);
}


int main (int argc, char* argv[])
{
    int task;

    if (argc < 2)
    {
        cout << "Error: missing argument\n";
        return 1;
    }

    /*
       Note that by convention argv[0] is the name of your executable,
       and the first argument to your program is stored in argv[1]
     */

    task = atoi(argv[1]);
    
    // TODO: Read the input grammar at this point from standard input

    /*
       Hint: You can modify and use the lexer from previous project
       to read the input. Note that there are only 4 token types needed
       for reading the input in this project.

       WARNING: You will need to modify lexer.cc and lexer.h to only
       support the tokens needed for this project if you are going to
       use the lexer.
     */
    Parser parser;
    switch (task) {
        case 1:

            parser.parse_program();
            cout<<"Done";
            // TODO: perform task 1.

            break;

        case 2:
            // TODO: perform task 2.
            break;

        case 3:
            // TODO: perform task 3.
            break;

        case 4:
            // TODO: perform task 4.
            break;

        case 5:
            // TODO: perform task 5.
            break;

        default:
            cout << "Error: unrecognized task number " << task << "\n";
            break;
    }
    return 0;
}


    

































