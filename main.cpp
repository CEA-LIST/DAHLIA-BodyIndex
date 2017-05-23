/*
    (C) Copyright 2017 CEA LIST. All Rights Reserved.
    Contributor(s): Astrid ORCESI (astrid.orcesi@cea.fr)

    This software is governed by the CeCILL-C license under French law and
    abiding by the rules of distribution of free software.  You can  use,
    modify and/ or redistribute the software under the terms of the CeCILL-C
    license as circulated by CEA, CNRS and INRIA at the following URL
    "http://www.cecill.info".
    As a counterpart to the access to the source code and  rights to copy,
    modify and redistribute granted by the license, users are provided only
    with a limited warranty  and the software's author,  the holder of the
    economic rights,  and the successive licensors  have only  limited
    liability.
    The fact that you are presently reading this means that you have had
    knowledge of the CeCILL-C license and that you accept its terms.
*/


#include <iostream>
#include <fstream>
#include <stdint.h>
#include <boost/concept_check.hpp>
#include <sstream>
#include <opencv/highgui.h>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc,const char *argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    string pathPI = argv[3];
    string pathPO = argv[4];

    for(int k=N;k<=M;k++)
    {
        std::stringstream ss;
        ss << k;
        string pathI = pathPI + "FileBodyIndex_" + ss.str() + ".bin" ;
        string pathO = pathPO + "FileBodyIndex_" + ss.str() + ".tif" ;

        ifstream f_in(pathI.c_str(), std::ios_base::binary);

        if(! f_in.is_open()) {
            cerr << "!!! can't open file [" << pathI << "]" << endl;
            return -1;
        }

        cout<<"decoding: "<<pathI<<" in: "<< pathO <<endl;

        int row = 424;
        int col = 512;
        uint8_t data_in [row*col/8];

        for (int i=0; i<row*col/8 ; i++)
        {
            f_in.read(reinterpret_cast<char*>(&data_in[i]),sizeof(uint8_t));
        }

        Mat image(row, col, CV_8UC1);

        for (int i=0; i<row*col/8 ; i++)
        {
            uint8_t val = data_in[i];
            for(int j=7;j>=0;j--)
            {
                int inv = 7-j;
                uint8_t res;
                res = val >> j;
                uint8_t mask = 00000001;
                if(res&mask)
                    image.at<uchar>(floor((i*8+inv)/col),(i*8+inv)%col)=255;
                else
                    image.at<uchar>(floor((i*8+inv)/col),(i*8+inv)%col)=0;
            }
        }

        imwrite(pathO, image);

        f_in.close();
    }

    return 0;
}
