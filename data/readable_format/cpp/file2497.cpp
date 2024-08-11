#include <array>

namespace servo_with_limits_data {

// Assuming 'mk' is a type alias for float or double. Adjust as necessary.
using Real = double;  // or float

int nblades;
int stepno;
int stuck_type;

Real omega0;
Real beta0;
Real vmax;
Real amax;
Real theta_min;
Real theta_max;
Real time_runaway;
Real time_stuck;
Real stuck_angle;

Real oldtime;
Real theta_ref;

std::array<std::array<Real, 3>, 2> yold;
std::array<std::array<Real, 3>, 2> ynew;

std::array<Real, 100> oldarray2;

Real timestep;

} // namespace servo_with_limits_data