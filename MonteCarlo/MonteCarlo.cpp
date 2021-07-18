#include <iostream>
#include <cstdlib>      
#include <ctime>        
#include <cmath>     
#include <sstream>
#include <iomanip>

const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164;
const int PRECISION = 10;

double distance(double xCoordinate, double yCoordinate)
{
    return sqrt(xCoordinate * xCoordinate + yCoordinate * yCoordinate);
}

double piValue(int totalNumberOfPoints, double counter)
{
    return counter / totalNumberOfPoints;  
}

int main()
{
    std::cout << "Odaberite opciju:" << std::endl << "  Slucajno generisana vrijednost - 1"
              << std::endl << "  Broj decimala - 2" << std::endl;
    int option;
    std::cout << std::endl << "Vas odabir: ";
    std::cin  >> option;

    double xCoordinate, yCoordinate, test;
    srand(time(NULL));   
    test = rand() / double(RAND_MAX);

    double distanceFromOrigin;       
    double counter = 0;             
    int totalNumberOfPoints;    

    if (option == 1)
    {

        std::cout << std::endl << "Unesite broj iteracija: ";
        std::cin >> totalNumberOfPoints;

        for (int i = 1; i <= totalNumberOfPoints; i++)
        {

            xCoordinate = (double)rand() / (RAND_MAX);
            yCoordinate = (double)rand() / (RAND_MAX);
            distanceFromOrigin = distance(xCoordinate, yCoordinate);

            if (distanceFromOrigin <= 1)
                counter++;

        }

        double piCalculated = 4 * piValue(totalNumberOfPoints, counter);
        std::cout.precision(PRECISION);
        std::cout << "Izracunata vrijednost broja Pi sa preciznoscu " << PRECISION << " je : " << std::fixed << piCalculated << std::endl;
       
    }
  
    else if (option == 2)
    {
        std::cout << "Unesite zeljenu preciznost: ";
        double precision;
        std::cin >> precision;
        double piCalculated = 0;

        double divider = pow(10, precision);
        double value = PI * divider;
        double piValueWithPrec = (double)value / divider;

        std::ostringstream piValueStream;
        piValueStream << std::fixed;
        piValueStream << std::setprecision(precision);
        piValueStream << piValueWithPrec;
        std::string piValueWithPrecision = piValueStream.str();
        const char* piValueWithPrecisionC = piValueWithPrecision.c_str();
        std::cout << "Potrebno da se poklapa: " << piValueWithPrecisionC << std::endl;

        std::string piCalculatedValueWithPrecision = "";
        const char* piCalculatedValueWithPrecisionC = piCalculatedValueWithPrecision.c_str();


        srand(time(NULL)); 
        test = rand() / double(RAND_MAX);

        counter = 0;
        totalNumberOfPoints = 0;
        double piValueCalc = 0;
        do
        {
            totalNumberOfPoints++;
            xCoordinate = (double)rand() / (RAND_MAX);
            yCoordinate = (double)rand() / (RAND_MAX);
            distanceFromOrigin = distance(xCoordinate, yCoordinate);

            if (distanceFromOrigin <= 1)
                counter++;

            piCalculated = 4 * piValue(totalNumberOfPoints, counter);

            int value = piCalculated * divider;
            piValueCalc = (double)value / divider;
            std::ostringstream piCalculatedValueStream;
            piCalculatedValueStream << std::fixed;
            piCalculatedValueStream << std::setprecision(precision);
            piCalculatedValueStream << piValueCalc;
            piCalculatedValueWithPrecision = piCalculatedValueStream.str();
            const char* piCalculatedValueWithPrecisionC = piCalculatedValueWithPrecision.c_str();
        } while (strcmp(piValueWithPrecisionC, piCalculatedValueWithPrecisionC) != 0);
      
        if (precision > PRECISION)
            std::cout.precision(precision);
        else
            std::cout.precision(PRECISION);

        std::cout << "Izracunata vrijednost: " << std::fixed << piCalculated << std::endl;
   
    }
    else
        std::cout << "Niste unijeli validnu opciju.";
    return 0;
}