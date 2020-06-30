//
// Created by Lorenzo Massa on 29/06/2020.
//

#include "gtest/gtest.h"

class TestHero : public ::testing::Test {

    virtual void SetUp() {
        try {
            bigImgFile.open("../../test/testImage/ferrari.ppm");
            if (bigImgFile.is_open())
                bigImgFile >> img;
            else
                GTEST_FAIL();
        }catch (ImageException &e){
            GTEST_FATAL_FAILURE_(e.what());
        }
    }

}