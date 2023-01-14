/**
 * @file Main.cpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief main landing point for our program
 * @version 0.1
 * @date 2023-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// raylib includes
#include "raylib.h"

#ifdef USE_RAYGUI
    #define RAYGUI_IMPLEMENTATION
    // idk if necessary
    #define RAYGUI_SUPPORT_ICONS 
    #include "raygui.h"
    #undef RAYGUI_IMPLEMENTATION
#endif


// c/c++ includes
#include <string>  // for strings
#include <iostream>  // for cout/endl
#include <fstream> // for file handling
#include <vector> // vectors
#include <memory>


// project includes
#include "CSVRead.hpp"
#include "CorbSheet.hpp"


// namespace imports
using namespace std;


// use these to determine how main works
// #define PROCESS_CSV_DATA
// #define DUMP_ALL_TABLE_DATA
// #define DUMP_ALL_FIELD_DATA
#define USE_APP_HANDLE
// #define DO_TESTING_STUFFERS



/**
 * @brief Get the Table Objects object
 * 
 * @return vector<CSV::Handler> 
 */
vector<CSV::Handler*> getTableObjects(){
    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // declare our working variables

    // to get to the workspace folder out of the build folder
    string workspaceFolder = "../";
    // the base of the table paths we're using
    string tableFilePathFromResourcesBase = "data spreadsheet harvest/Data Spreadsheet for Animal Crossing New Horizons - ";
    // the extension of the files we're retreiving 
    string tableFileExtension = ".csv";
    // get list of the table names
    vector<string> tableNames = CSV::getTableNames();
    // the list of table handlers
    vector<CSV::Handler*> tableObjectList;

    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // setup path list

    // declare/initialise the path list with the base path
    vector<string> tablePathList{
            // number of tables yoinked from our table names list
            tableNames.size(),
            // the base path before our tokens
            (workspaceFolder + "resources/")
        };
    
    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // construct path list

    // complete constructing the paths
    for(int idx = 0; idx < tablePathList.size(); idx++){
        tablePathList[idx] += tableFilePathFromResourcesBase + tableNames[idx] + tableFileExtension;
    }

    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // declare our CSV handlers list

    //for each path in the path list
    for(int idx = 0; idx < tablePathList.size(); idx++){
        // tell the people
        cout<<"["<< to_string(idx)<< "/" << to_string(tablePathList.size()) <<"]HANDLING CSV::Handler OBJECT FOR: " << endl << tablePathList[idx] << endl;
        // declare the table and give it the table name
        CSV::Handler *currTableHandler = new CSV::Handler( tablePathList[idx], tableNames[idx] );
        // process the handler
        currTableHandler->process();
        // add it to our list
        tableObjectList.push_back( currTableHandler );
    }
    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // done, give it to caller

    return tableObjectList;
    
    // ---- ---- ---- ---- ---- ---- ---- ---- 
}

/**
 * @brief get a list of lists containing the table headers for each table
 * 
 * @param tableListIn is a list of the tables we want to get our headers from
 * 
 * @return vector<vector<string>> 
 */
vector<vector<string>> getTableHeaderLists( vector<CSV::Handler*> tableListIn ){
    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // var declarations

    // our list of headers, each header containing a list of the table's fields
    //      where the first item in each sub-list is the name of the table
    vector<vector<string>> tableHeaderLists;
    
    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // sub-list creation

    // (range for loop using reference of given element)
    //  for each handler, generate the sub-list from our tableListIn
    for( CSV::Handler *currHandler : tableListIn ){
        // ---- ---- ---- ---- ---- 
        // iteration var declarations

        // declare the list for our current table
        vector<string> currHeaderList;
        
        // ---- ---- ---- ---- ---- 
        // setup header list

        // add in the table name as the first element
        currHeaderList.push_back( currHandler->name );

        // ---- ---- ---- ---- ---- 
        // handle the table headers

        // for each item in the first row of the table
        for( int colIdx = 0; colIdx < currHandler->colCount; colIdx++ ){
            // get the current column header
            string currColHeader = currHandler->get(0, colIdx);
            // push it to list
            currHeaderList.push_back( currColHeader );
        }

        // ---- ---- ---- ---- ---- 
        // push to parent list

        tableHeaderLists.push_back( currHeaderList );

        // ---- ---- ---- ---- ---- 
    }

    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // give back to caller
    
    // return whatever the list has in it (empty if no handlers in tableListIn)
    return tableHeaderLists;
}

