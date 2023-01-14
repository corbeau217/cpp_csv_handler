/**
 * @file CorbSheet.hpp
 * @author corbeau217 (github.com/corbeau217)
 * @brief this will handle the whole sheets thingy
 * @version 0.1
 * @date 2023-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// header protection
#pragma once

// c/c++ includes
#include <string>
#include <vector>
#include <iostream>  // for cout/endl

// raylib includes
#include "raylib.h"
#include "raygui.h"


// project includes


// preprocessor vars
// #define ANNOUNCE_DRAW_CALL // if we should say whenever we draw something in console


// namespace changes
using namespace std;


/**
 * @brief holds our content that handles our spreadsheet content
 * 
 */
namespace CorbSheet {
    /**
     * @brief RefSpace, 4 fields
     * 
     * @brief for the placement of an element in the ui, requiring fields to be references
     */
    typedef struct RefSpace {
        float &x;                // space top-left corner position x
        float &y;                // space top-left corner position y
        float &width;            // space width
        float &height;           // space height
    } RefSpace;

    /**
     * @brief is an area of the raygui that draws a box, and then a label over the top
     * 
     */
    class CorbCell {
        public:
        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // static vars

        //....

        // ---- ---- ---- ----  ---- ---- ---- ---- 
        // static member functions

        //...

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // member vars

        // the space occupied by this cell
        Rectangle space;
        // grid positioning fields
        int col,row;
        // the label string this cell has
        // TODO change to have paint provide the cell's data
        //      this allows a cell to just be a structure of fixed size that is used by the grid to produce a cell
        string value;

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // constructors/destructors

        /**
         * @brief constructor
         * 
         */
        CorbCell(Rectangle spaceIn, int xIdxIn, int yIdxIn);

        // ---- ---- ---- ----  ---- ---- ---- ---- 
        /**
         * @brief destructor
         * 
         */
        ~CorbCell();

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // member functions

        /**
         * @brief set the text for this cell
         * 
         */
        void setText(string textIn);
        /**
         * @brief get the text for this cell
         * 
         */
        string getText();

        // ---- ---- ---- ----  ---- ---- ---- ---- 

        /**
         * @brief gets the drawable text, used for incase the label is too long it crops it to 20 characters long
         * 
         * @return string of the text
         */
        string getDrawableText();

        // ---- ---- ---- ----  ---- ---- ---- ---- 

        /**
         * @brief draw handle thingy
         * 
         */
        void draw();

        // GuiLabel(
        //     (Rectangle){
        //         static_cast<float>(GetScreenWidth()/2.0f-100),
        //         static_cast<float>(GetScreenHeight()/2.0f+30),
        //         200.0f,
        //         100.0f
        //     },
        //     "RayGui Is Working" );
        
        // ==== ==== ==== ====  ==== ==== ==== ==== 
    };

    // the default size of our grid columns in pixels
    #define CORBGRID_DEFAULT_COLSIZE 50.0f
    // the default size of our grid rows in pixels
    #define CORBGRID_DEFAULT_ROWSIZE 20.0f

    /**
     * @brief holds a bunch of CorbCell items and interfaces between Client and a CorbCell
     * 
     */
    class CorbGrid{
        public:
        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // static vars

        //....

        // ---- ---- ---- ----  ---- ---- ---- ---- 
        // static member functions

        //...

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // member vars

        // ---- ---- ----  ---- ---- ---- 
        // full grid vars
        
        // grid max vals
        int colCount,rowCount;
        // header checkers
        bool hasColHeader,hasRowHeader;
        // // the cells we're using, [y][x] or [row][col]
        // vector<vector<CorbCell*>> cells;
        // TODO implement this as the new storage
        // data held by each cell
        vector<vector<string>> cellVals;
        
        // ---- ---- ---- ---- 
        // each column

        // the width of each column
        vector<float> colSize;
        // the position of each column
        vector<float> colPos;

        // ---- ---- ---- ---- 
        // each row
        
        // the height of each row
        vector<float> rowSize;
        // the position of each row
        vector<float> rowPos;

