#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  double total_error;
  double prev_cte;

  double def_throttle;
  /*
  * true: after it get first CTE
  */
  bool fstart;

  int count;
  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  double Kt; // throttle

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  double GetSteering();
  double GetThrottle();
  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
