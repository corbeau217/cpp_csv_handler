/**
 * @file CSVRead.hpp
 * @author corbeau217 (github.com/corbeau217)
 * @brief handles reading the CSV data from file
 * @version 0.1
 * @date 2023-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// header protection
#pragma once

// c++ includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


// namespace changes
using namespace std;


/**
 * @brief handling CSV data
 * 
 */
namespace CSV {
    //...

    /**
     * @brief this is the thing that handles the csv file
     * 
     */
    class Handler{
        public:
        // ==== ==== ==== ==== ==== ==== 
        // the file we're working on
        ifstream file;
        
        // raw lines extracted from the file
        vector<string> rawLines;

        // processed data of each cell
        vector<vector<string>> cells;

        // number of lines
        //  -1 initialised, 0 if no lines
        int rowCount;
        // number of tokens per line
        //  -1 initialised, 0 if no items
        int colCount;

        // just the name of the table we're handling
        string name;

        // ==== ==== ==== ==== ==== ==== 

        /**
         * @brief constructor
         * 
         * @param filePath path to the file
         * @param nameIn the name of the table to handle
         */
        Handler(string filePath, string nameIn);
        
        /**
         * @brief destructor
         * 
         */
        ~Handler();

        // ==== ==== ==== ==== ==== ==== 

        /**
         * @brief fetches the raw lines from our current file stream then gets the tokens from our raw lines
         * 
         */
        void process();

        /**
         * @brief get the cell value at a particular location
         * 
         * @brief make sure to process the CSV before attempting this
         * 
         * @param row 
         * @param col 
         * @return string 
         */
        string get(int row, int col);

        // ==== ==== ==== ==== ==== ==== 
    };

    // ==== ==== ==== ==== ==== ==== 

    /**
     * @brief process the token stack to be a real string
     * 
     * @param tokenStackIn the stack in questions
     * @return string of the new real string
     */
    string getTokenStackAsString(vector<string> tokenStackIn);

    /**
     * @brief get a list of token stacks from our line, to then process each with getTokenStackAsString
     * 
     * @brief process just the first token found in the string and recurse for any more
     * 
     * @param rawLineIn raw line we use to get the token stacks to make tokens out of
     * @param tokenListRef the reference to our list of tokens we want it to be added to
     */
    vector<string> getCSVTokenList(string rawLineIn, vector<string> &tokenListRef);

    /**
     * @brief retrieves the lines from the file steam
     * 
     * @param fileIn the file stream to fetch from
     * @return vector<string> the list of raw lines obtained
     */
    vector<string> getFilestreamLines(ifstream &fileIn);

    /**
     * @brief returns a list of the table names in the database thingy
     * 
     * @return vector<string> 
     */
    vector<string> getTableNames();

    // ==== ==== ==== ==== ==== ==== 
};

// ==== ==== ==== ==== ==== ==== 

/**
 * @brief definitions
 * 
 */
namespace CSV {
    // ...
    // ==== ==== ==== ==== ==== ==== 

    /**
     * @brief constructor
     * 
     * @param filePath path to the file
     * @param nameIn the name of the table to handle
     */
    Handler::Handler(string filePath, string nameIn){
        file.open(filePath, ios::in);
        colCount = -1;
        rowCount = -1;
        // c++ instance copies with a standard equals on string var
        name = nameIn;
    }
    
    /**
     * @brief destructor
     * 
     */
    Handler::~Handler(){
        //...
        file.close();
    }

    // ==== ==== ==== ==== ==== ==== 

