///Copyright Ryan Hermle.  Feb. 20, 2018.  All rights reserved.

#include "Bmp.h"
#include "Topograph.h"

const string VIEWING_APP = "eog ";

int main()
{
    string fileName1 = "map_input.txt";
    Topograph topograph(fileName1);

    Bmp bmp(topograph.getHeight(),topograph.getWidth());
    topograph.drawMap(bmp);

   bmp.write("map.bmp");
    //bmp.read(fileName1);


    //bmp.write(fileName2);

    system((VIEWING_APP + "map.bmp" + " &").c_str());
  
    return 0;
}
