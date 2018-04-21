#include <iostream>
#include <fstream>
using namespace std;
class pixel{
	private:
	   	int red;
	    int green;
	    int blue;
};

int main(int argc, char* argv[]){
    //file stream takes first argument given as the file name to open
	ifstream fin(argv[1]);
	//file stream that takes my outfile name
	ofstream fout("grayscale.ppm");
	//this array holds the heading "P3" to denote the file is a .ppm file
	char mark[3];
	int height,width,max,red,gr,blu,avg;
	//checks to see if file is open then stores file in a 2D array
	if(fin.is_open())
	{
		fin.getline(mark, 3);
		fout << mark << "\n";
		fin >> height >> width >> max;
		fout << height << " " << width << "\n" << max;
		//loops through 500x500 pixels, finds the average of each
		//pixel, then each component of the pixel gets change to the avg.
		for(int i=0;i<500;i++)
		{
			fin.ignore();
			for(int j=1;j<501; j++)
			{
				//gives me a new line. This is done so grayscale.ppm
				//can be 500x500
				if(j%500==1)
				{
					fout << "\n";
				}
				fin >> red >> gr >> blu;
				avg = (red+gr+blu)/3;
				fout << avg << " " << avg << " " << avg << " ";
			}
		}
	//If the file name could not be found, an error message prints and
	//program exits	
	}else
	{
		cout << "Could not open file \n";
		return 1;
	}


	//extra credit(giving image a negative filter)
	ifstream f("grayscale.ppm");
	ofstream fo("extra.ppm");
	char first[3];
	int sw,sh,l,r,g,b,nr,ng,nb;
	//I used the same method that was used above
	//the difference comes from subtracting 255 from each component of 
	//a pixel.
	if(f.is_open())
	{
		f.getline(first,3);
		fo << first << "\n";
		f >> sh >> sw >> l;
		fo << sw  << " " << sh << "\n" << l;
		for(int y=0;y<500;y++)
		{
			f.ignore();
			for(int a=1;a<501;a++)
			{
				if(a%500==1)
				{
					fo << "\n";
				}
				f >> r >> g >> b;
				nr = 255-r;
				ng = 255-g;
				nb = 255-b;
				fo << nr << " " << ng << " " << nb << " ";
			}
		}
	}
}
