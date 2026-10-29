#include <iostream>
#include <iomanip>
#include <cmath>

class Electric_Field
{
  private: 
    double *E;
  public:

	Electric_Field() { //DEFAULT CONSTRUCTOR

		E = new double[3]{0.0, 0.0, 0.0};
		}

	Electric_Field(double x, double y, double z) { //COMPONENT CONSTRUCTOR
		E = new double[3];

		E[0] = x; 
		E[1] = y; 
		E[2] = z; 
	}

	~Electric_Field() { //DESTRUCTOR
		delete[] E;
	}


	double calculateInnerProduct() { //MATH FUNCTION, BASICALLY MAGNITUDE FUNCTION WITHOUT SQUAREROOTING
		double inner = E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
		return inner;
	}

    	double calculateMagnitude() { //MAGNITUDE FUNCTION
		double magnitude = std::sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
		return magnitude;}

	double getx(){return E[0];} //GETTER FUNCTIONS
	double gety(){return E[1];}
	double getz(){return E[2];}

	void setx(double x){E[0] = x;} //SETTER FUNCTIONS
	void sety(double y){E[1] = y;}
	void setz(double z){E[2] = z;}
};

class Magnetic_Field //SAME AS ELECTRIC FIELD CLASS
{
  private:
    double *M;
  public:

        Magnetic_Field() {

                M = new double[3]{0.0, 0.0, 0.0};
                }

        Magnetic_Field(double x, double y, double z) {
                M = new double[3];

                M[0] = x;
                M[1] = y;
                M[2] = z;
        }

        ~Magnetic_Field() {
                delete[] M;
        }


        void calculateUnitVector() {

		double magnitude = calculateMagnitude();

		std::cout << "<" << M[0]/magnitude << ", " << M[1]/magnitude << ", " << M[2]/magnitude << ">\n";
	}

        double calculateMagnitude() {
                double magnitude = std::sqrt(M[0] * M[0] + M[1] * M[1] + M[2] * M[2]);
                return magnitude;}

	double getx(){return M[0];}
        double gety(){return M[1];}
        double getz(){return M[2];}

        void setx(double x){M[0] = x;}
        void sety(double y){M[1] = y;}
        void setz(double z){M[2] = z;}
};


int main() { 

	Electric_Field E_default;
	Electric_Field E_components(1e5, 10.9, 1.7e2);

	std::cout << "********************************************************************************" << '\n';

	//OUTPUT CALLS
	std::cout << "ELECTRIC FIELD DEFAULT MAGNITUDE: " << E_default.calculateMagnitude() << '\n';
	std::cout << "ELECTRIC FIELD COMPONENT INNER PRODUCT: " << E_components.calculateInnerProduct() << '\n';
	std::cout << "ELECTRIC FIELD COMPONENT MAGNITUDE: " << E_components.calculateMagnitude() << '\n';

	std::cout << "ELECTRIC FIELD SETTER FUNCTIONS" << '\n';
	//I KNOW IT LOOKS BAD BUT I PREFER TO SET IN THE MIDDLE OF MY PRINTING SO I DON'T GET CONFUSED
	//ADDITIONALLY, I PUT THE SETTER HERE AFTER THE DEFAULT MAGNITUDE TO DEMONSTRATE THAT I CHANGED IT FROM 0 TO WHATEVER
	E_default.setx(2.0);
        E_default.sety(4.0);
        E_default.setz(8.0);
	std::cout << "SETTER X COMPONENT: " << E_default.getx() << '\n';
	std::cout << "SETTER Y COMPONENT: " << E_default.gety() << '\n';
	std::cout << "SETTER Z COMPONENT: " << E_default.getz() << '\n';
	std::cout << "ELECTRIC FIELD DEFAULT MAGNITUDE: " << E_default.calculateMagnitude() << '\n';

	std::cout << "********************************************************************************" << '\n';
	//ELECTRICAL ENGINEERING MAJOR HERE, I DIVIDED THE E FIELD VECTORS BY THE SPEED OF LIGHT TO SOLVE FOR B
	//ESSENTIALLY THE SAME OUTPUT CALLS AS THE ELECTRIC FIELD CALLS
	Magnetic_Field M_default;
        Magnetic_Field M_components(1e5/3e8, 10.9/3e8, 1.7e2/3e8); 
	

        std::cout << "MAGNETIC FIELD DEFAULT MAGNITUDE: " << M_default.calculateMagnitude() << '\n';
        
	std::cout << "MAGNETIC FIELD UNIT VECTOR: "; 
	M_components.calculateUnitVector();

        std::cout << "MAGNETIC FIELD COMPONENT MAGNITUDE: " << M_components.calculateMagnitude() << '\n';

	std::cout << "MAGNETIC FIELD SETTER FUNCTIONS" << '\n';
        M_default.setx(2.0/3e8);
        M_default.sety(4.0/3e8);
        M_default.setz(8.0/3e8);
        std::cout << "SETTER X COMPONENT: " << M_default.getx() << '\n';
        std::cout << "SETTER Y COMPONENT: " << M_default.gety() << '\n';
        std::cout << "SETTER Z COMPONENT: " << M_default.getz() << '\n';
        std::cout << "MAGNETIC FIELD DEFAULT MAGNITUDE: " << M_default.calculateMagnitude() << '\n';
	return 0;
	}

