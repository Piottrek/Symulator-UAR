#include "ModelARX.h"
#include "RegulatorPID.h"
#include "SprzezenieZwrotne.h"
#include "Testy.h"
#include "generator.h"
#include "testyGen.h"
#include "testySpZWR.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

int main()
{
    test_ModelARX_brakPobudzenia();
    test_ModelARX_skokJednostkowy_1();
    test_ModelARX_skokJednostkowy_2();
    test_ModelARX_skokJednostkowy_3();

    test_RegulatorP_brakPobudzenia();
    test_RegulatorP_skokJednostkowy();
    test_RegulatorPI_skokJednostkowy_1();
    test_RegulatorPI_skokJednostkowy_2();
    test_RegulatorPID_skokJednostkowy();

    //testSkokJednostkowy();
    //testSinusoida();
    //testProstokatny();

    test_UAR_1_brakPobudzenia();
    test_UAR_1_skokJednostkowy();
    test_UAR_2_skokJednostkowy();
}
