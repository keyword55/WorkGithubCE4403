#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <cstring>
#include<cstdlib>
#include<vector>
using namespace std;
using namespace std;
using namespace cv;
#define NUM_READ_LINES 100

int main( int, char** argv )
{
  Mat src, dst;

  /// Load image
  src = imread( "D:/New folder/italianroast/italianroasttest.jpg", 1 );


  if( src.empty() )
    { return -1; }

  /// Separate the image in 3 places ( B, G and R )
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

  /// Establish the number of bins
  int histSize =16;

  /// Set the ranges ( for B,G,R) )
  float range[] = { 0, 256 } ;
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;

  Mat b_hist, g_hist, r_hist;

  /// Compute the histograms:
  calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
  double total;
    total=src.rows*src.cols;
    float cal,length,cal2,mostvalue=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int g=0;
    int h=0;
    // length % for calculate
       float percen=5.0/100;

     printf("Blue  ");
   for( int h = 0; h < histSize; h++ )
             {
                float binVal = b_hist.at<float>(h);
                cout<<":"<<binVal;
             }
   printf("\n");
   printf("Green ");
   for( int h = 0; h < histSize; h++ )
                {
                   float binVal = g_hist.at<float>(h);
                   cout<<":"<<binVal;
                }
    printf("\n");
    printf("Red   ");
    for( int h = 0; h < histSize; h++ )
                   {
                      float binVal = r_hist.at<float>(h);
                      cout<<":"<<binVal;
                   }
    printf("\n");


/*
  // Draw the histograms for B, G and R
  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound( (double) hist_w/histSize );

  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

  /// Normalize the result to [ 0, histImage.rows ]
  normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

  /// Draw for each channel
  for( int i = 1; i < histSize; i++ )
  {
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                       Scalar( 255, 0, 0), 2, 8, 0  );
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                       Scalar( 0, 255, 0), 2, 8, 0  );
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                       Scalar( 0, 0, 255), 2, 8, 0  );
  }

  // Display
  namedWindow("calcHist Demo", WINDOW_AUTOSIZE );
  imshow("calcHist Demo", histImage );
*/

  // Array of line numbers each line being no more than 100 chars
      char thearray[NUM_READ_LINES][100];
      int counter = 0;
      // Open our file
      ifstream inFile("D:/16p.txt",ifstream::in);
      // If we can read/write great
      if (inFile.good())
      {
          // Read throuthe file and load into array
          while (!inFile.eof() && (counter < NUM_READ_LINES)) {
              inFile.getline(thearray[counter],100);
              counter++;
          }
          // Loop through the array which we just put together
          for (int k = 0; k < counter; k++)
          {
          	char *token = std::strtok(thearray[k], ":");
          	           std::vector<int> v;
          	           while (token != NULL)
          	           {
          	               v.push_back( std::strtol( token, NULL, 10 ));
          	               token = std::strtok(NULL, ":");
          	           }
          	         for(std::size_t i =0 ; i < v.size() ; i++)
          	          {	for(int u=0;u<v.size();u++){
          	        	  if(v[u]>mostvalue){mostvalue=v[u];}
          	          }
          	        	  if(k%3==0)
          	        	  {
          	        	  	  length=mostvalue*percen;
          	        	  	  cal=v[i]+length;
          	        	  	  cal2=v[i]-length;
          	        		 if(b_hist.at<float>(i)<=cal && b_hist.at<float>(i)>=cal2  )
          	        		  { if(k==0){a++;}
          	        		if(k==3){b++;}
          	        		if(k==6){c++;}
          	        		if(k==9){d++;}
          	        		if(k==12){e++;}
          	        		if(k==15){f++;}
          	        		if(k==18){g++;}
          	        		if(k==21){h++;}
          	        		  }
          	        	  }
          	        	if(k%3==1)
          	        	   {
          	        	    length=v[i]*percen;
          	        	    cal=v[i]+length;
          	        	    cal2=v[i]-length;
          	        	    if(g_hist.at<float>(i)<=cal && g_hist.at<float>(i)>=cal2  )
          	        	   { if(k==1){a++;}
          	        	 if(k==4){b++;}
          	        	if(k==7){c++;}
          	        	if(k==10){d++;}
          	        	if(k==13){e++;}
          	        	if(k==16){f++;}
          	        	if(k==19){g++;}
          	        	if(k==22){h++;}
          	        	   }
          	        	   }
          	        	if(k%3==2)
          	        	   {
          	        	     length=v[i]*percen;
          	        	     cal=v[i]+length;
          	        	     cal2=v[i]-length;
          	        	    if(r_hist.at<float>(i)<=cal && r_hist.at<float>(i)>=cal2 )
          	        	    { if(k==2){a++;}
          	        	  if(k==5){b++;}
          	        	if(k==8){c++;}
          	        	if(k==11){d++;}
          	        	if(k==14){e++;}
          	        	if(k==17){f++;}
          	        	if(k==20){g++;}
          	        	if(k==23){h++;}
          	        	    }

          	        	    }
          	         }
          }
      }
      cout<<"a : "<<a<<"\n";
      cout<<"b : "<<b<<"\n";
      cout<<"c : "<<c<<"\n";
      cout<<"d : "<<d<<"\n";
      cout<<"e : "<<e<<"\n";
      cout<<"f : "<<f<<"\n";
      cout<<"g : "<<g<<"\n";
      cout<<"h : "<<h<<"\n";


      inFile.close();
      waitKey(0);
  return 0;

}
