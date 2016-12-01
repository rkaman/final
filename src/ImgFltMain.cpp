#include "imgflt.h"

int main(int argc, char **argv)
{    
    Fl::visual(FL_DOUBLE|FL_RGB);

	ImgFilterUI imgFltUI;
    imgFltUI.show();

	return Fl::run();
}

/************************** TO BE DONE 4 *********************************************/
	//generate help info about how to enjoy the application! very important!!
	//YOU NEED TO WORK IN THIS FUNCTION!!!!!
/*************************************************************************************/

void my_img_filter(char helpInfo[2048])
{
	char info[2048] = {"\
File-->Save Contour, save image with contour marked \n\
File-->Save Mask, save compositing mask for PhotoShop, \n\
Tool-->Scissor, open a panel to choose what to draw in the window \n\
Work Mode: \n\
Image Only: show original image without contour superimposed on it; \n\
Image with Contour: show original image with contours superimposed on it; \n\
Debug Mode: \n\
Pixel Node:  Draw a cost graph with original image pixel colors at the center \n\
of each 3by3 window, and black everywhere else; \n\
Cost Graph: Draw a cost graph with both pixel colors and link costs, where you \n\
can see whether your cost computation is reasonable or not, e.g., low cost \n\
(dark intensity) for links along image edges. \n\
Path Tree: show minimum path tree in the cost graph for the current seed; You \n\
can use the counter widget to simulate how the tree is computed by specifying \n\
the number of expanded nodes. The tree consists of links with yellow color. The \n\
back track direction (towards the seed) goes from light yellow to dark yellow. \n\
Min Path: show the minimum path between the current seed and the mouse position; \n\
Ctrl+\"+\", zoom in; \n\
Ctrl+\"-\", zoom out; \n\
Ctrl+Left click first seed; \n\
Left click, following seeds; \n\
Enter, finish the current contour; \n\
Ctrl+Enter, finish the current contour as closed; \n\
Backspace, when scissoring, delete the last seed; otherwise, delete selected contour. \n\
Select a contour by moving onto it. Selected contour is red, un-selected ones are green.\n\
\n\
				GOOD LUCK!\n\
"};

	strcpy(helpInfo,info);
}

/************************ END OF TBD 4 **************************/