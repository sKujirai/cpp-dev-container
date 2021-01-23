#include <Eigen/Core>
#include <boost/version.hpp>
#include <iostream>

int main() {
    std::cout << "Boost version: " << BOOST_LIB_VERSION << std::endl;
    std::cout << "Eigen version: " << EIGEN_WORLD_VERSION << "."
              << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION << std::endl;

    return 0;
}
