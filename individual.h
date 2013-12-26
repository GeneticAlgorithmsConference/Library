
#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "genetic.h"

namespace Genetic {


/**
  * class Individual
  *
  */

class Individual
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Individual ( );

  /**
   * Empty Destructor
   */
  virtual ~Individual ( );

  // Static Public attributes
  //

  // Public attributes
  //


  // Public attribute accessor methods
  //


  // Public attribute accessor methods
  //



  /**
   * @param  individual1
   * @param  individual2
   * @param  recombinationType
   * @param  crossoverPointsNum
   */
  static void recombine(Genetic::Individual* parent_individual1,
                                    Genetic::Individual* parent_individual2,
                                    Genetic::Individual* child_individual1,
                                    Genetic::Individual* child_individual2,
                                    Genetic::RecombinationType rec_type,
                                    double recombine_param = 1.0,
                                    int crossover_points_num = 1);


  /**
   * @param  probability
   */
  void mutate(MutationType mut_type, double probability, int attempts = 1, double parameter = 5.0);


  /**
   */
  virtual void generate ( )
  {
  }


  /**
   */
  virtual void updateParameters ( )
  {
  }

protected:

  // Static Protected attributes
  //

  // Protected attributes
  //

  int score;
  std::vector <double> dna;
public:


  // Protected attribute accessor methods
  //

protected:

public:


  // Protected attribute accessor methods
  //


  /**
   * Set the value of score
   * @param new_var the new value of score
   */
  void setScore ( int new_var )   {
      score = new_var;
  }

  /**
   * Get the value of score
   * @return the value of score
   */
  int getScore ( )   {
    return score;
  }

  /**
   * Set the value of dna
   * @param new_var the new value of dna
   */
  void setDna ( std::vector <double> new_var )   {
      dna = new_var;
  }

  /**
   * Get the value of dna
   * @return the value of dna
   */
  std::vector <double> getDna ( )   {
    return dna;
  }
protected:


private:

  // Static Private attributes
  //

  // Private attributes
  //

public:


  // Private attribute accessor methods
  //

private:

public:


  // Private attribute accessor methods
  //

private:


  void initAttributes ( ) ;

};
}; // end of package namespace

#endif // INDIVIDUAL_H
