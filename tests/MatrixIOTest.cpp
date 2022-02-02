#define BOOST_TEST_MODULE SideMadeTests
#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>

#include "matrixIO.hpp"

using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    expectedMatrix = MatrixXd(3, 3);
    expectedMatrix << 0.680375, 0.59688, -0.329554, -0.211234, 0.823295, 0.536459, 0.566198, -0.604897, -0.444451;
  }
  MatrixXd expectedMatrix;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(openData)
{
  MatrixXd actualMatrix = matrixIO::openData("../data/m3.csv", 3);

  BOOST_TEST(actualMatrix(0, 0) == expectedMatrix(0, 0));
  BOOST_TEST(actualMatrix(0, 1) == expectedMatrix(0, 1));
  BOOST_TEST(actualMatrix(0, 2) == expectedMatrix(0, 2));
  BOOST_TEST(actualMatrix(1, 0) == expectedMatrix(1, 0));
  BOOST_TEST(actualMatrix(1, 1) == expectedMatrix(1, 1));
  BOOST_TEST(actualMatrix(1, 2) == expectedMatrix(1, 2));
  BOOST_TEST(actualMatrix(2, 0) == expectedMatrix(2, 0));
  BOOST_TEST(actualMatrix(2, 1) == expectedMatrix(2, 1));
  BOOST_TEST(actualMatrix(2, 2) == expectedMatrix(2, 2));
}

BOOST_AUTO_TEST_SUITE_END()
