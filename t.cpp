import std;
/*
#include <print.h>
#include <input.h>
#include <zip.h>
#include <stlmain>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>
#include <QApplication>
#include <QPushButton>
using namespace cv;
*/
using namespace std;
auto main->int (){
cout<<format("Test {}",1)<<endl;
auto s=cin.getline();
auto v=s|views::spilt(" ")|to<vector<string>>();
for (auto i:v){cout<<i<<endl};
return(0);
}