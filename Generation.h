
#ifndef GENERATION_H
#define GENERATION_H

#include <string>
#include <vector>
#include "Individual.h"

class Individual;

namespace Genetic {


/**
  * class Generation
  * 
  */

class Generation
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Generation ( );

  /**
   * Empty Destructor
   */
  virtual ~Generation ( );

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   */
  virtual void test ( )
  {
  }


  /**
   * @param  seed
   */
  void init (unsigned int seed )
  {
  }

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

  std::vector <Individual*> individuals;
  int individualsNum;
  double mutationProbability;
  int mutationAttempts;
  int crossoverPointsNum;
public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  


  /**
   * Set the value of individuals
   * @param new_var the new value of individuals
   */
  void setIndividuals ( std::vector <Individual*> new_var )   {
      individuals = new_var;
  }

  /**
   * Get the value of individuals
   * @return the value of individuals
   */
  std::vector <Individual*> getIndividuals ( )   {
    return individuals;
  }

  /**
   * Set the value of individualsNum
   * @param new_var the new value of individualsNum
   */
  void setIndividualsNum ( int new_var )   {
      individualsNum = new_var;
  }

  /**
   * Get the value of individualsNum
   * @return the value of individualsNum
   */
  int getIndividualsNum ( )   {
    return individualsNum;
  }

  /**
   * Set the value of mutationProbability
   * @param new_var the new value of mutationProbability
   */
  void setMutationProbability ( double new_var )   {
      mutationProbability = new_var;
  }

  /**
   * Get the value of mutationProbability
   * @return the value of mutationProbability
   */
  double getMutationProbability ( )   {
    return mutationProbability;
  }

  /**
   * Set the value of mutationAttempts
   * @param new_var the new value of mutationAttempts
   */
  void setMutationAttempts ( int new_var )   {
      mutationAttempts = new_var;
  }

  /**
   * Get the value of mutationAttempts
   * @return the value of mutationAttempts
   */
  int getMutationAttempts ( )   {
    return mutationAttempts;
  }

  /**
   * Set the value of crossoverPointsNum
   * @param new_var the new value of crossoverPointsNum
   */
  void setCrossoverPointsNum ( int new_var )   {
      crossoverPointsNum = new_var;
  }

  /**
   * Get the value of crossoverPointsNum
   * @return the value of crossoverPointsNum
   */
  int getCrossoverPointsNum ( )   {
    return crossoverPointsNum;
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

#endif // GENERATION_H
