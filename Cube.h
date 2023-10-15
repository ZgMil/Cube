
/** \brief Rubik's Cube class implementation
 *\author Milena Zgurskaya
 *\date semptember 2019
 */
class Cube;
class Verge;
namespace rcn{
	const int blue=0;
	const int green=1;
	const int cyan=2;
	const int red=3;
	const int magenta=4;
	const int white=5;
    const int rightR=0;
    const int leftR=1;
}
using namespace rcn;


/** Simple class representing a singular cell of a cube. Has a color, represented by an integer. Is friends
 *  with Cube and Verge classes, so that private values wouldn't be accessible from anywhere else than Cube or Verge.*/  
class Cell{
        int color;
        friend class Verge;
        friend class Cube;
    };
/** Class representing a singular verge of a cube. Is derived form the Cell class. Consists of 3x3 Cell array. Is friends
 *  with Cube class, so that private values wouldn't be accessible from anywhere else than Cube.*/  
class Verge:Cell{
    Cell grid[3][3];
    friend class Cube;
/** Private function that rotates the verge, is only used as a part of public wheel rotation functions.
 *  \param direction Direction of rotation, right or left*/ 
    void rotateVerge(bool direction);
    bool check();
    
    };
/** Cube class that represents a cube as a whole. Is derived from Verge class. Consists of 6 verges.*/ 
class Cube:Verge{
        Verge front;
        Verge back;
        Verge top;
        Verge bottom;
        Verge left;
        Verge right;
    public: 
/** Constructor. Fills cells with appropriate colors.*/
    Cube(){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                front.grid[i][j].color=magenta;
                back.grid[i][j].color=white;
                top.grid[i][j].color=blue;
                bottom.grid[i][j].color=cyan;
                left.grid[i][j].color=red;
                right.grid[i][j].color=green;
                }   
    }
        
    /** Public function that checks if all sides have been completed. Returns true or false.*/
    bool check();
    /** Public function that scrambles the cube's sides.*/ 
    void randomize();
    /** Public function that rotates the wheel of the cube up in X Z plane.
     * \param wheel Position of the rotating wheel*/
    void front_up(int wheel);
    /** Public function that rotates the wheel of the cube down in X Z plane.
     * \param wheel Position of the rotating wheel*/
    void front_down(int wheel);
    /** Public function that rotates the wheel of the cube right in X Y plane.
     * \param wheel Position of the rotating wheel*/
    void front_right(int wheel);
    /** Public function that rotates the wheel of the cube left in X Y plane.
     * \param wheel Position of the rotating wheel*/
    void front_left(int wheel);
    /** Public function that rotates the wheel of the cube right in Y Z plane.
     * \param wheel Position of the rotating wheel*/
    void up_right(int wheel);
    /** Public function that rotates the wheel of the cube left in Y Z plane.
     * \param wheel Position of the rotating wheel*/
    void up_left(int wheel);
    /** Public function that gets input in array and writes it into the cube 
     * \param temp Array of values of cube*/
    int *out();
    /** Public function that reads cube's state from file. 
     * \param name Name of the save file*/    
    void read(const std::string &name);
    /** Public function that saves cube's state into file.
     * \param name Name of the save file*/  
    void write(const std::string &name);   
};
