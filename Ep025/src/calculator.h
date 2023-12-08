//!  A calculator class
/*!
  This class is a simple calculator class that can add, subtract, multiply, divide, and mod two numbers.
*/
struct Calculator {
    //! A member adding two arguments and returning an integer value.
    /*!
      \param a an integer argument.
      \param b an integer argument.
      \return the sum of a and b.
    */
    int add (int, int);

    //! A member subtracting arguments and returning an integer value.
    /*!
      \param a an integer argument.
      \param b an integer argument.
      \return a minus b.
    */
    int sub (int, int);

    //! A member multiplying arguments and returning an integer value.
    /*!
      \param a an integer argument.
      \param b an integer argument.
      \return a * b.
    */    
    int mul (int, int);


    //! A member dividing arguments and returning an integer value.
    /*!
      \param a an integer argument.
      \param b an integer argument.
      \return a / b.
    */  
    int div (int, int);

    //! A member carying out a modulus operation between arguments and returning an integer value.
    /*!
      \param a an integer argument.
      \param b an integer argument.
      \return a mod b.
    */ 
    int mod (int, int);
};