        // ---- ---- ----  ---- ---- ---- 
        // veiw space vars

        // the space occupied by this grid
        // TODO change to viewSpace
        Rectangle space;
        // where we're veiwing from in the grid
        int veiwingCol, veiwingRow;

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // constructors/destructors

        /**
         * @brief constructor
         * 
         */
        CorbGrid(Rectangle spaceIn, int colCountIn, int rowCountIn);

        // ---- ---- ---- ----  ---- ---- ---- ---- 
        /**
         * @brief destructor
         * 
         */
        ~CorbGrid();

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // member functions

        //...

        // ---- ---- ---- ----  ---- ---- ---- ---- 

        /**
         * @brief gets the drawable text, used for incase the label is too long it crops it to 20 characters long
         * 
         * @return string of the text
         */
        string getDrawableText( string valueIn );

        // ---- ---- ---- ----  ---- ---- ---- ---- 

        //...
        /**
         * @brief get the cell pointer at the indexed location
         * 
         * @param colIndex col index of the cell to get
         * @param rowIndex row index of the cell to get
         */
        string getCell( int colIndex, int rowIndex );

        /**
         * @brief set the cell pointer at the indexed location
         * 
         * @param colIndex col index of the cell to set
         * @param rowIndex row index of the cell to set
         */
        void setCell( int colIndex, int rowIndex, string valueIn );

        // ---- ---- ---- ----  ---- ---- ---- ---- 

        /**
         * @brief draw handle thingy
         * 
         */
        void draw(); // just calculate or dont, what we show for now
        // TODO implement the usage of this
        //      for now just have it call draw normally
        /**
         * @brief draw handle thing
         * 
         * @param veiwingColIn top left cell col index
         * @param veiwingRowIn top left cell row index
         * @param veiwingColCountIn col count of veiwing area
         * @param veiwingRowCountIn row count of veiwing area
         */
        void draw( int veiwingColIn, int veiwingRowIn, int veiwingColCountIn, int veiwingRowCountIn );
        
        // ==== ==== ==== ====  ==== ==== ==== ==== 
    };

    /**
     * @brief handles the creation and management of a CellGrid for the app
     *          (kinda like Client in our other projects, specialised to this project)
     * 
     */
    class CorbSheet{
        public:
        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // static vars

        //....

        // ---- ---- ---- ----  ---- ---- ---- ---- 
        // static member functions

        //...

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // member vars

        // grid instance
        CorbGrid *grid;
        // top left cell position we're veiwing, initialise as -1 before we load
        int veiwingCol, veiwingRow;
        // total count of cols/rows we draw
        int veiwingColCount, veiwingRowCount;

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // constructors/destructors

        /**
         * @brief constructor
         * 
         */
        CorbSheet();

        // ---- ---- ---- ----  ---- ---- ---- ---- 
        /**
         * @brief destructor
         * 
         */
        ~CorbSheet();

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // member functions

        //...

        // ---- ---- ---- ----  ---- ---- ---- ---- 

        /**
         * @brief draw handle thingy
         * 
         */
        void draw(); // just calculate or dont, what we show for now

        // ==== ==== ==== ====  ==== ==== ==== ==== 
    };
};

// ===== ===== ===== ===== =====  ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== 
// ===== ===== ===== ===== =====  ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== 
// ===== ===== ===== ===== =====  ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== 

/**
 * @brief definitions for the classes above
 * 
 */
namespace CorbSheet {

    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  

