
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "Cube.h"
Cube cube;
void sc(std::string t, int color){//set color
		std::cout<<t;
		HANDLE hConsole;
    	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(hConsole,(WORD)(color+9));
    	std::cout<<color;
    	SetConsoleTextAttribute(hConsole,(WORD)(15|0));
}

void print(Cube cube){
    int* temp;
    temp=cube.out();  
    std::string a;   
    std::cout<<"===============Menu=============== ";        sc("      _ ",temp[6]);std::cout<<" _               _        \n";
    std::cout<<"1.Save     2.Load                  ";        sc("   _ ",temp[3]);sc("     ",temp[7]);sc(" _         _ ",temp[35]);sc("|",temp[47]);std::cout<<" _     \n";//
    std::cout<<"3.Mix      4.Check          0.Exit ";        sc("_ ",temp[0]);sc("     ",temp[4]);sc("     ",temp[8]);sc(" _   _ ",temp[32]);sc("   |   ",temp[46]);std::cout<<" _  \n"; 
    std::cout<<"X-Y        "<<"X-Z       "<<"Y-Z           ";sc("|",temp[36]);sc(" _ ",temp[1]);sc("     ",temp[5]);sc(" _ ",temp[15]);sc("| |",temp[29]);sc("     ",temp[34]);sc("|",temp[50]);sc("     ",temp[45]);std::cout<<"|\n"; 
    std::cout<<"10.Right_0 "<<"30.Up_0   "<<"50.ClckWise_0 ";sc("|   ",temp[37]);sc(" _ ",temp[2]);sc(" _ ",temp[12]);sc("   | |   ",temp[31]);sc("   |   ",temp[49]);std::cout<<"   |\n"; 
    std::cout<<"11.Right_1 "<<"31.Up_1   "<<"51.ClckWise_1 ";sc("|",temp[39]);sc("     ",temp[38]);sc("|",temp[9]);sc("     ",temp[16]);sc("| |",temp[28]);sc("     ",temp[33]);sc("|",temp[53]);sc("     ",temp[48]);std::cout<<"|\n"; 
    std::cout<<"12.Right_2 "<<"32.Up_2   "<<"52.ClckWise_2 ";sc("|   ",temp[40]);sc("   |   ",temp[13]);sc("   | |   ",temp[30]);sc(" _ ",temp[26]);sc(" _ ",temp[52]);std::cout<<"   |\n"; 
    std::cout<<"                                   ";        sc("|",temp[42]);sc("     ",temp[41]);sc("|",temp[10]);sc("     ",temp[17]);sc("| |",temp[27]);sc(" _ ",temp[23]);sc("     ",temp[25]);sc(" _ ",temp[51]);std::cout<<"|\n";
    std::cout<<"20.Left_0  "<<"40.Down_0 "<<"60.CntrClck_0 ";sc("  - ",temp[43]);sc("   |   ",temp[17]);sc(" -   - ",temp[20]);sc("     ",temp[22]);sc("     ",temp[24]);std::cout<<" -\n";
    std::cout<<"21.Left_1  "<<"41.Down_1 "<<"61.CntrClck_1 ";sc("     - ",temp[44]);sc("|",temp[11]);sc(" -         - ",temp[19]);sc("     ",temp[21]);std::cout<<" -   \n"; 
    std::cout<<"22.Left_2  "<<"42.Down_2 "<<"62.CntrClck_2 ";sc(" front  -         back  - ",temp[18]);std::cout<<" -      \n";
    std::cout<<std::endl;
}


int main(int argc, char **argv)
{
    std::string name;
    int kod=0;
    while(1){
        if(kod!=4)print(cube);
        std::cin>>kod;
        switch(kod){
        case 0: return 0; break;    
        case 1: 
        	std::cout<<"Enter save file name:";
        	std::cin>>name; 
        	cube.write(name);
        break;
        case 2:
        	std::cout<<"Enter save file name:";
        	std::cin>>name; 
        	cube.read(name);
        break;       
        case 3: cube.randomize(); break;
        case 4:
        	if(cube.check()) std::cout<<"Complete!"<<std::endl;   
        	else std::cout<<"not complete:("<<std::endl;
        break;        
        case 10: cube.front_right(0); break;
        case 11: cube.front_right(1); break;
        case 12: cube.front_right(2); break;
        case 20: cube.front_left(0); break;
        case 21: cube.front_left(1); break; 
        case 22: cube.front_left(2); break;
        case 30: cube.front_up(0); break;
        case 31: cube.front_up(1); break;
		case 32: cube.front_up(2); break; 
        case 40: cube.front_down(0); break;   
        case 41: cube.front_down(1); break;
        case 42: cube.front_down(2); break;
        case 50: cube.up_right(0); break;
        case 51: cube.up_right(1); break;
        case 52: cube.up_right(2); break;
        case 60: cube.up_left(0); break;
        case 61: cube.up_left(1); break;
        case 62: cube.up_left(2); break;
        }
        if(kod!=4)system("cls");
    }    
}
