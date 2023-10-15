#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Cube.h"
using namespace rcn;
/** size-Is a dimension of cube(3x3),inv-A value from which you need to substract to make incrementation to size go in the opposite direction.*/  
const int size=3,inv=2;
/** Rotates verge in given direction by rearranging an array.*/  
void Verge::rotateVerge(bool direction){
    Cell temp[size][size];
    for(int i=0;i<size;i++)
    for(int j=0;j<size;j++) temp[i][j]=this->grid[i][j];        
    switch(direction){
        case 0:
            for(int i=0;i<size;i++)
            for(int j=0;j<size;j++) this->grid[i][j]=temp[j][inv-i];             
        break;
        case 1:
            for(int i=0;i<size;i++)
            for(int j=0;j<size;j++) this->grid[i][j]=temp[inv-j][i];            
        break;
    }
}
    /** Rearranges array elements of 4 arrays using temp Cell array. Copies a slice of the top verge into temp.
      * This slice of top verge is then replaced by corresponding slice of left side,
      * which is then replaced by corresponding slice of the bottom verge, which is then replaced by corresponding
      * slice of the right verge, which is then replaced by the temp. If rotating wheel is located next to the front verge,
      * front verge rotates right, if it's located next to the back verge, back verge rotates left.*/  
void Cube::up_right(int wheel){
    Cell temp[size];
        for (int i=0;i<size;i++) temp[i]=top.grid[wheel][i];
    
		for(int i=0;i<size;i++){
    		top.grid[wheel][i]=left.grid[wheel][i];
            left.grid[wheel][i]=bottom.grid[wheel][i];
            bottom.grid[wheel][i]=right.grid[wheel][i];
            right.grid[wheel][i]=temp[i];
        }
    switch(wheel){
        case 0: front.rotateVerge(rightR); break;      
        case 1: return; break;         
        case 2: back.rotateVerge(leftR); break;       
    }
}
    /** Rearranges array elements of 4 arrays using temp Cell array. Copies a slice of the top verge into temp.
      * This slice of top verge is then replaced by corresponding slice of right side,
      * which is then replaced by corresponding slice of the bottom verge, which is then replaced by corresponding
      * slice of the left verge, which is then replaced by the temp. If rotating wheel is located next to the front verge,
      * front verge rotates left, if it's located next to the back verge, back verge rotates right.*/  
void Cube::up_left(int wheel){
    Cell temp[size];
        for (int i=0;i<size;i++) temp[i]=top.grid[wheel][i];
    
        for(int i=0;i<size;i++){  
            top.grid[wheel][i]=right.grid[wheel][i];
            right.grid[wheel][i]=bottom.grid[wheel][i];
            bottom.grid[wheel][i]=left.grid[wheel][i];
            left.grid[wheel][i]=temp[i];
        }    
    switch(wheel){
        case 0: front.rotateVerge(leftR); break;        
        case 1: return; break;           
        case 2: back.rotateVerge(rightR); break;
    }
}
    /** Rearranges array elements of 4 arrays using temp Cell array. Copies a slice of the front verge.
      * This slice of front is then replaced by corresponding slice of the bottom verge,
      * which is then replaced by corresponding slice of the back verge, which is then replaced by the corresponding
      * slice of the top verge, which is then replaced by temp. If rotated wheel is located next to the left verge,
      * left verge rotates left, if it's located next to the right verge, right verge rotates right.*/   
void Cube::front_up(int wheel){
    Cell temp[size];
    for (int i=0;i<size;i++) temp[i] =front.grid[i][wheel]; 
    for (int i=0;i<size;i++){
        front.grid[i][wheel]=bottom.grid[i][inv-wheel];
        bottom.grid[i][inv-wheel]=back.grid[inv-i][inv-wheel];
        back.grid[inv-i][inv-wheel]=top.grid[inv-i][wheel];
        top.grid[inv-i][wheel]=temp[i];
    }
    switch(wheel){
        case 0: left.rotateVerge(leftR); break; 
        case 1: return; break; 
        case 2: right.rotateVerge(rightR); break;
       
    }
}
    /** Rearranges array elements of 4 arrays using temp Cell array. Copies a slice of the front verge.
      * This slice of front is then replaced by corresponding slice of the top verge,
      * which is then replaced by corresponding slice of the back verge, which is then replaced by the corresponding
      * slice of the bottom verge, which is then replaced by temp. If rotated wheel is located next to the left verge,
      * left verge rotates right, if it's located next to the right verge, right verge rotates left.*/   
