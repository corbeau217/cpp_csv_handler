<!-- ===================================================================================== -->
<!-- ===================================================================================== -->
<!--                                                                                       -->
<!--        Project:    cpp_csv_handler                                                    -->
<!--         Branch:    main                                                               -->
<!--        Created:    2023-01-13                                                         -->
<!--    Last update:    2023-01-14                                                         -->
<!--         Author:    Corbeau217                                                         -->
<!--                                                                                       -->
<!--        Repo URL:                                                                      -->
<!-- https://github.com/corbeau217/cpp_csv_handler/                                        -->
<!--                                                                                       -->
<!-- ===================================================================================== -->
<!-- ===================================================================================== -->

<h1> Corb's c++ csv file handler </h1>

<!-- ===================================================================================== -->
<hr /><!-- =============================================================================== -->
<!-- ===================================================================================== -->

<h2>Summary</h2>
<code>sub project of the animal crossing project to handle csv files using raylib and raygui</code>

<!-- ===================================================================================== -->
<hr /><!-- =============================================================================== -->
<!-- ===================================================================================== -->

<h2>Useful to user</h2>
<code>At some point we should update this section to include information useful to users of this client</code>
<!-- add in to this section information about the folders needed and placement of files -->
<!-- folders needed in workspace folder: build, external, resources -->
<!--    inside 'external' folder we need the 'raygui-3.2', and 'raylib-4.2.0', for cmake -->

<!-- ===================================================================================== -->
<hr /><!-- =============================================================================== -->
<!-- ===================================================================================== -->

