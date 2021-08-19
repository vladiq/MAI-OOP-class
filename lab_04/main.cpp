#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "templates.h"

int main() {
    int input;

    while (true) {
        std::cout << "++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cout << "1: Fake figure demonstration" << std::endl;
        std::cout << "2: Array figure demonstration" << std::endl;
        std::cout << "3: Real figure demonstration" << std::endl;

        std::cin >> input;

        if (input == 0) {
            break;
        }

        if (input > 3) {
            std::cout << "Invalid input" << std::endl;
        }

        switch (input) {
            case 1: {
                std::cout << "Fake Square (float):" << std::endl;
                std::tuple<vertex<float>, vertex<float>, vertex<float>, vertex<float>>
                        fakeSquare{{0, 0}, {0, 0.5}, {0.5, 0.5}, {0.5, 0}};
                std::cout << "Coordinates: ";
                Print(fakeSquare);
                std::cout << std::endl;
                std::cout << "Center: " << Center(fakeSquare) << std::endl;
                std::cout << "Area: " << Area(fakeSquare) << std::endl << std::endl;

                std::cout << "Fake Rectangle (int):" << std::endl;
                std::tuple<vertex<int>, vertex<int>, vertex<int>, vertex<int>>
                        fakeRectangle{{0, 0}, {0, 2}, {10, 2}, {10, 0}};
                std::cout << "Coordinates: ";
                Print(fakeRectangle);
                std::cout << std::endl;
                std::cout << "Center: " << Center(fakeRectangle) << std::endl;
                std::cout << "Area: " << Area(fakeRectangle) << std::endl << std::endl;

                std::cout << "Fake Trapezoid (double):" << std::endl;
                std::tuple<vertex<double>, vertex<double>, vertex<double>, vertex<double>>
                        fakeTrapezoid{{0, 0}, {0.5, 2}, {2, 2}, {15.5, 0}};
                std::cout << "Coordinates: ";
                Print(fakeTrapezoid);
                std::cout << std::endl;
                std::cout << "Center: " << Center(fakeTrapezoid) << std::endl;
                std::cout << "Area: " << Area(fakeTrapezoid) << std::endl << std::endl;
            break;
            }

            case 2: {
                std::cout << "Array Square (double):" << std::endl;
                std::array<vertex<double>, 4>
                        arraySquare{{{0, 0}, {0, 2}, {2, 2}, {2, 0}}};
                std::cout << "Coordinates: ";
                Print(arraySquare);
                std::cout << std::endl;
                std::cout << "Center: " << Center(arraySquare) << std::endl;
                std::cout << "Area: " << Area(arraySquare) << std::endl << std::endl;

                std::cout << "Array Trapezoid (float):" << std::endl;
                std::array<vertex<float>, 4>
                        arrayTrapezoid{{{0, 0}, {1, 2}, {2, 2}, {3, 0}}};
                std::cout << "Coordinates: ";
                Print(arrayTrapezoid);
                std::cout << std::endl;
                std::cout << "Center: " << Center(arrayTrapezoid) << std::endl;
                std::cout << "Area: " << Area(arrayTrapezoid) << std::endl << std::endl;
            break;
            }

            case 3: {
                int realID;

                std::cout << "Input real figure id:" << std::endl;
                std::cout << "1: Square" << std::endl;
                std::cout << "2: Rectangle" << std::endl;
                std::cout << "3: Trapezoid" << std::endl;
                
                std::cin >> realID;

                switch (realID) {
                    case 1: {
                        std::cout << "Input 4 coordinates in a sequence" << std::endl;
                        Square<double> realSquare(std::cin);
                        std::cout << "Coordinates: ";
                        Print(realSquare);
                        std::cout << std::endl;
                        std::cout << "Center: " << Center(realSquare) << std::endl;
                        std::cout << "Area: " << Area(realSquare) << std::endl << std::endl;
                    break;
                    }

                    case 2: {
                        std::cout << "Input 4 coordinates in a sequence" << std::endl;
                        Rectangle<double> realRectangle(std::cin);
                        std::cout << "Coordinates: ";
                        Print(realRectangle);
                        std::cout << std::endl;
                        std::cout << "Center: " << Center(realRectangle) << std::endl;
                        std::cout << "Area: " << Area(realRectangle) << std::endl << std::endl;
                    break;
                    }

                    case 3: {
                        std::cout << "Input 4 coordinates in a sequence" << std::endl;
                        Trapezoid<double> realTrapezoid(std::cin);
                        std::cout << "Coordinates: ";
                        Print(realTrapezoid);
                        std::cout << std::endl;
                        std::cout << "Center: " << Center(realTrapezoid) << std::endl;
                        std::cout << "Area: " << Area(realTrapezoid) << std::endl << std::endl;
                    break;
                    }
                }
            break;
            }
        }
    }
    return 0;
}