void Cube::front_down(int wheel){
    Cell temp[size];
    for (int i=0;i<size;i++) temp[i] =front.grid[i][wheel];
    for (int i=0;i<size;i++){
        front.grid[i][wheel]=top.grid[inv-i][wheel];
        top.grid[inv-i][wheel]=back.grid[inv-i][inv-wheel];
        back.grid[inv-i][inv-wheel]=bottom.grid[i][inv-wheel];
        bottom.grid[i][inv-wheel]=temp[i];
    }
    switch(wheel){
        case 0: left.rotateVerge(rightR); break; 
        case 1: return; break; 
        case 2: right.rotateVerge(leftR); break;
    }
}
    /** Rearranges array elements of 4 arrays using temp Cell array. Copies a slice of the front verge.
      * This slice of front is then replaced by corresponding slice of the left verge,
      * which is then replaced by corresponding slice of the back verge, which is then replaced by the corresponding
      * slice of the right verge, which is then replaced by temp. If rotated wheel is located next to the top verge,
      * top verge rotates left, if it's located next to the bottom verge, bottom verge rotates right.*/   
void Cube::front_right(int wheel){
    Cell temp[size];
    for (int i=0;i<size;i++) temp[i]=front.grid[wheel][i];
    for (int i=0;i<size;i++){
        front.grid[wheel][i]=left.grid[inv-i][inv-wheel];
        left.grid[inv-i][inv-wheel]=back.grid[wheel][i];
        back.grid[wheel][i]=right.grid[i][wheel];
        right.grid[i][wheel]=temp[i];
    }
    switch(wheel){
        case 0: top.rotateVerge(leftR); break;        
        case 1: return; break;         
        case 2: bottom.rotateVerge(rightR); break;  
       
    }
}
    /** Rearranges array elements of 4 arrays using temp Cell array. Copies a slice of the front verge.
      * This slice of front is then replaced by corresponding slice of the right verge,
      * which is then replaced by corresponding slice of the back verge, which is then replaced by the corresponding
      * slice of the left verge, which is then replaced by temp. If rotated wheel is located next to the top verge,
      * top verge rotates right, if it's located next to the bottom verge, bottom verge rotates left.*/   
void Cube::front_left(int wheel){
    Cell temp[size];
    for (int i=0;i<size;i++) temp[i] =front.grid[wheel][i];
    for (int i=0;i<size;i++){
        front.grid[wheel][i]=right.grid[i][wheel];
        right.grid[i][wheel]=back.grid[wheel][i];
        back.grid[wheel][i]=left.grid[inv-i][inv-wheel];
        left.grid[inv-i][inv-wheel]=temp[i];
    }  
    switch(wheel){
        case 0: top.rotateVerge(rightR); break;        
        case 1: return; break;         
        case 2: bottom.rotateVerge(leftR); break;       
    }
}
    /** Scrambles the cube by doing random rotations 15 times. There are two random values tied to system time, one
     *  chooses a rotation, other one chooses a specific wheel. */
void Cube::randomize(){
    srand(time(0));
    int i,k;
    const int moves=15,case_limit=6,argument_limit=3;
    for(int j=0;j<moves;j++){
        i=rand()%case_limit;
        k=rand()%argument_limit;
        switch(i){
            case 0: front_up(k); break;  
            case 1: front_down(k); break;     
            case 2: front_right(k); break;     
            case 3: front_left(k); break;  
            case 4: up_right(k); break;  
            case 5: up_left(k); break;   
        }
    }
} 
/** Writes Cube state into a file, the name of a file is chosen by a user.*/  
void Cube::write(const std::string &name){
    FILE *F;
    const int fsize=217;
    F = fopen(name.c_str(), "w");
    fwrite(this, fsize, 1, F);
    fclose(F);
}
/** Reads Cube state from a file, the name of a file is chosen by a user.*/  
void Cube::read(const std::string &name){
    FILE *F;
    const int fsize=217;
    F = fopen(name.c_str(), "r");
    fread(this, fsize, 1, F);
    fclose(F);
}
bool Verge::check(){
    int temp;
    
        temp=this->grid[0][0].color;
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
                if(temp!=this->grid[i][j].color) return false;

    return true;
}
/** Checks if all sides of the cube are uniform, meaning that a side consists only of one value.
 *  It checks it by comparing top left cell of a side to all other cells. If all sides are
 *  uniform, it returns true, else false.*/  
bool Cube::check(){
    int temp;
    if(!front.check()||!back.check()||!left.check()||!right.check()||!top.check()||!bottom.check())
    return false;
    else return true;
}

/** Writes cube state into the [54] array. Used for reading cube's Cell values.*/  
int *Cube::out(){
    static int temp[54];
    const int unit=9;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){ 
            temp[i*size+j]=top.grid[i][j].color;  
            temp[unit+i*size+j]=right.grid[i][j].color;  
            temp[unit*2+i*size+j]=bottom.grid[i][j].color; 
            temp[unit*3+i*size+j]=left.grid[i][j].color;  
            temp[unit*4+i*size+j]=front.grid[i][j].color;  
            temp[unit*5+i*size+j]=back.grid[i][j].color;   
        }
    return temp; 
}
