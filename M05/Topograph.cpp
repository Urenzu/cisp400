#include "Topograph.h"

Topograph::Topograph (string fileName)
{
    ifstream ifs (fileName);
    string dummy;
    ifs >> dummy >> width >> dummy >> height;
    ifs >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy;
    v.resize(height, vector<int>(width,0));
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++) 
        {
           ifs >> v.at(i).at(j);
        }
    }
  //cout<<"Done with constructor";
}
void Topograph::findMin(){
  min = v.at(0).at(0);
  for(int i = 0; i < height; i++)
  {
      for(int j = 0; j < width; j++) 
      {
        if(v.at(i).at(j) < min) min = v.at(i).at(j);
      }
  }
}

void Topograph::findMax(){
  max = v.at(0).at(0);
  for(int i = 0; i < height; i++)
  {
      for(int j = 0; j < width; j++) 
      {
        if(v.at(i).at(j) > max) max = v.at(i).at(j);
      }
  }
}
void Topograph::drawMap(Bmp& bmp){
  findMin();
  findMax();
  cout<<"Max elvation: "<<max<<endl;
  cout<<"min elvation: "<<min<<endl;

  for(int i = 0; i < height; i++)
  {
      for(int j = 0; j < width; j++) 
      {
        unsigned char grayVal = mapRange(v.at(i).at(j), min, max,0,255);
        bmp(i,j).r = grayVal;
        bmp(i,j).g = grayVal;
        bmp(i,j).b = grayVal;
      }
  }
}

/*
Transform n = 45
[fromLow : fromHigh] -> [toLow : toHigh]
[30:50] -> [70:120]
Guess:  110?  95?
((45 - 30) / (50 - 30)) * (120 - 70) + 70 = 107.5
  */
int Topograph::mapRange(int n, int fromLow, int fromHigh, int toLow, int toHigh){
  return ((n*1.0-fromLow) / (fromHigh - fromLow))*(toHigh - toLow) + toLow;
}
