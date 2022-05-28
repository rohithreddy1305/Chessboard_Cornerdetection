//Read and display an image
#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Chessboard.h>
using namespace std;

int main(int argc, char** argv)
{
    
    string directory_path = argv[1];
    cv::Size boardSize;
    boardSize.width = 9;
    boardSize.height = 7;

    // Read all image paths from txt file
    string file_path = directory_path + "/image_paths.txt";
    vector<string> image_paths;
    ifstream file(file_path);
    string line;
    while (getline(file, line))
    {
        image_paths.push_back(line);
    }
    
    for(int i=0; i<image_paths.size();++i)
    {
        string img_path = image_paths[i];
        cv::Mat image = cv::imread(img_path);
        CornerDetection::Chessboard chessboard(boardSize, image);
        chessboard.findCorners(false);
        if (chessboard.cornersFound())
        {

            cout << "# INFO: Detected chessboard in image " << img_path << std::endl;
            
            cv::Mat sketch;
            chessboard.getSketch().copyTo(sketch);

            // cv::imshow("Image", sketch);
            cv::imwrite(img_path.replace(img_path.end()-4, img_path.end(), "_sketch.jpg"), sketch);
            // cv::waitKey(50);
        }
        else
        {
            cerr << "# ERROR: Did not detect chessboard in image " << img_path << std::endl;
        }
    }
    
    return 0;
}