    /**
     * @brief fetches the raw lines from our current file stream then gets the tokens from our raw lines
     * 
     */
    void Handler::process(){
        // ----- ----- ----- ----- ----- 
        // get the lines into our raw lines
        rawLines = getFilestreamLines(file);
        // ----- ----- ----- ----- ----- 
        // update our rowCount
        rowCount = rawLines.size();
        // ----- ----- ----- ----- ----- 
        // loop through rawLines and for each, do the tokening
        for(string currLine : rawLines){
            // declare currLineTokens thingy
            vector<string> currLineTokenList;
            // fill them out
            getCSVTokenList(currLine,currLineTokenList);
            // copy the size into int
            //  (dump this into a int because it wont assign/work otherwise)
            //  P A I N
            int tokenCount = currLineTokenList.size();
            // push the list of retreived tokens to our cells matrix thing
            cells.push_back(currLineTokenList);
            // check if we have a larger size and change colCount
            if(tokenCount > colCount){
                colCount = tokenCount;
                // cout<<"changer"<<endl;
            }
            continue;
        }
        // ----- ----- ----- ----- ----- 
        // add in empty cells were necessary

        string emptyCellString = "";

        // for each row
        for( int rowIdx = 0; rowIdx < rowCount; rowIdx++){
            // ...
            // for each column that should exist in row
            for( int colIdx = 0; colIdx < colCount; colIdx++ ){
                // prepare our vars
                int currRowWidth = cells[rowIdx].size();
                int desiredRowWidth = colCount;
                // check we're at the right row width
                if(currRowWidth < desiredRowWidth){
                    // add an empty string to the current row
                    cells[rowIdx].push_back( "" );
                }
            }
        }
        // ----- ----- ----- ----- ----- 
    }

    /**
     * @brief get the cell value at a particular location
     * 
     * @brief make sure to process the CSV before attempting this
     * 
     * @param row
     * @param col
     * @return string 
     */
    string Handler::get(int row, int col){
        return cells[row][col];
    }

    // ==== ==== ==== ==== ==== ==== 

    /**
     * @brief process the token stack to be a real string
     * 
     * @param tokenStackIn the stack in questions
     * @return string of the new real string
     */
    string getTokenStackAsString(vector<string> tokenStackIn){
        // base case, return empty string
        if(tokenStackIn.size()==0) return "";
        // recursive case
        // stash back
        string backElement;
        if( tokenStackIn.back().size() > 0){
            // conversion happens from assigning to an already initialised string
            backElement = tokenStackIn.back().at(0);
        }
        else{
            backElement = "";
        }
        // pop it
        tokenStackIn.pop_back();
        // then return recursive + back
        string resultString = getTokenStackAsString(tokenStackIn);
        resultString += backElement;
        return resultString;
    }