/**
 * @brief check if the unordered list contains an exact match to
 *       the given item
 * 
 * @brief wants existing lists and existing items
 * 
 * @param listIn the list to check
 * @param itemIn the item to check
 * @return true if it's found in the given list at least once
 * @return false otherwise
 */
bool listHasItem(vector<string> &listIn, string &itemIn){
    // check the list has items
    if(listIn.size()==0) return false;
    // otherwise loop over every item
    for(string &currItem : listIn){
        // compare
        if(currItem == itemIn) return true;
    }
    // havent found it
    return false;
}

/**
 * @brief gets a unique list of fields from across all tables given
 * 
 * @param tableHeaderListIn the table name and fields given from getTableHeaderLists
 * @return vector<string> list of unique fields
 */
vector<string> getUniqueFieldsList( vector<vector<string>> tableHeaderListIn ){
    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // var declarations

    // our list to return to the caller of unique fields
    vector<string> resultUniqueList;

    // TODO improvement by:
    //  - add them all into a list
    //  - sort them using some O(n) or O(log(n)) complexity
    //  - then grab the first item that isnt equal to the
    //      last item we added, and save our location in the
    //      list to advance forward after we get an item
    //  ** has O(~3n) complexity instead of whatever the heck we got

    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // go through every item in input 2D list

    // for every header in input list
    for( vector<string> &currSubList : tableHeaderListIn ){
        // for every item in the header
        //  (ignoring first since it's the table name)
        for( int headerIdx = 1; headerIdx < currSubList.size(); headerIdx++){
            // make sure we dont have it already
            if( !listHasItem( resultUniqueList, currSubList[headerIdx] ) )
                resultUniqueList.push_back( currSubList[headerIdx] ); // add to result list
        }
    }
    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // give back the list to the caller

    return resultUniqueList;

    // ---- ---- ---- ---- ---- ---- ---- ---- 
}

/**
 * @brief list containing each field and the tables that contain them
 * 
 * @param tableHeaderListIn the table name and fields given from getTableHeaderLists
 * @param uniqueFieldListIn the unique list of fields to find which tables contain them
 * @return vector<vector<string>> 
 */
vector<vector<string>> getTablesContainingFieldList( vector<vector<string>> tableHeaderListIn, vector<string> uniqueFieldListIn ){
    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // var declarations 

    // list containing sublists where
    //  each sublist is first the field name,
    //  followed by the table names containing that field
    vector<vector<string>> fieldsContainedInTablesList;

    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // construct fieldsContainedInTablesList

    // loop through each field name
    for( string &currFieldName : uniqueFieldListIn ){
        // make a list for the field
        vector<string> currFieldsTableList;
        // add the field to the list
        currFieldsTableList.push_back(currFieldName);
        // loop through all the table headers, where first item is the table name
        for( int idx = 0; idx < tableHeaderListIn.size(); idx++ ){
            // check if the current field is in this header
            if(listHasItem(tableHeaderListIn[idx], currFieldName)){
                // add this header's table name to the current field being contained in a table list
                //  (first item in each sub-list of 'tableHeaderListIn' is the table's name)
                currFieldsTableList.push_back(tableHeaderListIn[idx][0]);
            }
        }
        // now add the current fields information to our overall list
        fieldsContainedInTablesList.push_back(currFieldsTableList);
    }
    // ---- ---- ---- ---- ---- ---- ---- ---- 
    // return the resulting 2D list to the caller

    return fieldsContainedInTablesList;

    // ---- ---- ---- ---- ---- ---- ---- ---- 
}

// // just make a table where it's like, x is table name, y is header name,
// //      then have the cells as booleans

/**
 * @brief centers a string inside another string, and returns it
 * 
 * @param centeredInStringIn string to center in
 * @param stringToCenterIn the string that will be centered
 * @return string result which will be size of centeredInStringIn if stringToCenterIn is shorter
 * @return string result which is just stringToCenterIn where the size of stringToCenterIn is greater than centeredInStringIn
 */
string getStringAsCenteredInString( string centeredInStringIn, string stringToCenterIn ){
    // declare result string we're returning
    string resultingStringContainingOther;

    // get the difference in size
    int diffInputStringToContainer = centeredInStringIn.size() - stringToCenterIn.size();

    // handle big input string
    if(diffInputStringToContainer < 2){
        // copy it fully across bc it big 
        resultingStringContainingOther = stringToCenterIn;
    }
    // otherwise construct it
    else{
        // just for the extra one placement if it's an odd difference
        int oddDiffRemainder = diffInputStringToContainer%2;
        // the amount from left side that we keep of the spacer line
        int leftPad = diffInputStringToContainer/2;
        // left side of the space line to put in the result before centered content name
        string leftSpacerChunk = centeredInStringIn.substr(0,leftPad-1) + " ";
        // right side version, including the oddDiffRemainder in the positioning inside centeredInStringIn
        //      relative to the right side of the string
        string rightSpacerChunk = " " + centeredInStringIn.substr(
                                            centeredInStringIn.size()-(leftPad + oddDiffRemainder) + 1,
                                            centeredInStringIn.size()
                                        );
        resultingStringContainingOther = leftSpacerChunk + stringToCenterIn + rightSpacerChunk;
    }
    return resultingStringContainingOther;
}


