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
    // apparently this doesnt work how we want it
    typedef struct RefSpace {
        float &x;                // space top-left corner position x
        float &y;                // space top-left corner position y
        float &width;            // space width
        float &height;           // space height
    } RefSpace;

    // TODO have each cell contain a reference address to the grid draw offset or provided in paint
    // TODO have a container for colors
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

        // // the space occupied by this cell
        // Rectangle space;

        // position var holding a reference to the column's position
        float &colPosX;
        // position var holding a reference to the row's position
        float &rowPosY;
        // width var holding a reference to the column's size
        float &colSizeWidth;
        // height var holding a reference to the row's size
        float &rowSizeHeight;

        // border vars

        int borderSize;

        // grid positioning fields
        int col,row;

        // the label string this cell has
        // TODO change to have paint provide the cell's data
        //      this allows a cell to just be a structure of fixed size that is used by the grid to produce a cell
        string value;

        // text vars

        // text size of the cell
        int textSize;
        
        // color vars

        // the fill of the cell color when not selected or hovered
        Color fillColor_default;
        // the fill of the cell color when mouse hovered
        Color fillColor_hover;
        // the fill of the cell color when selected
        Color fillColor_selected;

        // the text color when not selected or hovered
        Color textColor_default;
        // the text color when mouse hovered
        Color textColor_hover;
        // the text color when selected
        Color textColor_selected;

        // the color of the border for this cell
        Color borderColor;

        // ==== ==== ==== ====  ==== ==== ==== ==== 
        // constructors/destructors

        // /**
        //  * @brief constructor
        //  * 
        //  */
        // CorbCell(Rectangle spaceIn, int xIdxIn, int yIdxIn);
        /**
         * @brief constructor
         * 
         */
        CorbCell(float &colPosIn, float &rowPosIn, float &colSizeIn, float &rowSizeIn, int xIdxIn, int yIdxIn);

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
        void draw( float drawOffsetX, float drawOffsetY, float veiwOffsetX, float veiwOffsetY, int mouseOverCol, int mouseOverRow );

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
        // the size of the border
        float borderSize;
        // header checkers
        bool hasColHeader,hasRowHeader;
        vector<vector<CorbCell*>> cells;
        
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
        // where we're hovering the mouse
        // -1 when not hovering
        int mouseOverCol, mouseOverRow;

        // ---- ---- ----  ---- ---- ---- 
        // color vars

        // base fill color var
        Color fillColor_default;
        // base border color var
        Color borderColor_default;

        // hover border color var
        Color borderColor_hover;

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
         * @brief get the cell text at the indexed location
         * 
         * @param colIndex col index of the cell to get
         * @param rowIndex row index of the cell to get
         */
        string getText( int colIndex, int rowIndex );
        
        /**
         * @brief get the cell pointer at the indexed location
         * 
         * @param colIndex col index of the cell to get
         * @param rowIndex row index of the cell to get
         */
        CorbCell* getCell( int colIndex, int rowIndex );

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
         * @param currMousePos the position of the mouse in the grid view space,
         *              if -1.0f for both params then it's not within the bounds
         * 
         */
        void draw( Vector2 currMousePos );

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
         * @param mousePosIn the current mouse pos
         * 
         */
        void draw( Vector2 mousePosIn ); // just calculate or dont, what we show for now

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

    // /**
    //  * @brief constructor
    //  * 
    //  */
    // CorbCell::CorbCell(Rectangle spaceIn, int xIdxIn, int yIdxIn){
    //     // initialise the space as instance copy of the spaceIn
    //     space = { spaceIn.x, spaceIn.y, spaceIn.width, spaceIn.height };
    //     // initialise col index
    //     col = xIdxIn;
    //     // initialise row index
    //     row = yIdxIn;
    //     // initialise the value
    //     value = "";
    // }
    /**
     * @brief constructor
     * 
     */
    CorbCell::CorbCell( float &colPosIn, float &rowPosIn, float &colSizeIn, float &rowSizeIn, int xIdxIn, int yIdxIn ) :
        // initialise the address holders for col/row pos/size
        colPosX {colPosIn},
        rowPosY {rowPosIn},
        colSizeWidth {colSizeIn},
        rowSizeHeight {rowSizeIn}
    {
        // initialise border vars

        borderSize = 1;

        // initialise standard vars

        // initialise col index
        col = xIdxIn;
        // initialise row index
        row = yIdxIn;
        // initialise the value
        value = "";

        // initialise the text vars

        textSize = 10;

        // initialise the color vars

        fillColor_default = WHITE;
        fillColor_hover = DARKBLUE;
        fillColor_selected = LIGHTGRAY;

        textColor_default = DARKBLUE;
        textColor_hover = WHITE;
        textColor_selected = DARKBLUE;

        borderColor = BLACK;
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
    void CorbCell::draw( float drawOffsetX, float drawOffsetY, float veiwOffsetX, float veiwOffsetY, int mouseOverCol, int mouseOverRow ){
        #ifdef ANNOUNCE_DRAW_CALL
        cout << ".";
        #endif
        // RAYLIB ONLY version
        // color stores
        Color currFillColor, currTextColor, currBorderColor;
        // if we're hovering
        if( mouseOverCol == col && mouseOverRow == row ){
            // set the colors as the hover vals
            currFillColor = fillColor_hover;
            currTextColor = textColor_hover;
            currBorderColor = borderColor;
        } else {
            // set the colors as the default vals
            currFillColor = fillColor_default;
            currTextColor = textColor_default;
            currBorderColor = borderColor;
        }

        float drawingAtX = drawOffsetX + (colPosX-veiwOffsetX);
        float drawingAtY = drawOffsetY + (rowPosY-veiwOffsetY);

        // // draw the space
        DrawRectangle(
            // pos
            static_cast<int>( drawingAtX ),static_cast<int>( drawingAtY ),
            // size
            static_cast<int>( colSizeWidth ),static_cast<int>( rowSizeHeight ),
            currFillColor
        );
        // draw the outline
        DrawRectangleLines(
            // pos
            static_cast<int>( drawingAtX ),static_cast<int>( drawingAtY ),
            // size
            static_cast<int>( colSizeWidth ),static_cast<int>( rowSizeHeight ),
            currBorderColor
        );

        // declare/initialise the x pos
        int drawTextX = static_cast<int>( drawingAtX + ( borderSize*2 ) );
        // get the y pos ready
        int drawTextY = 0;
        // get the change from top left ready
        float drawTextY_change = ( ( rowSizeHeight - textSize ) / 2.0f );
        // if it's positive change then we add it
        if( drawTextY_change > 0.0f ){
            drawTextY = static_cast<int>( drawingAtY + drawTextY_change );
        }
        // otherwise just make it the pos
        else {
            drawTextY = static_cast<int>( drawingAtY );
        }

        // draw the text
        DrawText(
            getDrawableText().c_str(),
            drawTextX, drawTextY,
            textSize, currTextColor
        );
        // DrawText("TEMPLATE",GetScreenWidth()/2-100,GetScreenHeight()/2,10,BLACK);

        // RAYGUI version
        // // draw the cell background
        // GuiDrawRectangle(space,borderSize,DARKGRAY,WHITE);
        // // draw the text
        // GuiLabel( space, getDrawableText().c_str() );
        // // what it calls
        // GuiDrawText(text, GetTextBounds(LABEL, bounds), GuiGetStyle(LABEL, TEXT_ALIGNMENT), Fade(GetColor(GuiGetStyle(LABEL, TEXT + (state*3))), guiAlpha));
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

        // initialise border size data member
        borderSize = 3.0f;

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
        // setup the mouse vars
        mouseOverCol = -1;
        mouseOverRow = -1;

        // initialise our boolean for col header
        hasColHeader = true;
        // initialise our boolean for row header
        hasRowHeader = false;
        // now setup the cells thingy

        // comment out the cells initialisation
        // for every row
        for( int currRow = 0; currRow < rowCount; currRow++ ){
            // initialise the row list
            vector<CorbCell*> currCellRow;

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
                // initialise the curr cell instance pointer
                CorbCell *currCell = new CorbCell( colPos[ currCol ], rowPos[ currRow ], colSize[ currCol ], rowSize[ currRow ], currCol, currRow );

                // push to the row list
                currCellRow.push_back( currCell );
            }

            // push the row to the overall cells list
            cells.push_back( currCellRow );
        }

        // setup color data members

        fillColor_default = LIGHTGRAY;
        borderColor_default = BLACK;

        borderColor_hover = DARKBLUE;

    }

    // ---- ---- ---- ----  ---- ---- ---- ---- 

    /**
     * @brief destructor
     * 
     */
    CorbGrid::~CorbGrid(){
        // delete all the cells

        for(int y = 0; y < rowCount; y++ ){
            for(int x = 0; x < colCount; x++){
                delete cells[y][x];
            }
        }

    }

    // ---- ---- ---- ----  ---- ---- ---- ----

    /**
     * @brief get the cell text at the indexed location
     * 
     * @param colIndex col index of the cell to get
     * @param rowIndex row index of the cell to get
     */
    string CorbGrid::getText( int colIndex, int rowIndex ){
        return cells[rowIndex][colIndex]->getText();
    }

    /**
     * @brief get the cell pointer at the indexed location
     * 
     * @param colIndex col index of the cell to get
     * @param rowIndex row index of the cell to get
     */
    CorbCell* CorbGrid::getCell( int colIndex, int rowIndex ){
        return cells[rowIndex][colIndex];
    }

    /**
     * @brief set the cell pointer at the indexed location
     * 
     * @param colIndex col index of the cell to set
     * @param rowIndex row index of the cell to set
     */
    void CorbGrid::setCell( int colIndex, int rowIndex, string valueIn ){
        cells[rowIndex][colIndex]->setText( valueIn );
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
     * @param currMousePos the position of the mouse in the grid view space,
     *              if -1.0f for both params then it's not within the bounds
     * 
     */
    void CorbGrid::draw( Vector2 currMousePos ){
        #ifdef ANNOUNCE_DRAW_CALL
        cout << "grid draw call" << endl;
        #endif
        // draw the grid background/border
        GuiDrawRectangle(space,static_cast<int>(borderSize),borderColor_default,fillColor_default);
        // make the mouse relative to the grid by trimming off the grid position and border size
        currMousePos.x -= ( space.x + borderSize );
        currMousePos.y -= ( space.y + borderSize );
        // for every row fully within the veiw space
        for( int currRow = veiwingRow; ( currRow < rowCount ) &&
            ( ( rowPos[currRow] + rowSize[currRow] ) - rowPos[ veiwingRow ] ) < space.height-(borderSize*2.0f); currRow++ ){
            // for every col fully within the veiw space
            for( int currCol = veiwingCol; ( currCol < colCount ) &&
            ( ( colPos[currCol] + colSize[currCol] ) - colPos[ veiwingCol ] ) < space.width-(borderSize*2.0f); currCol++ ){
                // check if our mouse is inside the position of the cell
                if( ((currMousePos.x+colPos[ veiwingCol ] >= colPos[currCol])                 && (currMousePos.y+rowPos[ veiwingRow ] >= rowPos[currRow])) &&
                    ((currMousePos.x+colPos[ veiwingCol ] < colPos[currCol]+colSize[currCol]) && (currMousePos.y+rowPos[ veiwingRow ] < rowPos[currRow]+rowSize[currRow])) ){
                    // we're hovering this cell
                    mouseOverCol = currCol;
                    mouseOverRow = currRow;
                }
                else{
                    mouseOverCol = -1;
                    mouseOverRow = -1;
                }
                // tell the cell to draw
                cells[currRow][currCol]->draw( space.x+borderSize, space.y+borderSize, colPos[veiwingCol], rowPos[veiwingRow], mouseOverCol, mouseOverRow );
                // // prepare the current cell space
                // Rectangle currCellSpace {
                //     colPos[currCol] - colPos[ veiwingCol] + space.x,
                //     rowPos[currRow] - rowPos[ veiwingRow] + space.y,
                //     colSize[currCol],
                //     rowSize[currRow],
                // };

                // // RAYGUI version
                // // draw the cell background
                // GuiDrawRectangle( currCellSpace, 1, DARKGRAY, WHITE );
                // // draw the text
                // GuiLabel( currCellSpace, getDrawableText( getCell( currCol, currRow ) ).c_str() );

            }
        }
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
     * @param mousePosIn the current mouse pos
     * 
     */
    void CorbSheet::draw( Vector2 mousePosIn ){
        #ifdef ANNOUNCE_DRAW_CALL
        cout << endl << "sheet draw call" << endl;
        #endif
        // prepare the mouse pos
        Vector2 giveableMousePos = { mousePosIn.x, mousePosIn.y };
        // calculate if it's inside bounds
        if(
            ( ( mousePosIn.x < grid->space.x ) && 
              ( mousePosIn.y < grid->space.y ) )       &&
            ( ( mousePosIn.x >= grid->space.x+grid->space.width ) &&
              ( mousePosIn.y >= grid->space.y+grid->space.height ) )
        ){
            giveableMousePos = { -1.0f, -1.0f };
        }
        // do the draw handoff
        grid->draw( giveableMousePos );
    }

    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
    // ==== ==== ==== ====  ==== ==== ==== ====  ==== ==== ==== ====  
}