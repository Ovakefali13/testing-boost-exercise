#define BOOST_TEST_MODULE SideMadeTests
#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>
#include "MatrixSolver.hpp"
#include "MatrixIO.hpp"

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
    MatrixXd actualMatrix;
    actualMatrix = matrixIO::openData("../data/m3.csv", 3);

    BOOST_CHECK_EQUAL_COLLECTIONS(actualMatrix.begin(), actualMatrix.end(), expectedMatrix.begin(), expectedMatrix.end());
}

BOOST_AUTO_TEST_SUITE_END()