/**
 * @brief handle our app
 * 
 */
void appHandle(){

    // initialise the raylib gui

    InitWindow(1024, 768, "cpp_csv_handler");

    SetTargetFPS(15);

    // initialise the corb sheet

    CorbSheet::CorbSheet *corbSheet = new CorbSheet::CorbSheet();

    corbSheet->grid->setCell(2,3, "beeper");
    corbSheet->grid->setCell(2,12, "the quick brown fox jumped over the lazy dog");

    // handle the draw loop

    while (!WindowShouldClose())
    {
       
        //Draw
        BeginDrawing();
            ClearBackground(GRAY);

            corbSheet->draw();

            // // test content
            // DrawText("TEMPLATE",GetScreenWidth()/2-100,GetScreenHeight()/2,20,BLACK);
            // //Just For Testing
            // #if defined(USE_RAYGUI)
            //     GuiLabel(
            //         (Rectangle){
            //             static_cast<float>(GetScreenWidth()/2.0f-100),
            //             static_cast<float>(GetScreenHeight()/2.0f+30),
            //             200.0f,
            //             100.0f
            //         },
            //         "RayGui Is Working" );
            // #endif


        EndDrawing();
      
    }

    // delete the corbsheet now we're done
    delete corbSheet;

    CloseWindow();
}


#ifdef DO_TESTING_STUFFERS

// /**
//  * @brief float dealer,
//  * @brief expected behaviour:  instance copy that creates a stable reference
//  * @brief actual   behaviour:  creates stack memory and doesnt let us return as reference
//  * @param floatRefIn it's a float reference
//  * 
//  * @return float& reference to a local 'float' initialised from 'floatRefIn'
//  */
// float& floatDealer( float& floatRefIn ){
//     float newFloatRef = floatRefIn;
//     return newFloatRef;
// }

/**
 * @brief float dealer,
 * @brief expected behaviour:  turns magic number into a volatile reference
 * @brief actual   behaviour:  fits in 'float' but not 'float &', instance copy
 * 
 * @return float 1.23f
 */
float floatDealer(){
    return 1.23f;
}
/**
 * @brief float dealer,
 * @brief expected behaviour:  reference return of reference copy
 * @brief actual   behaviour:  
 * @param floatRefIn it's a float reference
 * 
 * @return float& reference to a local 'float' initialised from 'floatRefIn'
 */
float& floatDealerUnstack( float& floatRefIn ){
    float &newFloatRef = floatRefIn;
    return newFloatRef;
}
/**
 * @brief float dealer,
 * @brief expected behaviour:  instance copy that creates a volatile reference
 * @brief actual   behaviour:  instance copy at the time of the call
 * @param floatRefIn reference to a float value
 * 
 * @return float value that was initialised locally and just sending back the value?
 */
float floatDealerUnref( float& floatRefIn ){
    float newFloatRef = floatRefIn;
    return newFloatRef;
}
/**
 * @brief float dealer,
 * @brief expected behaviour:  modifies all floats linked
 * @brief actual   behaviour:  works as intended
 * @param floatRefIn reference to a float value
 * 
 */
void floatDealerAdder( float& floatRefIn ){
    floatRefIn += 1.0f;
}
/**
 * @brief float dealer,
 * @brief expected behaviour:  changes the float completely
 * @brief actual   behaviour:  changes the float value for all floats linked
 * @param floatRefIn reference to a float value
 * 
 */
void floatDealerChanger( float& floatRefIn ){
    float newFloater = 7.46f;
    floatRefIn = newFloater;
}
/**
 * @brief float dealer,
 * @brief expected behaviour:  changes the float reference linkage completely
 * @brief actual   behaviour:  no difference, still changes all variables linked to that address
 * @param floatRefIn reference to a float value
 * 
 */
void floatDealerChanger2( float& floatRefIn ){
    float newFloater = 7.46f;
    float &newFloater2 = newFloater;
    floatRefIn = newFloater2;
}