<h2>Notices / Changes</h2>
<!-- notices / changes dropdown -->
<details>
    <summary><i>show / hide</i></summary>
    <ul>
        <li><code>[from source project README.md relating to this code]</code>
            <ul>
                <li>
                    <details>
                        <summary>[ show / hide ]</summary>
                        <ul>
                            <!-- ======================================== -->
                            <!-- ======= change notes from origin ======= -->
                            <!-- ======================================== -->
                            <li><code>[24/12/22]</code> ---> <i>ported readme from <code>cpp_newer_modeller</code> (private repo at the time)</i>
                                <details>
                                    <summary><i>show / hide</i></summary>
                                    <ul>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                        <li><code>[12:27am]</code> ---> <i>started working on cmake handling of raylib and raygui</li>
                                        <li><code>[03:25am]</code> ---> <i><a href="https://media.tenor.com/tWZeezTVHwQAAAAC/jarjar-binks.gif"><code>mygiveupjarjar.gif</code></a> no more pre-fetching the packages for now, just download them myself yemstve, we goto the store first bc need a break or brain will break</i></li>
                                        <li><code>[04:55am]</code> ---> <i>we got it working with cmake and provided libraries</i></li>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                    </ul>
                                </details>
                            </li>
                            <li><code>[25/12/22] to [28/12/22][07:03pm]</code> ---> <i>CSV file reader handle added which took some effort and planning but was constructed really haphazardly so maybe need revisiting</i></li>
                            <li><code>[28/12/22]</code> ---> <i>additional changes after finishing CSV file reader</i>
                                <details>
                                    <summary><i>show / hide</i></summary>
                                    <ul>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                        <li><code>[07:03pm]</code> ---> <i>added include statement for <code>CSVRead.hpp</code></i></li>
                                        <li><code>[07:03pm]</code> ---> <i>will need a list of the CSV files and then can begin working on something to search them for similarities</i></li>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                    </ul>
                                </details>
                            </li>
                            <li><code>[30/12/22]</code> ---> <i>setting up data handles</i>
                                <details>
                                    <summary><i>show / hide</i></summary>
                                    <ul>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                        <li><code>[07:34pm]</code> ---> <i>added in stubs for data handle and ideas as comments</i></li>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                    </ul>
                                </details>
                            </li>
                            <li><code>[31/12/22]</code> ---> <i>we making a spreadsheet thinger</i>
                                <details>
                                    <summary><i>show / hide</i></summary>
                                    <ul>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                        <li><code>[01:12pm]</code> ---> <i>we start the structure i guess</i></li>
                                        <li><code>[03:10pm]</code> ---> <i>eyes glazed over from this tutorial, so stopped trying to library in cmake for now, just hardcoding it:</i>
                                            <ul>
                                                <li><a href="https://decovar.dev/blog/2021/03/08/cmake-cpp-library/">tutorial in question</a></li>
                                            </ul>
                                        </li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[04:17pm]</code> ---> <i>added in some stubs for <code>CorbSheet</code>, which will have:</i>
                                            <ul>
                                                <li><i><code>CorbCell</code>: holds our drawn content for values</i></li>
                                                <li><i><code>CorbGrid</code>: holds our <code>CorbCell</code> instances</i></li>
                                                <li><i><code>CorbSheet</code>: project specialised <code>Client</code> class</i></li>
                                            </ul>
                                        </li>
                                        <li><code>[04:19pm]</code> ---> <i>still need to add in code for handling csv data and putting it into our grid</i></li>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                    </ul>
                                </details>
                            </li>
                            <li><code>[01/01/23]</code> ---> <i>cleaning up <code>CSVRead</code> errors</i>
                                <details>
                                    <summary><i>show / hide</i></summary>
                                    <ul>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                        <li><code>[12:07pm]</code> ---> <i>fixed up issue with signature of <code>CSV::getTokenList</code> not having correct parameters for both definition and declaration</i></li>
                                        <li><code>[12:07pm]</code> ---> <i>moved <code>static</code> methods of <code>CSV::Handler</code> to namespace scope</i></li>
                                        <li><code>[12:07pm]</code> ---> <i>fixed issue with <code>CSV::getFilestreamLines</code> not keeping the reference of the <code>ifstream</code> parameter by changing to pass by address</i></li>
                                        <li><code>[12:07pm]</code> ---> <i>changed <code>CSV::getTokenList</code> to have <code>currChar</code> as string, and cleaned up the conditionals relating to it</i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[01:03pm]</code> ---> <i>completed <code>Main.cpp::getTableObjects</code></i></li>
                                        <li><code>[01:07pm]</code> ---> <i>began work on <code>Main.cpp::getTableHeaderLists</code></i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[01:20pm]</code> ---> <i>updated <code>CSV::Handler::get</code> to use <code>col/row</code> instead of <code>x/y</code></i></li>
                                        <li><code>[01:23pm]</code> ---> <i>finished <code>Main.cpp::getTableHeaderLists</code></i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[01:35pm]</code> ---> <i>added in <code>Main.cpp::listHasItem</code> for searching a list for an exact match to a string</i></li>
                                        <li><code>[01:42pm]</code> ---> <i>completed definition of <code>Main.cpp::getUniqueFieldsList</code></i></li>
                                        <li><code>[02:05pm]</code> ---> <i>completed definition of <code>Main.cpp::getTablesContainingFieldList</code></i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[02:54pm]</code> ---> <i>completed construction of code including testing code in <code>Main.cpp::main</code></i></li>
                                        <li><code>[03:26pm]</code> ---> <i>fixed issue in <code>CSV::Handle::process()</code></i></li>
                                        <li><code>[03:48pm]</code> ---> <i>fixed <code>CSV::getTokenStackAsString</code> and <code>CSV::getCSVTokenList</code> not correctly accessing chars/strings</i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[03:57pm]</code> ---> <i>added code to <code>CSV::Handler::process()</code> to tidy up incomplete rows</i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[04:07pm]</code> ---> <i>currently code runs and works, but to have the output/dump for fields or tables you need to define <code>DUMP_ALL_TABLE_DATA</code> for tables, and <code>DUMP_ALL_FIELD_DATA</code> for fields</i></li>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                    </ul>
                                </details>
                            </li>
                            <li><code>[05/01/23]</code> ---> <i>declaration and definitions of the <code>CorbSheet</code> stuff</i>
                                <details>
                                    <summary><i>show / hide</i></summary>
                                    <ul>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                        <li><code>[02:55pm]</code> ---> <i>finished basic declarations for the <code>CorbSheet</code> situation</i></li>
                                        <li><code>[03:00pm]</code> ---> <i>cleaned up the <code>./Main.cpp</code> to use preprocessor definitions for choosing what code is run</i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[03:06pm]</code> ---> <i>added in some code to use the <code>CorbSheet</code> code as part of <code>Main.cpp::appHandle()</code></i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[03:16pm]</code> ---> <i>modified cell draw structure to use more raygui functions and provided a non raygui implementation commented out</i></li>
                                        <li><code>[03:16pm]</code> ---> <i>setup the CSV processing code to be used based on preprocessor value to speed up testing of the GUI code</i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[03:23pm]</code> ---> <i>completed the implementation of basic <code>CorbSheet</code> and verified that it is working as intended, however the text size is too large and the cells are too small</i></li>
                                        <li><code> ----- ----- ----- ----- ----- </code></li>
                                        <li><code>[03:36pm]</code> ---> <i>added some tasks to <code>./docs/README.md</code> tasks section</i></li>
                                        <li><code>[04:11pm]</code> ---> <i>completed merging stale branch structure back to main branch in github repositiory</i></li>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                    </ul>
                                </details>
                            </li>
                            <li><code>[10/01/23]</code> ---> <i>improvements and changes to <code>CorbSheet</code>/<code>CorbTable</code></i>
                                <details>
                                    <summary><i>show / hide</i></summary>
                                    <ul>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                        <li><code>[01:03pm]</code> ---> <i>added in some documentation to <code>README.md</code> for contained sub projects</i></li>
                                        <li><code>[01:03pm]</code> ---> <i>hypothesized a change to the name of our library for handling the data</i></li>
                                        <li><code>[01:11pm]</code> ---> <i>added a summary of written ideas to the ideas section of <code>README.md</code></i></li>
                                        <li><code> ===== ===== ===== ===== ===== </code></li>
                                    </ul>
                                </details>
                            </li>
                        </ul>
                    </details>
                </li>
            </ul>
        </li>
        <!-- ======================================== -->
        <!-- === beginning of notes for this repo === -->
        <!-- ======================================== -->
        <li><code>[13/01/23]</code> ---> <i>port from <code>cpp_csv_handle</code></i>
            <details>
                <summary><i>show / hide</i></summary>
                <ul>
                    <li><code> ===== ===== ===== ===== ===== </code></li>
                    <li><code>[11:57am]</code> ---> <i>completed restructure of notices section of <code>README.md</code> and copied across some of the file structur</i></li>
                    <li><code>[12:09pm]</code> ---> <i>completed porting of files and cmake configure</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[02:53pm]</code> ---> <i> began refactoring the <code>CorbSheet.hpp</code> to use our new formatting</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[05:23pm]</code> ---> <i>changed the <code>CorbGrid</code> to no longer using a cell instance</i></li>
                    <li><code>[05:23pm]</code> ---> <i>added in a task for suggested cell data handle holding references to the col/row</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[00:00pm]</code> ---> <i></i></li>
                    <li><code> ===== ===== ===== ===== ===== </code></li>
                </ul>
            </details>
        </li>
        <li><code>[14/01/23]</code> ---> <i>minor changes</i>
            <details>
                <summary><i>show / hide</i></summary>
                <ul>
                    <li><code> ===== ===== ===== ===== ===== </code></li>
                    <li><code>[04:10am]</code> ---> <i>fixed bug in cell drawing where they werent offset by grid view space position</i></li>
                    <li><code>[01:14pm]</code> ---> <i>removed some of the TODO statements in <code>CorbCell</code></i></li>
                    <li><code>[01:14pm]</code> ---> <i>changed the window title to be correct for current project</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[01:17pm]</code> ---> <i>changed <code>README.md</code> to strikethrough the tasks complete</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[01:32pm]</code> ---> <i>added in <code>RefSpace</code> which is a copy of <code>raylib</code>'s <code>Rectangle</code> structure but takes references</i></li>
                    <li><code>[01:32pm]</code> ---> <i>prepared directory for initial repository push to track further changes during spelling correction/refactoring to have cell use references</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[02:04pm]</code> ---> <i>added a testing section to <code>./Main.cpp</code></i></li>
                    <li><code>[03:07pm]</code> ---> <i>provided some tested data for address containers in <code>./Main.cpp</code></i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[00:00pm]</code> ---> <i></i></li>
                    <li><code>[00:00pm]</code> ---> <i></i></li>
                    <li><code> ===== ===== ===== ===== ===== </code></li>
                </ul>
            </details>
        </li>
        <li><code>[16/01/23]</code> ---> <i>reimplementing the <code>CorbCell</code> objects</i>
            <details>
                <summary><i>show / hide</i></summary>
                <ul>
                    <li><code> ===== ===== ===== ===== ===== </code></li>
                    <li><code>[01:51pm]</code> ---> <i>restructured <code>CorbCell</code> to use a shared reference member for position/size based on col/row</i></li>
                    <li><code>[01:51pm]</code> ---> <i>restructured <code>CorbCell</code> draw method to use <code>raylib</code> methods so each cell isnt required to have a rectangle member</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[00:00pm]</code> ---> <i></i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[00:00pm]</code> ---> <i></i></li>
                    <li><code>[00:00pm]</code> ---> <i></i></li>
                    <li><code> ===== ===== ===== ===== ===== </code></li>
                </ul>
            </details>
        </li>
        <li><code>[17/01/23]</code> ---> <i>changes on this day</i>
            <details>
                <summary><i>show / hide</i></summary>
                <ul>
                    <li><code> ===== ===== ===== ===== ===== </code></li>
                    <li><code>[11:52am]</code> ---> <i>changed some minor things in <code>README.md</code></i></li>
                    <li><code>[12:15pm]</code> ---> <i>added in containers for color/border size/text size to the cell objects</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[01:16pm]</code> ---> <i>changed over to having variable and offsetting the drawing of cells correctly (not including grid border size)</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[02:27pm]</code> ---> <i>removed defunct overloading of grid's draw method</i></li>
                    <li><code>[02:27pm]</code> ---> <i>provided functionality for mouse hovering and mouse selection and made the position provided to grid as relative to the view space</i></li>
                    <li><code> ----- ----- ----- ----- ----- </code></li>
                    <li><code>[00:00pm]</code> ---> <i></i></li>
                    <li><code>[00:00pm]</code> ---> <i></i></li>
                    <li><code> ===== ===== ===== ===== ===== </code></li>
                </ul>
            </details>
        </li>
        <li></li>
        <li></li>
    </ul>
