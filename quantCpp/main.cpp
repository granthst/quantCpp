//
//  main.cpp
//  CppQuantFinance
//
//  Created by Geyijie on 12/12/2017.
//  Copyright © 2017 Geyijie. All rights reserved.
//

#include <iostream>
#include "vanillaOption.h"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    VanillaOption v;
    cout << v.calc_put_price() <<endl;
    return 0;
}
