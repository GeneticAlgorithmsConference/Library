
#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>
#include <vector>



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
   * @param  crossoverPointsNum
   */
  static void crossover (Genetic::Individual individual1, Genetic::Individual individual2, int crossoverPointsNum = 1 )
  {
  }


  /**
   * @param  probability
   */
  void mutate (double probability )
  {
  }


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
  std::vector <int> dna;
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
  void setDna ( std::vector <int> new_var )   {
      dna = new_var;
  }

  /**
   * Get the value of dna
   * @return the value of dna
   */
  std::vector <int> getDna ( )   {
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