</details>

<!-- ===================================================================================== -->
<hr /><!-- =============================================================================== -->
<!-- ===================================================================================== -->

<h2>Plans</h2>
<!-- Plans dropdown -->
<details>
    <summary><i>show / hide</i></summary>
    <ul>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
    </ul>
</details>

<!-- ===================================================================================== -->
<hr /><!-- =============================================================================== -->
<!-- ===================================================================================== -->

<h2>Ideas</h2>
<!-- Ideas dropdown -->
<details>
    <summary><i>show / hide</i></summary>
    <ul>
        <li><code> ===== ===== ===== ===== ===== </code></li>
        <li><code>[from source project README.md relating to this code]</code>
            <ul>
                <li>
                    <details>
                        <summary>[ show / hide ]</summary>
                        <ul>
                            <!-- ======================================== -->
                            <!-- ========== Ideas from origin  ========== -->
                            <!-- ======================================== -->
                            <li><code>[10/01/23][01:05pm]</code> ---> <i>change to the structure of our <code>CorbSheet</code> code:</i>
                                <ul>
                                    <li><s>has offset for position of drawing pixels</s></li> <!-- ye -->
                                    <li><i>uses drawable structure from other projects</i></li>
                                    <li><s>calculates a cell's position and size when the table is loaded</s></li> <!-- ye -->
                                    <li><i>change to file formatting</i>
                                        <ul>
                                            <li><i>use some sort of seperator for each table contained in a file including table name</i></li>
                                            <li><i>maybe also include the table sizing in that header</i></li>
                                            <li><i>have a line that says the character limit of each column after the column names</i></li>
                                            <li><i>modularise the concept of the table for the different parts?</i></li>
                                            <li><i></i></li>
                                        </ul>
                                    </li>
                                    <li><i>have the header row as seperately stored to the table entries</i></li>
                                    <li><i>each cell is given the data that it draws by the table? when we do concurrent stuff</i></li>
                                    <li><i>have a cell as just a structure for relative position and size</i></li>
                                    <li><i></i></li>
                                </ul>
                            </li>
                        </ul>
                    </details>
                </li>
            </ul>
        </li>
        <!-- ======================================== -->
        <!-- === beginning of ideas for this repo === -->
        <!-- ======================================== -->
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[13/01/23][05:28pm]</code> ---> <s>change the cell structure to be holding references for positioning, where the references are to data held in grid shared for a column or a row</s></li> <!-- ye -->
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code> ===== ===== ===== ===== ===== </code></li>
    </ul>
