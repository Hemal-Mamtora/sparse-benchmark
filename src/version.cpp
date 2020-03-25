#include <mlpack/core.hpp>
using namespace mlpack;
int main()
{
  arma::arma_version ver;
  std::cout << "ARMA version: "<< ver.as_string() << std::endl;

  return 0;
}