#endif


/**
 * @brief main landing point for our program
 * 
 * @param argc count of args passed to application on run
 * @param argv pointer to C string array of each arg
 */
int main(int argc, char **argv){
    cout<<"scream"<<endl;

    // spacer line
    string consoleSpacerLine = "==== ==== ==== ==== ==== ==== ==== ==== ==== ====";
    
    #ifdef PROCESS_CSV_DATA

    // list of table names
    vector<string> tableNamesList = CSV::getTableNames();

    // list of table handlers
    vector<CSV::Handler*> tableHandlerList = getTableObjects();

    // list of the table headers
    vector<vector<string>> tableHeaderList = getTableHeaderLists( tableHandlerList );

    // list of unique fields 
    vector<string> uniqueFieldList = getUniqueFieldsList(tableHeaderList);

    // list of tables containing each field
    vector<vector<string>> tablesContainingFieldList = getTablesContainingFieldList(tableHeaderList,uniqueFieldList);

    #endif
    



    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="

    #ifdef DUMP_ALL_TABLE_DATA

    // prepare for next thingy
    cout << consoleSpacerLine << consoleSpacerLine << consoleSpacerLine << endl << endl << endl;

    // for each table
    for( int tableIdx = 0; tableIdx < tableHeaderList.size(); tableIdx++ ){
        // construct console log of the name

        // announce the field
        cout << consoleSpacerLine << endl;
        cout << getStringAsCenteredInString(consoleSpacerLine, tableNamesList[tableIdx]) << endl;
        cout << consoleSpacerLine << endl << endl;

        // output out table count
        cout << "FIELD COUNT: " << to_string(tableHeaderList[tableIdx].size()-1) << endl<<endl;

        // declare table name list
        string currTableFieldList = "FIELDS: ";

        // loop through the fields for that table
        //      ignoring first since it's the name
        for(int idx = 1; idx < tableHeaderList[tableIdx].size(); idx++ ){
            //...
            currTableFieldList += " [" + tableHeaderList[tableIdx][idx] + "],";
        }

        // output table list
        cout << currTableFieldList << endl << endl;
    }

    #endif

    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="

    #ifdef DUMP_ALL_FIELD_DATA

    // prepare for next thingy
    cout << consoleSpacerLine << consoleSpacerLine << consoleSpacerLine << endl << endl << endl;

    // loop through every sub-list (each field)
    for( int uniqueFieldIdx = 0; uniqueFieldIdx < tablesContainingFieldList.size(); uniqueFieldIdx++ ){
        // construct console log of the name

        // announce the field
        cout << consoleSpacerLine << endl;
        cout << getStringAsCenteredInString(consoleSpacerLine, uniqueFieldList[uniqueFieldIdx]) << endl;
        cout << consoleSpacerLine << endl << endl;

        // output out table count
        cout << "TABLE COUNT: " << to_string(tablesContainingFieldList[uniqueFieldIdx].size()-1) << endl<<endl;

        // declare table name list
        string currFieldTableList = "TABLES: ";

        // loop through the tables for that field
        //      ignoring first since it's the name
        for(int idx = 1; idx < tablesContainingFieldList[uniqueFieldIdx].size(); idx++ ){
            //...
            currFieldTableList += " [" + tablesContainingFieldList[uniqueFieldIdx][idx] + "],";
        }

        // output table list
        cout << currFieldTableList << endl << endl;
    }
    #endif

    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="

    // hand off to the appHandle thingy so this space isnt bloated
    #ifdef USE_APP_HANDLE

    // prepare for next thingy
    cout << consoleSpacerLine << consoleSpacerLine << consoleSpacerLine << endl << endl << endl;

    appHandle();

    #endif

    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="

    #ifdef DO_TESTING_STUFFERS

    // // try magic number
    // float stdFloatMagic         = 1.78f;
    // try magic number
    float stdFloatMagic2        = 3.67f;
    // // try return
    // float stdFloatReturn        = floatDealer();
    // // try assign existing float ---> instance copies at the time of declaration
    // float stdFloatCopyMagic     = stdFloatMagic;
    // // try copy from passed reference ---> instance copies on call
    // float stdFloatCopyMagicFunc = floatDealerUnref( stdFloatMagic );

    // [IDE error] [attempt with inline as well] [not left hand value]
    // // try copy return
    // float &refFloatReturn    = floatDealer();
    // [IDE error] [attempt with inline as well] [not left hand value]
    // // try copy from passed reference
    // float &refFloatCopyMagicFunc = floatDealerUnref( stdFloatMagic );

    // // try copy by reference
    // float &refFloatCopyMagic = stdFloatMagic;
    // // try get from created reference
    // float &refFloatCopyMagicFuncRef = floatDealerUnstack( stdFloatMagic );
    // // try add to the float
    // float &refFloatCopyMagicAdd = stdFloatMagic2;

    // try change the float function scope
    float &refFloatCopyMagicChanger = stdFloatMagic2;
    floatDealerChanger( refFloatCopyMagicChanger );

    // now we see what the values are

    cout << endl << consoleSpacerLine << endl;
    cout << consoleSpacerLine << endl << endl;
    // cout << "stdFloatMagic:            | " << to_string( stdFloatMagic            ) << endl;
    cout << "stdFloatMagic2:           | " << to_string( stdFloatMagic2           ) << endl;
    // cout << "stdFloatReturn:           | " << to_string( stdFloatReturn           ) << endl;
    // cout << "stdFloatCopyMagic:        | " << to_string( stdFloatCopyMagic        ) << endl;
    // cout << "stdFloatCopyMagicFunc:    | " << to_string( stdFloatCopyMagicFunc    ) << endl;
    // cout << consoleSpacerLine << endl;
    // cout << "refFloatCopyMagic:        | " << to_string( refFloatCopyMagic        ) << endl;
    // cout << "refFloatCopyMagicFuncRef: | " << to_string( refFloatCopyMagicFuncRef ) << endl;
    // cout << "refFloatCopyMagicAdd:     | " << to_string( refFloatCopyMagicAdd     ) << endl;
    cout << "refFloatCopyMagicChanger: | " << to_string( refFloatCopyMagicChanger ) << endl;
    cout << consoleSpacerLine << endl << endl;

    // change the magic numbers
    // stdFloatMagic  = 2.15f;
    stdFloatMagic2 = 6.95f;

    cout << endl << consoleSpacerLine << endl;
    cout << consoleSpacerLine << endl << endl;
    // cout << "stdFloatMagic:            | " << to_string( stdFloatMagic            ) << endl;
    cout << "stdFloatMagic2:           | " << to_string( stdFloatMagic2           ) << endl;
    // cout << "stdFloatReturn:           | " << to_string( stdFloatReturn           ) << endl;
    // cout << "stdFloatCopyMagic:        | " << to_string( stdFloatCopyMagic        ) << endl;
    // cout << "stdFloatCopyMagicFunc:    | " << to_string( stdFloatCopyMagicFunc    ) << endl;
    // cout << consoleSpacerLine << endl;
    // cout << "refFloatCopyMagic:        | " << to_string( refFloatCopyMagic        ) << endl;
    // cout << "refFloatCopyMagicFuncRef: | " << to_string( refFloatCopyMagicFuncRef ) << endl;
    // cout << "refFloatCopyMagicAdd:     | " << to_string( refFloatCopyMagicAdd     ) << endl;
    cout << "refFloatCopyMagicChanger: | " << to_string( refFloatCopyMagicChanger ) << endl;
    cout << consoleSpacerLine << endl << endl;

    // functions yey
    // floatDealerAdder( refFloatCopyMagicAdd );
    floatDealerChanger2( refFloatCopyMagicChanger );

    cout << endl << consoleSpacerLine << endl;
    cout << consoleSpacerLine << endl << endl;
    // cout << "stdFloatMagic:            | " << to_string( stdFloatMagic            ) << endl;
    cout << "stdFloatMagic2:           | " << to_string( stdFloatMagic2           ) << endl;
    // // cout << "stdFloatReturn:           | " << to_string( stdFloatReturn           ) << endl;
    // // cout << "stdFloatCopyMagic:        | " << to_string( stdFloatCopyMagic        ) << endl;
    // // cout << "stdFloatCopyMagicFunc:    | " << to_string( stdFloatCopyMagicFunc    ) << endl;
    // cout << consoleSpacerLine << endl;
    // cout << "refFloatCopyMagic:        | " << to_string( refFloatCopyMagic        ) << endl;
    // cout << "refFloatCopyMagicFuncRef: | " << to_string( refFloatCopyMagicFuncRef ) << endl;
    // cout << "refFloatCopyMagicAdd:     | " << to_string( refFloatCopyMagicAdd     ) << endl;
    cout << "refFloatCopyMagicChanger: | " << to_string( refFloatCopyMagicChanger ) << endl;
    // cout << consoleSpacerLine << endl << endl;

    #endif

    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="
    // "==== ==== ==== ==== ==== ==== ==== ==== ==== ===="

    return 0;
}