</details>

<!-- ===================================================================================== -->
<hr /><!-- =============================================================================== -->
<!-- ===================================================================================== -->

<h2>Tasks</h2>
<!-- tasks dropdown -->
<details>
    <summary><i>show / hide</i></summary>
    <ul>
        <li><code> ===== ===== ===== ===== ===== </code></li>
        <li><code>[from source project README.md relating to this code]</code>
            <ul>
                <li>
                    <details>
                        <summary>[ show / hide ]</summary>
                        <ul>
                            <!-- ======================================== -->
                            <!-- ========== Tasks from origin  ========== -->
                            <!-- ======================================== -->
                            <li><code>[05/01/23][03:27pm]</code> ---> <i>add in some more functionality to <code>CorbSheet</code></i>
                                <details>
                                    <summary><i>[ show / hide ]</i></summary>
                                    <ul>
                                        <li><i><code>CorbCell</code> member variables for:</i>
                                            <ul>
                                                <li><i>hover color</i></li>
                                                <li><i>background/border color</i></li>
                                                <li><i>text color</i></li>
                                            </ul>
                                        </li>
                                        <li><i><code>CorbGrid</code> member variables for:</i>
                                            <ul>
                                                <li><i>hover col/row index</i></li>
                                                <li><i>background/border color</i></li>
                                                <li><s><code>colWidthPx</code> as a list</s></li> <!-- ye -->
                                            </ul>
                                        </li>
                                        <li><i><code>CorbSheet</code> code handle for:</i>
                                            <ul>
                                                <li><s>veiwing col/row index and veiwing col/row count code</s></li> <!-- ye -->
                                                <li><i>mouse position translation to viewing row/col index</i></li>
                                                <li><i>data handle inputing into the grid instance from 2D list of strings</i></li>
                                            </ul>
                                        </li>
                                        <li><i></i></li>
                                    </ul>
                                </details>
                            </li>
                        </ul>
                    </details>
                </li>
            </ul>
        </li>
        <!-- ======================================== -->
        <!-- === beginning of tasks for this repo === -->
        <!-- ======================================== -->
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[13/01/23][02:53pm]</code> ---> <code>CorbGrid</code> ---> <s>change column size and row size to list</s></li> <!-- ye -->
        <li><code>[13/01/23][02:53pm]</code> ---> <code>CorbGrid</code> ---> <s>add in the position vars as list for col and row</s></li> <!-- ye -->
        <li><code>[13/01/23][02:53pm]</code> ---> <code>CorbGrid</code> ---> <s>add in 2D vector of strings</s></li> <!-- ye -->
        <li><code>[13/01/23][02:53pm]</code> ---> <code>CorbGrid</code> ---> <s>change draw to using the new available values instead of the <code>CorbCell</code> instances</s></li> <!-- ye -->
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[13/01/23][03:56pm]</code> ---> <code>CorbGrid</code> ---> <s>have the veiwing things calculated as asking if they're inside the veiwing space</s></li> <!-- ye -->
        <!-- ---------------------------------------- -->
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[13/01/23][05:09pm]</code> ---> <code>CorbGrid</code> ---> <i>change to using a <code>CorbRectangle</code> or <code>CorbCellDrawLocation</code></i></li>
        <li><code>[16/01/23][01:05pm]</code> ---> <code>CorbCell</code> ---> <i>using the float address containers for shared memory by column/row</i></li>
        <li><code>[16/01/23][01:15pm]</code> ---> <code>CorbCell</code> ---> <i>needs to also do the same for the column/row index</i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[14/01/23][01:19pm]</code> ---> <code>[cpp_csv_handler]</code> ---> <i>get cmake to treat our code sections as static libraries correctly</i></li>
        <li><code> ===== ===== ===== ===== ===== </code></li>
    </ul>
