/*
 * vector_funcs.h
 *
 *
 *
 */

#ifndef VECTOR_FUNCS_H_
#define VECTOR_FUNCS_H_
#include <cstddef>

class Vector { //Beginn der Vector Klasse

public:

    //Constructor
    Vector ( const std::size_t dim );

    //Copy-Constructor
    Vector( const Vector & c );

    //Destructor
    ~Vector ();

    //Return size of Vector
    const std::size_t size() const;

    //Ausgabe aller Einträge
    void print(const std::string title="", const int w=8) const; //const int w=8 default Wert für Abstand. Übergabe bei Aufruf optional

    //Copy Operator
    Vector & operator= ( const Vector & c );

    //Initialisierung mit Skalar
    Vector & operator=(const double value);

    //Index Operator Reading
    const double  operator() ( std::size_t n ) const;

    //Index Operator Writing
    double & operator() ( std::size_t n );


    //Vektor-Addition
    const Vector operator+ (const Vector & c2) const;
    //Vektor-Subtraktion
    const Vector operator- (const Vector & c2) const;
    //Skalarprodukt
    const double operator* (const Vector & c2) const;
    //Multiplikation mit Skalar
    const Vector operator* ( const double & lambda) const;

private:

    //Default Constructor: Hier PRIVATE um Ausführen des Default Constructor zu unterbinden
    Vector ();

    double * dataPtr;  // pointer for data
    std::size_t      N;        // number of entries in the vector

}; //Ende der Vector Kasse


#endif /* VECTOR_FUNCS_H_ */
