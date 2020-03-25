// Includes all relevant components of mlpack.
#include <mlpack/core.hpp>
// Convenience.
using namespace mlpack;
int main()
{
  // First, load the data.
  arma::mat data, d, a, b;
  arma::sp_mat sp_data, c;
  // Use data::Load() which transposes the matrix.
  data::Load("data.csv", data, true);
  
  sp_data = arma::sp_mat(data);

  // std::cout<<sp_data<<std::endl;
  // Now compute the covariance.  We assume that the data is already centered.
  // Remember, because the matrix is column-major, the covariance operation is
  // transposed.
  std::cout<<(data * sp_data)<<std::endl;
  std::cout<<(sp_data * data)<<std::endl;
  std::cout<<(sp_data * sp_data)<<std::endl;
  std::cout<<(data * data)<<std::endl;
  // for(int i = 0; i < 10; i++){
  //   sp_data = sp_data * trans(data); 
  //   std::cout<<sp_data<<std::endl;
  // }
  // // std::cout<<"Dense"<<std::endl;
  // std::cout<<cov_dense<<std::endl;
  
  // cov.save("sparse_covariance");
  // cov.save("sparse_covariance.txt", arma::raw_ascii);
  // cov.save("sparse_covariance.csv", arma::csv_ascii);

  
  // Save the output.
  // data::Save("cov.csv", cov, true);
}