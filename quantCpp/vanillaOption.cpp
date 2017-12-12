//
//  vanillaOption.cpp
//  CppQuantFinance
//
//  Created by Geyijie on 12/12/2017.
//  Copyright © 2017 Geyijie. All rights reserved.
//



#include <stdio.h>
#include "vanillaOption.h"
#include <cmath>
#include "statUtils.h"

void VanillaOption::init(){
    K = 100;
    r = 0.05;
    T = 1.0;
    S = 100.0;
    sigma = 0.2;
}

void VanillaOption::copy(const VanillaOption &rhs){
    K = rhs.getK();
    r = rhs.getr();
    T = rhs.getT();
    S = rhs.getS();
    sigma = rhs.getsigma();
}

VanillaOption::VanillaOption(){
    init();
}

VanillaOption::VanillaOption(const double& K,const double& r ,
                               const double& T , const double& S ,
                               const double& sigma){
    this->K = K;
    this->r = r;
    this->T = T;
    this->S = S;
    this->sigma = sigma;
}

VanillaOption::VanillaOption(const VanillaOption& rhs){
    copy(rhs);
}

VanillaOption& VanillaOption::operator=(const VanillaOption& rhs){
    if (this ==&rhs)
        return *this;
    copy(rhs);
    return *this;
}


VanillaOption::~VanillaOption(){

}

double VanillaOption::getK() const{
    return this->K;
}

double VanillaOption::getr() const{
    return this->r;
}
double VanillaOption::getT() const{
    return this->T;
}
double VanillaOption::getS() const{
    return this->S;
}
double VanillaOption::getsigma() const{
    return this->sigma;
}


double VanillaOption::calc_call_price () const{
    double sigma_sqrt_T = sigma * sqrt(T);
    double d_1 = (log(S/K) + sigma*sigma*0.5*T)/ sigma_sqrt_T;
    double d_2 = d_1 - sigma_sqrt_T;
    return (S*exp(-r*T)*N(d_1)) - (K*exp(-r*T)*N(d_2));
}

double VanillaOption::calc_put_price () const{
    double sigma_sqrt_T = sigma * sqrt(T);
    double d_1 = (log(S/K) + sigma*sigma*0.5*T)/ sigma_sqrt_T;
    double d_2 = d_1 - sigma_sqrt_T;
    return (K*exp(-r*T)*N(-d_2)) - (S*exp(-r*T)*N(-d_1));
}