</details>

<!-- ===================================================================================== -->
<hr /><!-- =============================================================================== -->
<!-- ===================================================================================== -->

<h2>Issues</h2>
<!-- Issues dropdown -->
<details>
    <summary><i>show / hide</i></summary>
    <ul>
        <li><code> ===== ===== ===== ===== ===== </code></li>
        <li><code>[14/01/23][01:36pm]</code> ---> <i>cell drawing isnt inside the border of the grid due to border going inwards from boundary pixels</i></li>
        <li><code>[14/01/23][01:36pm]</code> ---> <i>text in cell is too far to the left</i></li>
        <li><code>[14/01/23][01:36pm]</code> ---> <i>text in cell isnt properly shortened to the cell size</i>
            <ul>
                <li><i>( font isnt monospace so would need to be calculated from each font's glyph size )</i></li>
            </ul>
        </li>
        <li><code>[14/01/23][01:36pm]</code> ---> <i>currently cell isnt its own instance to improve code speed but should be used with references to shared data fields in column/row</i></li>
        <li><code>[16/01/23][01:13pm]</code> ---> <i>cell also doesnt share the memory for column index or row index</i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[14/01/23][01:42pm]</code> ---> <i>border is a magic number for cells and grid</i></li>
        <li><code>[14/01/23][01:42pm]</code> ---> <i>no color storage for any ui elements, using magic color values</i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[14/01/23][01:42pm]</code> ---> <i>incorrect spelling of "view" throughout the project as "veiw"</i></li>
        <li><code>[14/01/23][01:42pm]</code> ---> <i>old TODO statements in code that should be updated</i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[14/01/23][01:42pm]</code> ---> <i>no mouse tracking</i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[16/01/23][01:51pm]</code> ---> <i>draws cells from top left without offsetting by grid position</i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code>[00/01/23][00:00xx]</code> ---> <i></i></li>
        <li><code> ===== ===== ===== ===== ===== </code></li>
    </ul>
</details>

<!-- ===================================================================================== -->
<hr /><!-- =============================================================================== -->
<!-- ===================================================================================== -->

<h2>Resources</h2>
<!-- Resources dropdown -->
<details>
    <summary><i>show / hide</i></summary>
    <ul>
        <li><code> ===== ===== ===== ===== ===== </code></li>
        <li><i>C++ resources</i>
            <details>
                <summary><i>show / hide</i></summary>
                <ul>
                    <li><a href="https://github.com/raysan5/raylib">raylib</a> [<code>raysan5</code>]</li>
                    <li><a href="https://github.com/raysan5/raygui">raygui</a> [<code>raysan5</code>]</li>
                    <li><a href="https://github.com/Treeki/imgui">dear imgui</a> [<code>Ash Wolf (@_Ninji)</code>]</li>
                    <li><a href="https://github.com/Treeki/VulpIRC">VulpIRC</a> [<code>Ash Wolf (@_Ninji)</code>]</li>
                    <li><a href="https://github.com/Treeki/GenericIRC">GenericIRC</a> [<code>Ash Wolf (@_Ninji)</code>]</li>
                    <li><a href="https://github.com/WerWolv/ImHex">ImHex editor thingy</a> <i>[remember how we thought of this and then got distracted?]</i></li>
                    <li><a href="https://github.com/bkaradzic/bgfx">some rendering thingy?</a> <i>seems neat</i></li>
                    <li><a href="https://learn.microsoft.com/en-us/cpp/standard-library/file-system-navigation?view=msvc-170#paths">has some neat stuff about paths</a></li>
                    <li><a href=""></a></li>
                    <li><a href=""></a></li>
                </ul>
            </details>
        </li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><i>source database used in this project</i>
            <ul>
                <li><a href="https://docs.google.com/spreadsheets/d/13d_LAJPlxMa_DubPTuirkIV4DERBMXbrWQsmSh8ReK4/edit">masterdoc google sheets link</a></li>
                <li><a href="https://cdn.acnhapi.com/">acnh api link</a></li>
            </ul>
        </li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><i></i>
            <ul>
                <li><a href=""></a></li>
                <li><a href=""></a></li>
                <li><a href=""></a></li>
            </ul>
        </li>
        <li><code> ----- ----- ----- ----- ----- </code></li>
        <li><i></i></li>
        <li><i></i></li>
        <li><code> ===== ===== ===== ===== ===== </code></li>
    </ul>
</details>

<!-- ===================================================================================== -->
<hr /><!-- =============================================================================== -->
<!-- ===================================================================================== -->