    /**
     * @brief constructor
     * 
     */
    CorbCell::CorbCell(Rectangle spaceIn, int xIdxIn, int yIdxIn){
        // initialise the space as instance copy of the spaceIn
        space = { spaceIn.x, spaceIn.y, spaceIn.width, spaceIn.height };
        // initialise col index
        col = xIdxIn;
        // initialise row index
        row = yIdxIn;
        // initialise the value
        value = "";
    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 
    /**
     * @brief destructor
     * 
     */
    CorbCell::~CorbCell(){
        // empty body
    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    /**
     * @brief set the text for this cell
     * 
     */
    void CorbCell::setText(string textIn){
        value = textIn;
    }
    /**
     * @brief get the text for this cell
     * 
     */
    string CorbCell::getText(){
        return value;
    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    /**
     * @brief gets the drawable text, used for incase the label is too long it crops it to 20 characters long
     * 
     * @return string of the text
     */
    string CorbCell::getDrawableText(){
        if( value.length() > 20 )
            return value.substr(0,20) + "...";
        return value;
    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    /**
     * @brief draw handle thingy
     * 
     */
    void CorbCell::draw(){
        #ifdef ANNOUNCE_DRAW_CALL
        cout << ".";
        #endif
        // RAYLIB ONLY version

        // // draw the space
        // DrawRectangleRec(space,WHITE);
        // // draw the outline
        // DrawRectangleLines(
        //     // pos
        //     static_cast<int>(space.x),static_cast<int>(space.y),
        //     // size
        //     static_cast<int>(space.width),static_cast<int>(space.height),
        //     BLACK
        // );
        // DrawText("TEMPLATE",GetScreenWidth()/2-100,GetScreenHeight()/2,10,BLACK);

        // RAYGUI version
        // draw the cell background
        GuiDrawRectangle(space,1,DARKGRAY,WHITE);
        // draw the text
        GuiLabel( space, getDrawableText().c_str() );
    }
    
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  

    /**
     * @brief constructor
     * 
     */
    CorbGrid::CorbGrid( Rectangle spaceIn, int colCountIn, int rowCountIn ){
        // initialise the space as instance copy of the spaceIn
        space = { spaceIn.x, spaceIn.y, spaceIn.width, spaceIn.height };
        // initialise the col count
        colCount = colCountIn;
        // initialise the row count
        rowCount = rowCountIn;

        // prepare some stores
        float prevPos = 0.0f;
        float prevSize = 0.0f;

        // for each column
        for( int i = 0; i < colCount; i++ ){
            // setup the colSize as our default
            colSize.push_back( CORBGRID_DEFAULT_COLSIZE );

            // setup the column position based of the previous
            // store it
            colPos.push_back( prevPos + prevSize );

            // save the current col data
            prevPos = prevPos + prevSize;
            prevSize = CORBGRID_DEFAULT_COLSIZE;
        }

        // clean up stores for row
        prevPos = 0.0f;
        prevSize = 0.0f;

        // for each row
        for( int i = 0; i < rowCount; i++ ){
            // setup the rowSize as our default
            rowSize.push_back( CORBGRID_DEFAULT_ROWSIZE );

            // setup the column position based of the previous
            // store it
            rowPos.push_back( prevPos + prevSize );

            // save the current col data
            prevPos = prevPos + prevSize;
            prevSize = CORBGRID_DEFAULT_ROWSIZE;
        }

        // setup the veiwing thingies
        veiwingCol = 0;
        veiwingRow = 0;

        // initialise our boolean for col header
        hasColHeader = true;
        // initialise our boolean for row header
        hasRowHeader = false;
        // now setup the cells thingy

        // comment out the cells initialisation
        // for every row
        for( int currRow = 0; currRow < rowCount; currRow++ ){
            // // initialise the row list
            // vector<CorbCell*> currCellRow;
            // initialise the curr row list
            vector<string> currRowVals;

            // for every column in a row
            for( int currCol = 0; currCol < colCount; currCol++ ){
                // Rectangle currCellSpace = {
                //     // the x position
                //     space.x + colPos[ currCol ],
                //     // the y position
                //     space.y + rowPos[ currRow ],
                //     // the size of the cell
                //     colSize[ currCol ], rowSize[ currRow ]
                // };
                // //...
                // // initialise the curr cell instance pointer
                // CorbCell *currCell = new CorbCell( currCellSpace, currCol, currRow );

                // // push to the row list
                // currCellRow.push_back( currCell );

                // push junk to the row vals
                currRowVals.push_back( "" );
            }

            // // push the row to the overall cells list
            // cells.push_back( currCellRow );

            // push the row vals list to overall vals
            cellVals.push_back( currRowVals );
        }
    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    /**
     * @brief destructor
     * 
     */
    CorbGrid::~CorbGrid(){
        // delete all the cells

        // for(int y = 0; y < rowCount; y++ ){
        //     for(int x = 0; x < colCount; x++){
        //         delete cells[y][x];
        //     }
        // }

    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    //...

    /**
     * @brief get the cell pointer at the indexed location
     * 
     * @param colIndex col index of the cell to get
     * @param rowIndex row index of the cell to get
     */
    string CorbGrid::getCell( int colIndex, int rowIndex ){
        return cellVals[rowIndex][colIndex];
    }

    /**
     * @brief set the cell pointer at the indexed location
     * 
     * @param colIndex col index of the cell to set
     * @param rowIndex row index of the cell to set
     */
    void CorbGrid::setCell( int colIndex, int rowIndex, string valueIn ){
        cellVals[rowIndex][colIndex] = valueIn;
    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    /**
     * @brief gets the drawable text, used for incase the label is too long it crops it to 20 characters long
     * 
     * @return string of the text
     */
    string CorbGrid::getDrawableText( string valueIn ){
        if( valueIn.length() > 20 )
            return valueIn.substr(0,20) + "...";
        return valueIn;
    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    /**
     * @brief draw handle thingy
     * 
     */
    void CorbGrid::draw(){ // just calculate or dont, what we show for now
        #ifdef ANNOUNCE_DRAW_CALL
        cout << "grid draw call" << endl;
        #endif
        // draw the grid background/border
        GuiDrawRectangle(space,3,BLACK,LIGHTGRAY);
        // for every row fully within the veiw space
        for( int currRow = veiwingRow; ( currRow < rowCount ) &&
            ( ( rowPos[currRow] + rowSize[currRow] ) - rowPos[ veiwingRow ] ) < space.height; currRow++ ){
            // for every col fully within the veiw space
            for( int currCol = veiwingCol; ( currCol < colCount ) &&
            ( ( colPos[currCol] + colSize[currCol] ) - colPos[ veiwingCol ] ) < space.width; currCol++ ){
                // // tell the cell to draw
                // getCell(currCol,currRow)->draw();

                // prepare the current cell space
                Rectangle currCellSpace {
                    colPos[currCol] - colPos[ veiwingCol] + space.x,
                    rowPos[currRow] - rowPos[ veiwingRow] + space.y,
                    colSize[currCol],
                    rowSize[currRow],
                };

                // RAYGUI version
                // draw the cell background
                GuiDrawRectangle( currCellSpace, 1, DARKGRAY, WHITE );
                // draw the text
                GuiLabel( currCellSpace, getDrawableText( getCell( currCol, currRow ) ).c_str() );

            }
        }
    }
    // TODO implement the usage of this
    //      for now just have it call draw normally
    /**
     * @brief draw handle thing
     * 
     * @param veiwingColIn top left cell col index
     * @param veiwingRowIn top left cell row index
     * @param veiwingColCountIn col count of veiwing area
     * @param veiwingRowCountIn row count of veiwing area
     */
    void CorbGrid::draw( int veiwingColIn, int veiwingRowIn, int veiwingColCountIn, int veiwingRowCountIn ){
        draw();
    }

    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  

    /**
     * @brief constructor
     * 
     */
    CorbSheet::CorbSheet(){
        // initialise the space
        Rectangle gridSpace = {
            // position
            50.0f, 50.0f,
            // bounds
            400.0f, 300.0f
        };
        // initialise the grid
        grid = new CorbGrid( gridSpace, 8, 20 );
    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    /**
     * @brief destructor
     * 
     */
    CorbSheet::~CorbSheet(){
        delete grid;
    }

    // ==== ==== ==== ====  ==== ==== ==== ==== 
    // member functions

    //...

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    /**
     * @brief draw handle thingy
     * 
     */
    void CorbSheet::draw(){
        #ifdef ANNOUNCE_DRAW_CALL
        cout << endl << "sheet draw call" << endl;
        #endif
        grid->draw();
    }

    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
}