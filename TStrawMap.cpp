#include <vector>
#include <TEllipse.h>
#include "TStraw.cpp"
//#include <iostream>
class TStraw;


namespace Constanses{
	float sqrt3 = 1.7320508;
}




class TStrawMap{
	std::vector<TStraw *> straws;
	unsigned int cols;
	unsigned int raws;
	double radius;

public:
	TStrawMap(unsigned int x, unsigned int y);
	void Draw(double, double);
	void MarkStraw(int);
	void MarkStraw(int,int);
	void Clear();

};

TStrawMap::TStrawMap(unsigned int x, unsigned int y): raws(x), cols(y) {
//        straws.resize(cols*raws);

	radius = 0.;
	cols > raws ? radius=0.45/cols : radius = 0.45/raws; //we calculated maximal radius which can fit into canvas

        for (unsigned int x = 0 ; x < cols ; x++){
                for (unsigned int y =0 ; y < raws; y++){
                        straws.push_back(new TStraw(0,0,radius));
                }
	//std::cout<<straws.size()<<std::endl;
}
}




void TStrawMap::Draw(double startPointX, double startPointY){
	
//	float x_step = 0.9/
//	float y_step

	
	//float x_pos = 0.05 + radius;
	//float y_pos = 0.05 + radius;
	float x_pos = startPointX;
	float y_pos = startPointY + 2*radius;


	//unsigned int straw_iter = 0;
	for (unsigned int straw_iter = 0; straw_iter< raws*cols; straw_iter++){
                        straws[straw_iter] -> SetX1(x_pos);
                        straws[straw_iter] -> SetY1(y_pos);
			x_pos = x_pos + radius;
			straw_iter%2 != 0 ? y_pos = y_pos + Constanses::sqrt3*radius : y_pos = y_pos - Constanses::sqrt3*radius;
			straws[straw_iter]->Draw();
	}


/*	for (unsigned int x = 0 ; x < cols ; x++){
		for (unsigned int y =0 ; y < raws; y++){
			//straws.push_back(new TStraw(x_pos,y_pos,radius));
			straws[straw_iter] -> SetX1(x_pos);
			straws[straw_iter] -> SetY1(y_pos);
			x_pos = x_pos + 2*radius;
//			straws.back()->Draw();
			straws[straw_iter]->Draw();
			straw_iter++;
		}
		y_pos = y_pos + Constanses::sqrt3*radius;
		x%2 != 0 ? x_pos = 0.05+2*radius : x_pos = 0.05+radius;
		//x_pos = 0.05 +radius;
	}
*/	

}

void TStrawMap::MarkStraw(int st_number, int color){
	if(st_number <= straws.size())
	straws[st_number]->Mark(color);	
}

void TStrawMap::MarkStraw(int st_number){
	if(st_number <= straws.size())
	straws[st_number]->Mark();	
}

void TStrawMap::Clear(){
	for (std::vector<TStraw *>::iterator it = straws.begin() ; it != straws.end(); ++it)
    	(*it)->Mark(0);	
	//straws[st_number]->Mark();	
}