    /**
     * @brief get a list of token stacks from our line, to then process each with getTokenStackAsString
     * 
     * @brief process just the first token found in the string and recurse for any more
     * 
     * @param rawLineIn raw line we use to get the token stacks to make tokens out of
     * @param tokenListRef the reference to our list of stacks we want it to be added to
     */
    vector<string> getCSVTokenList(string rawLineIn, vector<string> &tokenListRef){
        // declare token stack
        vector<string> currTokenStack;
        // stash the rawLineIn in a working string so we can work on it
        //      (idk if this does instance/reference copy)
        string workingLine = rawLineIn;
        // to keep track of if we're quoting the token
        bool quotingToken = false;
        // to keep track of if last was quote
        bool lastWasQuote = false;
        // ----- ----- ----- ----- ----- 
        // handle empty rawLineIn
        //       BASE CASE

        if(rawLineIn.size()==0){
            // give empty string to list
            tokenListRef.push_back( "" );
            // done doing the thing so return
            return tokenListRef;
        }
        
        // ----- ----- ----- ----- ----- 
        // try go over the line
        while(workingLine.size() > 0){
            // ----- ----- -----
            // chop off first

            // get the currChar we working with
            //      use the string constructor to convert from char to string
            //      (initialise the string before assignment so it will accept a char)
            string currChar;
            // conversion to string happens because we're assigning to an existing string
            currChar = workingLine.at(0);
            // ----- ----- -----
            // advance working string

            // remove it from the working line
            if(workingLine.size() > 1)
                workingLine = workingLine.substr(1);
            else
                workingLine = "";
            // ----- ----- -----
            // handle the char

            // handle not quote
            if(currChar != "\""){
                // handle last was quote
                if(lastWasQuote){
                    // ----- ----- -----
                    // stop last was quote flag
                    lastWasQuote = false;
                    // ----- ----- -----
                    // handle quoted token branch
                    //  ending token, probs comma
                    if(quotingToken)
                        break; // get to end of while loop to add token
                    // otherwise not quoted token yet
                    // ----- ----- -----
                    // no items yet, so make us quoting token
                    if(currTokenStack.size()==0)
                        quotingToken = true;
                    // otherwise push the escaped quote
                    else
                        currTokenStack.push_back("\"");
                    // ----- ----- -----
                }
                // ----- ----- -----
                // handle when last is not a quote
                // when we're in a non quoted token
                //  with a comma as our currChar
                else if(!quotingToken && currChar == ",")
                    break; // get to end of while loop to add token
                // ----- ----- -----
                // should be safe to push the char we're doing
                currTokenStack.push_back( currChar );
                // ----- ----- -----
            }
            // handle quote char
            else{
                // saw quote char already
                if(lastWasQuote){
                    // uncheck since we know
                    lastWasQuote = false;
                    // if empty token stack, would be empty quoted token
                    //      handle it so we can find the next comma easier
                    if(currTokenStack.size()==0){
                        quotingToken = false;
                    }
                    else{
                        // ...
                        // branch only accessible on CSV file creation error
                        //  or space before first quote
                        // pretend it's fine
                        currTokenStack.push_back("\"");
                    }
                    continue; // go next iteration
                }
                // otherwise prepare possible quote
                lastWasQuote = true;
            }
        }

        // ----- ----- ----- ----- ----- 
        // convert the stack to string and add
        tokenListRef.push_back( getTokenStackAsString(currTokenStack) );
        // ----- ----- ----- ----- ----- 
        // recurse with working string etc
        //        RECURSIVE CASE

        return getCSVTokenList(workingLine,tokenListRef);        
        // ----- ----- ----- ----- ----- 
    }

    /**
     * @brief retrieves the lines from the file stream, will end up at the end of the file by the end of this function
     * 
     * @param fileIn the file stream to fetch from
     * @return vector<string> the list of raw lines obtained
     */
    vector<string> getFilestreamLines(ifstream &fileIn){
        // declare list of lines
        vector<string> rawLines;
        // loop through all lines and add them
        for( string currRawLine = ""; getline(fileIn, currRawLine); ){
            // add the current line to our rawLins
            // may have issues with reference vs instance copy
            rawLines.push_back(currRawLine);
        }
        // give back the raw lines
        return rawLines;
    }

    // ==== ==== ==== ==== ==== ==== 


    /**
     * @brief returns a list of the table names in the database thingy
     * 
     * @return vector<string> 
     */
    vector<string> getTableNames(){
        /**
         * @brief typed these as magic data bc finding them by searching
         *      directory was bloaty code that i'll spend too long on
         * 
         */
        vector<string> resultTableNameList {
            // "Read Me", // not part of the data so comment out for the data analysis to work
            "Housewares",
            "Miscellaneous",
            "Wall-mounted",
            "Ceiling Decor",
            "Interior Structures",
            "Wallpaper",
            "Floors",
            "Rugs",
            "Photos",
            "Posters",
            "Tools_Goods",
            "Fencing",
            "Tops",
            "Bottoms",
            "Dress-Up",
            "Headwear",
            "Accessories",
            "Socks",
            "Shoes",
            "Bags",
            "Umbrellas",
            "Clothing Other",
            "Music",
            "Insects",
            "Fish",
            "Sea Creatures",
            "Fossils",
            "Artwork",
            "Gyroids",
            "Other",
            "Construction",
            "Recipes",
            "Achievements",
            "Villagers",
            "Special NPCs",
            "Reactions",
            "Message Cards",
            "Seasons and Events",
            "Paradise Planning"
        };
        // send it to caller
        return resultTableNameList;
    }

    // ==== ==== ==== ==== ==== ==== 
};