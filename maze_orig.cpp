#include <iostream>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <assert.h>
enum  shit
{
	width = 27,
	height=20
};
int x,y;
int win;
char prog[0x1000];

//width:27, height:20
char map []=    "# #########################"
		"#    #    #     #    ######"
		"## #   ## # ### # ## ## ###"
		"#  ###### #    ## #       #"
		"# ######  # ##    ###### ##"
		"# #   ## ## ########## # ##"
		"# # # ##    #   ##     #  #"
		"#   #  ###### #### ### ## #"
		"#### # #      ####   # ## #"
		"# #      ## #    #####    #"
		"#   # ##### ####  ## ######"
		"### # ##### #  # #    #####"
		"# # #    ## ##     ###   ##"
		"# # #### ### #######   # ##"
		"#   #### ##  ##      ### ##"
		"##### ##        ######    #"
		"#  #     ### #######   # ##"
		"##   #######      ###### ##"
		"#### ##      ####      ####"
		"######################*####";

void addCur(int x, int y)
{
	map[width*x+y]= 'X';
}
void init()
{
	x=0;
	y=1;
	win = 0;
	addCur(x,y);
}
void draw(int width, int height)
{
	std::cout << "\n\n\n\n\n";
	for(int i =0; i <height; ++i)
	{
		for(int j =0; j<width; ++j)
		{
			std::cout << map[i*width+j];
		}
		std::cout << "\n";
	}
}

void up()
{
	int tx = x-1;
	int ty = y;
	if(tx <= 0 || tx >= height)
		return;
	if(map[tx*width+ty]=='#')
		return;
	else if(map[tx*width+ty]==' ')
	{	
		x = tx;
		y = ty;
		addCur(x,y);
	}
	else if(map[tx*width+ty]=='*')
	{
		win = 1;
		x = tx;
		y = ty;
	}

}

void down()
{
	int tx = x+1;
	int ty = y;
	if(tx <= 0 || tx >= height)
		return;
	if(map[tx*width+ty]=='#')
		return;
	else if(map[tx*width+ty]==' ')
	{	
		x = tx;
		y = ty;
		addCur(x,y);
	}
	else if(map[tx*width+ty]=='*')
	{
		win = 1;
		x = tx;
		y = ty;
	}

}
void left()
{
	int tx = x;
	int ty = y-1;
	if(ty <=0 || ty >= width)
		return;
	if(map[tx*width+ty]=='#')
		return;
	else if(map[tx*width+ty]==' ')
	{	
		x = tx;
		y = ty;
		addCur(x,y);
	}
	else if(map[tx*width+ty]=='*')
	{
		win = 1;
		x = tx;
		y = ty;
	}

}
void right()
{
	int tx = x;
	int ty = y+1;
	if(ty <=0 || ty >= width)
		return;
	if(map[tx*width+ty]=='#')
		return;
	else if(map[tx*width+ty]==' ')
	{	
		x = tx;
		y = ty;
		addCur(x,y);
	}
	else if(map[tx*width+ty]=='*')
	{
		win = 1;
		x = tx;
		y = ty;
	}

}

int main()
{
	int i=0;
	init();
	draw(width, height);
	memset(prog, 0, 0x1000);
	read(0, prog, 0x1000);
	while(prog[i] != '\0')
	{
		int tx =x;
		int ty=y;
		if(win)
		{
			std::cout << "You Win!\n"<<std::endl;
			return 0;
		}
		switch (prog[i])
		{
			case 'W':
				up();
				break;
			case 'S':
				down();
				break;
			case 'A':
				left();
				break;
			case 'D':
				right();
				break;
			default:
				break;
		}
		if(tx ==x && ty==y)
		{
			std::cout << "You Loooooooose, Loser??\n" <<std::endl;
			return 0;
		}
		draw(width, height);
		struct timespec ts;
		struct timespec tr;
		ts.tv_sec =0;
		ts.tv_nsec = 1000000*200;
		nanosleep(&ts, &tr);
		++i;
	}
		
}
